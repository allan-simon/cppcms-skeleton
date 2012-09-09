from addMethod import addMethod
from addModel import addModel
from addController import addController
from linkModelController import linkModelController


from config import ARCHITECTURE

def generate_architecture ():

    controllers = []

    for controller,attributes in ARCHITECTURE['controllers'].items():
        controllers.append(controller)
        if  'description' in attributes.keys():
            description = attributes['description']
            addController(controller,description)
        else:
            addController(controller)

        if 'methods' not in attributes.keys():
             continue

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

    models = []
    for model,attributes in ARCHITECTURE['models'].items():
        models.append(model)
        if  'description' in attributes.keys():
            description = attributes['description']
            addModel(
                model,
                description
            )
        else:
            addModel(model)


    for model,controller in ARCHITECTURE['models_controllers']:
        
        bothExist = true
        if model not in models:
            bothExist = false
            print("the model %s is not defined",model)
        if controller not in controllers:
            bothExist = false
            print("the controller %s is not defined",controller)
        if bothExist:
            linkModelController(model,controller)



