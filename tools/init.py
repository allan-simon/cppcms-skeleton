#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import config
import fileinput
import os
import shutil
from architecture import generate_architecture, generate_folders
from config import ARCHITECTURE, APP_ROOT, REPLACEMENTS
from constants import FOLDERS, LOCAL_TEMPLATE_ROOT, MAIN_APP_PLACEHOLDER

IGNORE_DIRS = [
    'tools',
    'build',
    '.git',
    '.svn'
]

IGNORE_EXTENSIONS = [
    '.swp'
]



def adapt_files(
    rootDir,
    replacements,
    ignoreDirs = [],
    ignoreExtensions = []
):
    print("root Dir is :" + rootDir)
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

def create_template_local_copy(localTemplateRoot):
    # we create a copy of the templates in order to
    # adapt them to the projet (and if the user need to custom
    # them a little for a given app
    shutil.copytree(
        "../template/",
        localTemplateRoot
    )


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

os.mkdir(APP_ROOT)

generate_folders(APP_ROOT,FOLDERS)

create_template_local_copy(LOCAL_TEMPLATE_ROOT)

adapt_files(
    LOCAL_TEMPLATE_ROOT,
    REPLACEMENTS,
    IGNORE_DIRS,
    IGNORE_EXTENSIONS
)

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
generate_architecture(ARCHITECTURE)

