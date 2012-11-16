#!/usr/bin/env python3
# -*- coding: utf-8 -*-

#as we use symbolic links we need to do this
#to be able to import config.py
import sys
sys.path.append(".")
from config import ARCHITECTURE



from addMethod import addMethod
from addModel import addModel
from addController import addController
from linkModelController import linkModelController
from addFormPage import addFormPage
from addActionOnlyPage import addActionOnlyPage

from os import mkdir

BAD_NAMES = [
    "delete",
    "new",
    "register",
    "class",
    "int"
]

# this function is meant to check that no
# invalid names are used in the architecture (like using
# language keywords etc.) that would result in a generated
# code that can't compile
def check_architecture_names(architecture):
    controllersOk = check_controllers(architecture['controllers'])
    modelsOk = check_models(architecture['models']);
    linksOk = check_links_models_controllers(architecture['models_controllers'])

    # true only if everything is ok
    return controllersOk and modelsOk and linksOk

def _check(dict,type):
    isAllOk = True
    for key, value in dict.items():
        if key.lower()  in BAD_NAMES:
            print(
                "You can't name your %s '%s', it's a C++ keyword"
                % (type, key)
            )
            isAllOk = False
    return isAllOk

# TODO add DOC
def check_controllers(controllers):
    isAllOk = True
    for controller,attributes in controllers.items():
        if controller.lower() in BAD_NAMES:
            print(
                "You can't name your controller '%s', it's a C++ keyword"
                % (controller)
            )
            isAllOk = False
        check_methods(attributes)
        check_forms(attributes)

    return isAllOk

# TODO add DOC
def check_methods(attributes):
    if 'methods' not in attributes.keys():
         return True
    isAllOk = _check(attributes['methods'],'method')

    return isAllOk

# TODO add DOC
def check_forms(attributes):
    isAllOk = True
    if 'forms' not in attributes.keys():
         return True

    isAllOk = _check(attributes['forms'],'form')

    return isAllOk

# TODO add DOC
def check_models(models):
    isAllOk = _check(models,"model")
    return isAllOk

# TODO add DOC
def check_links_models_controllers(links):
    return True


def generate_models(models):
    modelNames = []
    for model,attributes in models.items():
        modelNames.append(model)
        if  'description' in attributes.keys():
            description = attributes['description']
            addModel(
                model,
                description
            )
        else:
            addModel(model)

    return modelNames



def generate_controllers(controllers):
    
    controllerNames = []
    for controller,attributes in controllers.items():
        controllerNames.append(controller)
        if  'description' in attributes.keys():
            description = attributes['description']
            addController(controller,description)
        else:
            addController(controller)

        generate_methods(controller,attributes)
        generate_actions_only(controller,attributes)
        generate_form_pages(controller,attributes)

    return controllerNames



def generate_generic_methods(controller,attributes,key,function):
    if key not in attributes.keys():
         return

    for method, properties in attributes[key].items():
        if 'description' in properties.keys():
            description = properties['description']
            function(
                controller,
                method,
                description
            )
        else:
            function(
                controller,
                method
            )



def generate_methods (controller,attributes):
    generate_generic_methods(
        controller,
        attributes,
        "methods",
        addMethod
    )

def generate_actions_only (controller,attributes):
    generate_generic_methods(
        controller,
        attributes,
        "actions_only",
        addActionOnlyPage
    )



def generate_form_pages(controller,attributes):
    generate_generic_methods(
        controller,
        attributes,
        "forms",
        addFormPage
    )



def generate_links_models_controllers(modelsControllers,models,controllers):
   for model,controller in modelsControllers:
        bothExist = True
        if model not in models:
            bothExist = False
            print("the model %s is not defined",model)
        if controller not in controllers:
            bothExist = False
            print("the controller %s is not defined",controller)
        if bothExist:
            linkModelController(model,controller)



def generate_architecture (architecture):
    if (not check_architecture_names(architecture)):
        print(
            "Your architecture file is not correct please correct it" +
            " and then run ./architecture.py"
        )
        return

    controllerNames = generate_controllers(architecture['controllers'])
    modelNames = generate_models(architecture['models']);

    generate_links_models_controllers(
        architecture['models_controllers'],
        modelNames,
        controllerNames
    )

def generate_folders(root,tree):
    for folder,subfolders in tree.items():
        newFolder = root + "/" + folder
        mkdir(newFolder)
        if len(subfolders) != 0:
            generate_folders(newFolder,subfolders)
        else:
            # we create a new file in it
            # because git does not like empty direcotry
            open(newFolder + "/README",'w').close()

if __name__ == '__main__':
    generate_architecture(ARCHITECTURE)
