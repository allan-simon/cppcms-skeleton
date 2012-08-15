#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from argparse import ArgumentParser
import fileinput
import os

from datetime import date
from constants import *
from utils import *
from config import REPLACEMENT

parser = ArgumentParser(
    description = "Add a new controller"
)

parser.add_argument(
    'controller',
    metavar = 'CONTROLLER',
    help = 'name of controller you want to add'
)

parser.add_argument(
    '-d',
    '--description',
    nargs='?',
    help = 'a description of what your controller is supposed to do',
    default = '@TODO add a description'
)


args = parser.parse_args();


description = args.description
#TODO maybe do some check if the user enter a non valid
# controller name
controller = args.controller
controllerInclude = controller.upper()

controllerUrl = camelToUnderscore(controller).replace('_','-')

replacePlaceholders = {
    '%%CONTROLLER_VAR%%' : pascalCaseToCamel(controller),
    '%%CONTROLLER_NAME%%' : controller,
    '%%CONTROLLER_URL%%' : controllerUrl,
    '%%CONTROLLER_INCLUDE%%' : controllerInclude,
    '%%CONTROLLER_TODAY%%' : date.today().strftime('%d %B %Y'),
    '%%CONTROLLER_DESCRIPTION%%' : description
}


# first edit the cpp file
generateFromTemplate(
    os.path.join(CTRL_TEMPLATE_DIR,TMPL_CTRL_CPP),
    replacePlaceholders,
    os.path.join(CTRL_OUTPUT_DIR,controller + '.cpp')
)

# then the .h file
generateFromTemplate(
    os.path.join(CTRL_TEMPLATE_DIR,TMPL_CTRL_H),
    replacePlaceholders,
    os.path.join(CTRL_OUTPUT_DIR,controller + '.h')
)

mainFileCpp = REPLACEMENT['@MAIN_CLASS@'] + '.cpp'
mainFileH = REPLACEMENT['@MAIN_CLASS@'] + '.h'
mainFileCppPath = os.path.join(
    MAIN_APP_DIR,
    mainFileCpp
)
mainFileHPath = os.path.join(
    MAIN_APP_DIR,
    mainFileH
)


insertFromTemplate(
    mainFileHPath,
    NEXT_CONTROLLER_INCLUDE_MARKER,
    os.path.join(MAIN_APP_TEMPLATE_DIR,TMPL_MAIN_APP_INCLUDE_H),
    replacePlaceholders
)

insertFromTemplate(
    mainFileHPath,
    NEXT_MAIN_APP_CTRL_ATTR,
    os.path.join(MAIN_APP_TEMPLATE_DIR,TMPL_MAIN_APP_ATTR_H),
    replacePlaceholders
)



insertFromTemplate(
    mainFileCppPath,
    NEXT_MAIN_APP_CTRL_CONSTRUCT_MARKER,
    os.path.join(MAIN_APP_TEMPLATE_DIR,TMPL_MAIN_APP_CONSTRUCT_CPP),
    replacePlaceholders
)


insertFromTemplate(
    mainFileCppPath,
    NEXT_CONTROLLER_DISPATCHER_MARKER,
    os.path.join(MAIN_APP_TEMPLATE_DIR,TMPL_MAIN_APP_DISPATCHER_CPP),
    replacePlaceholders
)


