#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
#as we use symbolic links we need to do this
#to be able to import config.py
import sys
sys.path.append(".")

if (not os.path.isfile("config.py")):
    sys.exit("you should first create a config.py file")


import config
import fileinput
import shutil

from argparse import ArgumentParser
from architecture import generate_architecture, generate_folders
from config import ARCHITECTURE, APP_ROOT, REPLACEMENTS
from constants import FOLDERS, LOCAL_TEMPLATE_ROOT, MAIN_APP_PLACEHOLDER

CPPCMS_SKEL_DEFAULT_INSTALL_DIR = '/usr/local/share/cppcmsskel/'

IGNORE_DIRS = [
    'tools',
    'build',
    '.git',
    '.svn'
]

IGNORE_EXTENSIONS = [
    '.swp'
]



# This function will take the generic "template" files and will adapt them
# to the current projet (i.e putting the user copyright header etc.)
def adapt_files(
    rootDir,
    replacements,
    ignoreDirs = [],
    ignoreExtensions = []
):
    # we do a recursive walk 
    for path, dirs, files in os.walk(rootDir):
        # we ignore some directories
        for ignoreDir in ignoreDirs:
            if ignoreDir in  dirs:
                dirs.remove(ignoreDir)
        if files:
            for file in files:
                #if the file is not a source file, we do not try to modify it
                if file[-4:] in ignoreExtensions:
                    continue
                fullPathFile  = os.path.join(path,file)
                print(fullPathFile)
                # in all the files we search and replace for the placeholders
                for line in fileinput.FileInput(fullPathFile,inplace=1):
                    for find,replace in replacements.items():
                        line  = line.replace(find,replace)
                    #note FileInput redirect STDIN to the file that's why
                    # we use print and nothing is displayed
                    print(line, end='')


def create_template_local_copy(
    originTemplateRoot,
    localTemplateRoot,
):
    # we create a copy of the templates in order to
    # adapt them to the projet (and if the user need to custom
    # them a little for a given app
    shutil.copytree(
        originTemplateRoot,
        localTemplateRoot
    )


# generic function to move a file
def move_file(
    localTemplateRoot,
    appRoot,
    fileName
):
    src = localTemplateRoot + "/" + fileName
    dst =appRoot + "/" + fileName
    print(src)
    print(dst)

    os.rename(src, dst)


# to move the CMake configuration file
# that will compile the website
def move_cmake_file(
    localTemplateRoot,
    appRoot
):
    fileName = 'CMakeLists.txt'
    move_file(
        localTemplateRoot,
        appRoot,
        fileName
    )

# move the main.cpp file from the template's files
# to the application folder
def move_main(
    localTemplateRoot,
    appRoot
):
    fileName = 'main.cpp'
    move_file(
        localTemplateRoot,
        appRoot + "/src",
        fileName
    )

# move homepage.tmpl, the file that contain the html of
# the main page when you go on domain.tld/
def move_homeplage(
    localTemplateRoot,
    appRoot
):
    fileName = '/views/webs/pages/homepage.tmpl'
    move_file(
        localTemplateRoot,
        appRoot + "/src",
        fileName
    )


# The application class file has by default a generic name
# rename it with the actual application name
def rename_app_files(
    localTemplateRoot,
    placeholderName,
    appName
):
    os.rename(
        localTemplateRoot + "/" + placeholderName + ".cpp",
        localTemplateRoot + "/" + appName + ".cpp",
    )

    os.rename(
        localTemplateRoot + "/" + placeholderName + ".h",
        localTemplateRoot + "/" + appName + ".h",
    )


# move the application class file from the template directoy
# to the actual application folder
def move_app_files(
    localTemplateRoot,
    appRoot,
    appName
):
    fileName = appName + '.cpp'
    move_file(
        localTemplateRoot,
        appRoot + '/src',
        fileName
    )

    fileName = appName + '.h'
    move_file(
        localTemplateRoot,
        appRoot + '/src',
        fileName
    )

# By default the main application contain a sub-application
# named "Pages" that is used to display "nearly static" web pages
# i.e homepage/credit pages etc.

def move_pages_files(
    localTemplateRoot,
    appRoot
):
    appName = "Pages"
    subdir = '/controllers/webs'
    fileName = appName + '.cpp'
    move_file(
        localTemplateRoot + subdir,
        appRoot + '/src' + subdir,
        fileName
    )

    fileName = appName + '.h'
    move_file(
        localTemplateRoot + subdir,
        appRoot + '/src' + subdir,
        fileName
    )

    subdir = '/contents'
    fileName = appName + '.h'
    move_file(
        localTemplateRoot + subdir,
        appRoot + '/src' + subdir,
        fileName
    )


# move the configuration file of the website
# from the template directory to the application's one
def move_config_js(
    localTemplateRoot,
    appRoot
):
    fileName = 'config.js'
    move_file(
        localTemplateRoot,
        appRoot,
        fileName
    )


def move_master_layout(
    localTemplateRoot,
    appRoot
):
    fileName = 'views/webs/layouts/master.tmpl'
    move_file(
        localTemplateRoot,
        appRoot + "/src",
        fileName
    )



def move_and_renamed_files(
    localTemplateRoot,
    appRoot,
    replacements,
    mainAppPlaceholder, 
):

    #move Cmake 
    move_cmake_file(localTemplateRoot, appRoot)

    # move config.js 
    move_config_js(localTemplateRoot, appRoot)

    # move main.cpp file
    move_main(localTemplateRoot, appRoot)

    # move homepage.tmpl
    move_homeplage(localTemplateRoot, appRoot)

    # rename @mainAppPlaceholder@.h/cpp@ into mainApp.h/cpp
    mainApp = replacements[mainAppPlaceholder]

    rename_app_files(
        localTemplateRoot,
        mainAppPlaceholder,
        mainApp
    )
    # move the mainApp.cpp/h files
    move_app_files(
        localTemplateRoot,
        appRoot,
        mainApp
    )
    move_pages_files(localTemplateRoot, appRoot)
    move_master_layout(localTemplateRoot, appRoot)


if __name__ == '__main__':
    parser = ArgumentParser(
        description = 'Initialize the directories and generate the code using your config.py file'
    )

    parser.add_argument(
        '-i',
        '--install-dir',
        nargs='?',
        help = 'Path where you have installed cppcmsskel',
        default = CPPCMS_SKEL_DEFAULT_INSTALL_DIR
    )
    args = parser.parse_args();
    cppcmsskelInstallDir = args.install_dir




    # we create the application directory
    os.mkdir(APP_ROOT)
    
    # we create the directory structure in it
    generate_folders(APP_ROOT,FOLDERS)
    
    # we generate a local copy of the template files ...
    create_template_local_copy(
        CPPCMS_SKEL_DEFAULT_INSTALL_DIR + 'template',
        LOCAL_TEMPLATE_ROOT
    )
    
    # and we adapt them to fit the current application
    adapt_files(
        LOCAL_TEMPLATE_ROOT,
        REPLACEMENTS,
        IGNORE_DIRS,
        IGNORE_EXTENSIONS
    )
    
    # we move the needing files from the local template
    # directory to the application's one
    move_and_renamed_files(
        LOCAL_TEMPLATE_ROOT,
        APP_ROOT,
        REPLACEMENTS,
        MAIN_APP_PLACEHOLDER
    )
    print(
        '''
        ################################
        NOW WE GENERATE THE ARCHITECTURE
        ################################
        '''
    )
    # finally generate the code following the
    # architecture defined by the user in the config.py file
    generate_architecture(ARCHITECTURE)
