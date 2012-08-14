#!/usr/bin/env python
# -*- coding: utf-8 -*-

from argparse import ArgumentParser
import fileinput
from datetime import date
import os
import re

def camelToUnderscore(
    name
) :
    s1 = re.sub('(.)([A-Z][a-z]+)', r'\1_\2', name)
    return re.sub('([a-z0-9])([A-Z])', r'\1_\2', s1).lower()

def underscoreToPascalCase(value):
    return "".join( x.capitalize() for x in value.split("_") )



#  were the template files are stored
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

#template that contains the code to attach the action
#to the controller
TMPL_METHOD_DISPATCH_CPP = '_template_method_dispatcher_.tpl'
#name of the template that contains the code for a new

#marker to tell where to put the next method's code in the
#controller file
NEXT_ACTION_MARKER = "%%%NEXT_ACTION_MARKER%%%"
NEXT_ACTION_DISPATCHER_MARKER = "%%%NEXT_ACTION_DISPATCHER_MARKER%%%"

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



# will take a template, replace the placeholders and insert
# the resulting file inside an other at the given marker
def insertFromTemplate(
    controllerFileName,
    insertMarker,
    insertTemplateName,
    placeHolders
) :


    insertFullPath = os.path.join(
        TEMPLATE_DIR,
        insertTemplateName
    )

    output = ""
    for line in fileinput.FileInput(insertFullPath):
        for find,replace in placeHolders.items():
            line = line.replace(find,replace)
        output += line




    for line in fileinput.FileInput(controllerFileName, inplace=1):
        if  insertMarker in line:
            line = output
        print(line, end='')

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
    controller + '.cpp',
    NEXT_ACTION_DISPATCHER_MARKER,
    TMPL_METHOD_DISPATCH_CPP,
    replacePlaceholders,
)

insertFromTemplate(
    controller + '.cpp',
    NEXT_ACTION_MARKER,
    TMPL_METHOD_CPP,
    replacePlaceholders,
)


# then the .h file
insertFromTemplate(
    controller + '.h',
    NEXT_ACTION_MARKER,
    TMPL_METHOD_H,
    replacePlaceholders
)


