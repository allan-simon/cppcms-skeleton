from addMethod import addMethod
from addModel import addModel
from addController import addController
from linkModelController import linkModelController


from config import ARCHITECTURE

def generate_architecture ():
    for controller,attributes in ARCHITECTURE['controllers'].items():
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

    for model,attributes in ARCHITECTURE['models'].items():
        if  'description' in attributes.keys():
            description = attributes['description']
            addModel(
                model,
                description
            )
        else:
            addModel(model)


    for model,controller in ARCHITECTURE['models_controllers']:
        linkModelController(model,controller)



