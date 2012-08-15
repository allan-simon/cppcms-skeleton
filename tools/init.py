#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import config
import fileinput
import os

IGNORE_DIRS = [
    'tools',
    'build',
    '.git',
    '.svn'
]


rootdir = '..'

# we do a recursive walk 
for path, dirs, files in os.walk(rootdir):
    # we ignore some directories
    for ignoreDir in IGNORE_DIRS:
        if ignoreDir in  dirs:
            dirs.remove(ignoreDir)
    if files:
        for file in files:
            fullPathFile  = os.path.join(path,file)
            print(fullPathFile)
            # in all the files we search and replace for the placeholders
            for line in fileinput.FileInput(fullPathFile,inplace=1):
                for find,replace in config.REPLACEMENT.items():
                    line  = line.replace(find,replace)
                #note FileInput redirect STDIN to the file that's why
                # we use print and nothing is displayed
                print(line, end='')



#rename files
srcDir = os.path.join(
    os.pardir,
    'src'
)
originalFile = os.path.join (
    srcDir,
    '@PROJECT_NAME_CODE@'
)

renamedFile = os.path.join(
    srcDir,
    config.REPLACEMENT['@PROJECT_NAME_CODE@']
)

os.rename(
    originalFile + '.h',
    renamedFile + '.h'
)

os.rename(
    originalFile + '.cpp',
    renamedFile + '.cpp'
)




