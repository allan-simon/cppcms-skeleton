#!/usr/bin/env python3
# -*- coding: utf-8 -*-

#as we use symbolic links we need to do this
#to be able to import config.py
import sys
sys.path.append(".")

from argparse import ArgumentParser
import os

from datetime import date
from constants import *
from utils import *

def addForm(controller, form, description = '@TODO'):
    formInclude = form.upper()
    formUnderscore = camelToUnderscore(form)
    controllerUnderscore = camelToUnderscore(controller)

    replacePlaceholders = {
        '%%CONTROLLER_NS%%' : controllerUnderscore,
        '%%FORM_NAME%%' : form,
        #TODO the user should be able to override this
        '%%FORM_SUBMIT_UI%%' : 'submit',
        '%%FORM_INCLUDE%%' : formInclude,
        '%%FORM_TODAY%%' : date.today().strftime('%d %B %Y'),
        '%%FORM_STRUCT%%' : underscoreToPascalCase(form),
        '%%FORM_DESCRIPTION%%' : description
    }


    # create the struct file

    generateFromTemplate(
        os.path.join(FORM_TMPL_DIR,FORM_H_TPL),
        replacePlaceholders,
        os.path.join(FORM_OUTPUT_DIR,form + '.h')
    )


if __name__ == '__main__' :

    parser = ArgumentParser(
        description = "Add a new form"
    )


    parser.add_argument(
        'controller',
        metavar = 'CONTROLLER',
        help = 'name of the controller in which you want to add a form'
    )



    parser.add_argument(
        'form',
        metavar = 'FORM',
        help = 'name of form you want to add'
    )

    parser.add_argument(
        '-d',
        '--description',
        nargs='?',
        help = 'a description of what your form is supposed to do',
        default = '@TODO add a description'
    )


    args = parser.parse_args();


    description = args.description
#TODO maybe do some check if the user enter a non valid
# form name
    controller = args.controller
    form = args.form
    addForm(controller,form,description)

