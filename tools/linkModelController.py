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

def linkModelController(model,controller):

    replacePlaceholders = {
        '%%MODEL_VAR%%' : pascalCaseToCamel(model) + 'Model' ,
        '%%MODEL_CTRL_TODAT%%' : date.today().strftime('%d %B %Y'),
        '%%MODEL_NAME%%' : model
    }

    insertFromTemplate(
        os.path.join(MODEL_CTRL_OUTPUT_DIR,controller + '.cpp'),
        NEXT_INC_MODEL_CTRL_MARKER,
        os.path.join(MODEL_CTRL_TMPL_DIR,INC_MODEL_CTRL_TPL),
        replacePlaceholders,
    )


    insertFromTemplate(
        os.path.join(MODEL_CTRL_OUTPUT_DIR,controller + '.cpp'),
        NEXT_NEW_MODEL_CTRL_MARKER,
        os.path.join(MODEL_CTRL_TMPL_DIR,NEW_MODEL_CTRL_TPL),
        replacePlaceholders,
    )


    insertFromTemplate(
        os.path.join(MODEL_CTRL_OUTPUT_DIR,controller + '.cpp'),
        NEXT_DEL_MODEL_CTRL_MARKER,
        os.path.join(MODEL_CTRL_TMPL_DIR,DEL_MODEL_CTRL_TPL),
        replacePlaceholders,
    )


    insertFromTemplate(
        os.path.join(MODEL_CTRL_OUTPUT_DIR,controller + '.h'),
        NEXT_VAR_MODEL_CTRL_MARKER,
        os.path.join(MODEL_CTRL_TMPL_DIR,VAR_MODEL_CTRL_TPL),
        replacePlaceholders,
    )

    insertFromTemplate(
        os.path.join(MODEL_CTRL_OUTPUT_DIR,controller + '.h'),
        NEXT_CLASS_MODEL_CTRL_MARKER,
        os.path.join(MODEL_CTRL_TMPL_DIR,CLASS_MODEL_CTRL_TPL),
        replacePlaceholders,
    )


if __name__ == '__main__':

    parser = ArgumentParser(
        description = "link a model to a controller"
    )

    parser.add_argument(
        'model',
        metavar = 'MODEL',
        help = 'name of the model you want to add'
    )

    parser.add_argument(
        'controller',
        metavar = 'CONTROLLER',
        help = 'name of the controller in which you want to add a model'
    )

    args = parser.parse_args();


    controller = args.controller
    model= args.model


    linkModelController(model,controller)
