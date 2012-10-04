from addMethod import addMethod
from addModel import addModel
from addController import addController
from linkModelController import linkModelController



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

    controllerNames = generate_controllers(architecture['controllers'])
    modelNames = generate_models(architecture['models']);

    generate_links_models_controllers(
        architecture['models_controllers'],
        modelNames,
        controllerNames
    )



