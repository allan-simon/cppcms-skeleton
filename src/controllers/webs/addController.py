#!/usr/bin/env python
# -*- coding: utf-8 -*-

from argparse import ArgumentParser
import fileinput
from datetime import date
import os

# directory were the template files are stored
TEMPLATE_DIR = "template"
#name of the template that contains the main template of the
# .cpp file of a controller
TMPL_CTRL_CPP = '_template_.cpp.tpl'
#name of the template that contains the main template of the
# .h file of a controller
TMPL_CTRL_H = '_template_.h.tpl'
#name of the template that contains the code for a new
#controller method
TMPL_METHOD_CPP = '_template_method.tpl'
#name of the template that contains the code for a new
#controller method header
TMPL_METHOD_H = '_template_method_header.tpl'



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

replacePlaceholders = {
    '%%CONTROLLER_NAME%%' : controller,
    '%%CONTROLLER_INCLUDE%%' : controllerInclude,
    '%%CONTROLLER_TODAY%%' : date.today().strftime('%d %B %Y'),
    '%%CONTROLLER_DESCRIPTION%%' : description
}

def generateFromTemplate(templateFile, placeHolders, outfileName):
    outfile = open(
        outfileName,
        'w'
    )


    pathTemplateCpp = os.path.join(
        TEMPLATE_DIR,
        templateFile
    )
    for line in fileinput.FileInput(pathTemplateCpp):
        for find,replace in placeHolders.items():
            line = line.replace(find,replace)
        outfile.write(line)

    outfile.close()



# first edit the cpp file
generateFromTemplate(
    TMPL_CTRL_CPP,
    replacePlaceholders,
    controller + '.cpp'
)

# then the .h file
generateFromTemplate(
    TMPL_CTRL_H,
    replacePlaceholders,
    controller + '.h'
)


