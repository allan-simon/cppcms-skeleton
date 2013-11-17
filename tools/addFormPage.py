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
from addForm import addForm
import os

def addFormPage(controller, form, description = '@TODO'):
    addForm(controller,form)

    controllerUnderscore = camelToUnderscore(controller)
    controllerUrl = camelToUnderscore(controller).replace('_','-')
    viewName =controllerUnderscore + "_" + form

    replacePlaceholders = {
        '%%CONTROLLER_NAME%%' : controller,
        '%%FORM_NAME%%' : form,
        '%%FORM_INCLUDE%%' : form,
        '%%FORM_TREAT_NAME%%' : form + '_treat',
        #NOTE: it seems that - is more Google friendly than _
        '%%FORM_URL%%' : '%s' % (form.replace('_','-')),
        '%%FORM_TREAT_URL%%' : '%s_treat' % (form.replace('_','-')),
        '%%FORM_TODAY%%' : date.today().strftime('%d %B %Y'),
        '%%FORM_DESCRIPTION%%' : description,
        '%%CONTENT_NAME%%' : underscoreToPascalCase(form),
        '%%FORM_STRUCT%%' : underscoreToPascalCase(form),
        '%%CONTROLLER_NS%%' : controllerUnderscore,
        '%%CONTROLLER_URL%%' : controllerUnderscore,
        '%%FORM_VAR%%' : underscoreToCamel(form) + 'Form',
        '%%VIEW_NAME%%' : viewName
    }



# first edit the cpp file
    insertFromTemplate(
        os.path.join(CTRL_OUTPUT_DIR,controller + '.cpp'),
        NEXT_ACTION_DISPATCHER_MARKER,
        os.path.join(CTRL_TEMPLATE_DIR,TMPL_METHOD_FORM_DISPATCH_CPP),
        replacePlaceholders,
    )

    insertFromTemplate(
        os.path.join(CTRL_OUTPUT_DIR,controller + '.cpp'),
        NEXT_ACTION_MARKER,
        os.path.join(CTRL_TEMPLATE_DIR,TMPL_METHOD_FORM_CPP),
        replacePlaceholders,
    )


# then the .h file
    insertFromTemplate(
        os.path.join(CTRL_OUTPUT_DIR,controller + '.h'),
        NEXT_ACTION_MARKER,
        os.path.join(CTRL_TEMPLATE_DIR,TMPL_METHOD_FORM_H),
        replacePlaceholders
    )

    # edit the content header to add the include to the form
    insertFromTemplate(
        os.path.join(CONTENT_OUTPUT_DIR,controller + '.h'),
        NEXT_CONTENT_FORM_INCLUDE_MARKER,
        os.path.join(CONTENT_TMPL_DIR,TMPL_CONTENT_FORM_INCLUDE_H),
        replacePlaceholders
    )

    # edit the content header to add the content for that action
    insertFromTemplate(
        os.path.join(CONTENT_OUTPUT_DIR,controller + '.h'),
        NEXT_CONTENT_MARKER,
        os.path.join(CONTENT_TMPL_DIR,TMPL_CONTENT_FORM_H),

        replacePlaceholders
    )


# create the view for that action
    generateTemplateForAllSkins(
        controllerUnderscore,
        form,
        replacePlaceholders
    )


if __name__ == '__main__':
    parser = ArgumentParser(
        description = "Add everything to fill and treat a form to a controller"
    )

    parser.add_argument(
        'controller',
        metavar = 'CONTROLLER',
        help = 'name of the controller in which you want to add a form treatment'
    )

    parser.add_argument(
        'form',
        metavar = 'FORM',
        help = 'name of the form you want to fill and treat'
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
    form= args.form


    addFormPage(controller, form, description)

