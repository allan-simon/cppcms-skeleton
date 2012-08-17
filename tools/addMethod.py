#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from argparse import ArgumentParser
import fileinput
from datetime import date
from constants import *
from utils import *
import os
import re

parser = ArgumentParser(
    description = "Add a method to a controller"
)

parser.add_argument(
    'controller',
    metavar = 'CONTROLLER',
    help = 'name of the controller in which you want to add a method'
)

parser.add_argument(
    'method',
    metavar = 'METHOD',
    help = 'name of the method you want to add'
)



parser.add_argument(
    '-d',
    '--description',
    nargs='?',
    help = 'a description of what your method is supposed to do',
    default = '@TODO add a description'
)

args = parser.parse_args();



description = args.description
#TODO maybe do some check if the user enter a non valid
# controller name
controller = args.controller
method= args.method
controllerInclude = controller.upper()

controllerUnderscore = camelToUnderscore(controller)

replacePlaceholders = {
    '%%CONTROLLER_NAME%%' : controller,
    '%%ACTION_NAME%%' : method,
    #NOTE: it seems that - is more Google friendly than _
    '%%ACTION_URL%%' : '/%s' % (method.replace('_','-')),
    '%%ACTION_TODAY%%' : date.today().strftime('%d %B %Y'),
    '%%ACTION_DESCRIPTION%%' : description,
    '%%CONTENT_NAME%%' : underscoreToPascalCase(method),
    '%%CONTROLLER_NS%%' : controllerUnderscore,
    '%%VIEW_NAME%%' :  controllerUnderscore + "_" + method
}



# first edit the cpp file
insertFromTemplate(
    os.path.join(CTRL_OUTPUT_DIR,controller + '.cpp'),
    NEXT_ACTION_DISPATCHER_MARKER,
    os.path.join(CTRL_TEMPLATE_DIR,TMPL_METHOD_DISPATCH_CPP),
    replacePlaceholders,
)

insertFromTemplate(
    os.path.join(CTRL_OUTPUT_DIR,controller + '.cpp'),
    NEXT_ACTION_MARKER,
    os.path.join(CTRL_TEMPLATE_DIR,TMPL_METHOD_CPP),
    replacePlaceholders,
)


# then the .h file
insertFromTemplate(
    os.path.join(CTRL_OUTPUT_DIR,controller + '.h'),
    NEXT_ACTION_MARKER,
    os.path.join(CTRL_TEMPLATE_DIR,TMPL_METHOD_H),
    replacePlaceholders
)


# edit the content header to add the content for that action
insertFromTemplate(
    os.path.join(CONTENT_OUTPUT_DIR,controller + '.h'),
    NEXT_CONTENT_MARKER,
    os.path.join(CONTENT_TMPL_DIR,TMPL_CONTENT_INCLUDE_H),
    replacePlaceholders
)


