#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from argparse import ArgumentParser
import fileinput
import os

from datetime import date
from constants import *
from utils import *
from config import REPLACEMENT


def addModel(model,description):
    modelInclude = model.upper()

    replacePlaceholders = {
        '%%MODEL_NAME%%' : model,
        '%%MODEL_INCLUDE%%' : modelInclude,
        '%%MODEL_TODAY%%' : date.today().strftime('%d %B %Y'),
        '%%MODEL_DESCRIPTION%%' : description
    }

    # first edit the cpp file
    generateFromTemplate(
        os.path.join(MODEL_TMPL_DIR,MODEL_CPP_TPL),
        replacePlaceholders,
        os.path.join(MODEL_OUTPUT_DIR,model + '.cpp')
    )

    # then the .h file
    generateFromTemplate(
        os.path.join(MODEL_TMPL_DIR,MODEL_H_TPL),
        replacePlaceholders,
        os.path.join(MODEL_OUTPUT_DIR,model + '.h')
    )

if __name__ == '__main__':

    parser = ArgumentParser(
        description = "Add a new model"
    )

    parser.add_argument(
        'model',
        metavar = 'MODEL',
        help = 'name of model you want to add'
    )

    parser.add_argument(
        '-d',
        '--description',
        nargs='?',
        help = 'a description of what your model is supposed to do',
        default = '@TODO add a description'
    )


    args = parser.parse_args();


    description = args.description
    model = args.model

    addModel(model,description)
