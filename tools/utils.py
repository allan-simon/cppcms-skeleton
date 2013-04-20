###
import re
import fileinput
import os
from constants import *

def camelToUnderscore(
    name
) :
    s1 = re.sub('(.)([A-Z][a-z]+)', r'\1_\2', name)
    return re.sub('([a-z0-9])([A-Z])', r'\1_\2', s1).lower()

###

def underscoreToPascalCase(value):
    return "".join( x.capitalize() for x in value.split("_") )

def underscoreToCamel(value):
    #TODO replace by something more direct
    return  pascalCaseToCamel(underscoreToPascalCase(value))

def pascalCaseToCamel(value):
    return value[0].lower() + value[1:]


###
# will take a template, replace the placeholders and insert
# the resulting file inside an other at the given marker
def insertFromTemplate(
    controllerFileName,
    insertMarker,
    insertTemplateName,
    placeHolders
) :


    output = ""
    for line in fileinput.FileInput(insertTemplateName):
        for find,replace in placeHolders.items():
            line = line.replace(find,replace)
        output += line




    for line in fileinput.FileInput(controllerFileName, inplace=1):
        if  insertMarker in line:
            line = output
        print(line, end='')

######

def generateFromTemplate(
    templateFile,
    placeHolders,
    outfileName
):

    outfile = open(
        outfileName,
        'w'
    )

    for line in fileinput.FileInput(templateFile):
        for find,replace in placeHolders.items():
            line = line.replace(find,replace)
        outfile.write(line)

    outfile.close()


def generateTemplateForAllSkins(
    controllerUnderscore,
    method,
    replacePlaceholders
):
    for skinDir in os.listdir(VIEW_CTRL_OUTPUT_DIR):
        generateFromTemplate(
            os.path.join(VIEW_CTRL_TMPL_DIR,TMPL_VIEW_ACTION_TPL),
            replacePlaceholders,
            os.path.join(VIEW_CTRL_OUTPUT_DIR, skinDir,controllerUnderscore,method + '.tmpl')
        )


