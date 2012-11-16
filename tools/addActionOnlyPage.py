#!/usr/bin/env python3
# -*- coding: utf-8 -*-

#as we use symbolic links we need to do this
#to be able to import config.py
import sys
sys.path.append(".")

from argparse import ArgumentParser
from datetime import date
from constants import *
from utils import *
import os

def addActionOnlyPage(controller, action, description = '@TODO'):
    controllerInclude = controller.upper()

    controllerUnderscore = camelToUnderscore(controller)

    replacePlaceholders = {
        '%%CONTROLLER_NAME%%' : controller,
        '%%ACTION_NAME%%' : action,
        #NOTE: it seems that - is more Google friendly than _
        '%%ACTION_URL%%' : '%s' % (action.replace('_','-')),
        '%%ACTION_TODAY%%' : date.today().strftime('%d %B %Y'),
        '%%ACTION_DESCRIPTION%%' : description,
        '%%CONTROLLER_NS%%' : controllerUnderscore,
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
        os.path.join(CTRL_TEMPLATE_DIR,TMPL_ACTION_ONLY_CPP),
        replacePlaceholders,
    )


# then the .h file
    insertFromTemplate(
        os.path.join(CTRL_OUTPUT_DIR,controller + '.h'),
        NEXT_ACTION_MARKER,
        os.path.join(CTRL_TEMPLATE_DIR,TMPL_METHOD_H),
        replacePlaceholders
    )



if __name__ == '__main__':
    parser = ArgumentParser(
        description = "Add an action to a controller, this page will display nothing, only do something internally and redirect"
    )

    parser.add_argument(
        'controller',
        metavar = 'CONTROLLER',
        help = 'name of the controller in which you want to add this action'
    )

    parser.add_argument(
        'action',
        metavar = 'ACTION',
        help = 'name of the action you want to add'
    )



    parser.add_argument(
        '-d',
        '--description',
        nargs='?',
        help = 'a description of what your action is supposed to do',
        default = '@TODO add a description'
    )

    args = parser.parse_args();



    description = args.description
#TODO maybe do some check if the user enter a non valid
# controller name
    controller = args.controller
    action= args.action


    addActionOnlyPage(controller, action, description)
