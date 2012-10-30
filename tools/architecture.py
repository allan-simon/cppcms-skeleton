from addMethod import addMethod
from addModel import addModel
from addController import addController
from linkModelController import linkModelController
from addFormPage import addFormPage

from os import mkdir


# this function is meant to check that no
# invalid names are used in the architecture (like using
# language keywords etc.) that would result in a generated
# code that can't compile
def check_names(architecture):
    pass



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
        generate_form_pages(controller,attributes)

    return controllerNames



def generate_methods (controller,attributes):

    if 'methods' not in attributes.keys():
         return

    for method, properties in attributes['methods'].items():
        if 'description' in properties.keys():
            description = properties['description']
            addMethod(
                controller,
                method,
                description
            )
        else:
            addMethod(
                controller,
                method
            )

def generate_form_pages(controller,attributes):
    if 'forms' not in attributes.keys():
         return

    for method, properties in attributes['forms'].items():
        if 'description' in properties.keys():
            description = properties['description']
            addFormPage(
                controller,
                method,
                description
            )
        else:
            addFormPage(
                controller,
                method
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
    if (not check_names(architecture)):
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




