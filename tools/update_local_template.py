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

from move_and_rename import IGNORE_DIRS
from move_and_rename import IGNORE_EXTENSIONS
from move_and_rename import adapt_files
from move_and_rename import move_and_renamed_files
from move_and_rename import create_template_local_copy



from argparse import ArgumentParser
from architecture import generate_architecture, generate_folders
from config import ARCHITECTURE, APP_ROOT, REPLACEMENTS
from constants import FOLDERS, LOCAL_TEMPLATE_ROOT, MAIN_APP_PLACEHOLDER

CPPCMS_SKEL_DEFAULT_INSTALL_DIR = '/usr/local/share/cppcmsskel/'

if __name__ == '__main__':
    parser = ArgumentParser(
        description = 'update your local copy of code template using your config.py file'
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

    if (os.path.isdir(LOCAL_TEMPLATE_ROOT)):
        shutil.rmtree(LOCAL_TEMPLATE_ROOT)

    # we generate a local copy of the template files ...
    create_template_local_copy(
        cppcmsskelInstallDir + 'template',
        LOCAL_TEMPLATE_ROOT
    )

    # and we adapt them to fit the current application
    adapt_files(
        LOCAL_TEMPLATE_ROOT,
        REPLACEMENTS,
        IGNORE_DIRS,
        IGNORE_EXTENSIONS
    )
