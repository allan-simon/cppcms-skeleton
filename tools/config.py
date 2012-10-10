

# where the application code will be generated
# relative to the "tools" directory
APP_ROOT = "../../app"

# this represent the logical structure of your code
# the script init will use this to generate a skeleton
# of code
ARCHITECTURE = {
    'controllers' : {
        'Module1' : {},
        'Articles' : {
            'description': 'a module that does something',
            'methods' : {
                'add_something' : {},
                'do_something_else' : {}
            }    
        }
    },

    'models': {
        'MyModel' : {}
    },

    'models_controllers': [
        ('MyModel','Module1'),
        ('MyModel','Articles')

    ]



}


# placeholders, replace the value by those specific to your
# projet
REPLACEMENTS = {
    '@FRAMEWORK_ROOT@' : '../framework', #TODO a bit hackish yet
    '@AUTHOR@' : 'your name',
    '@EMAIL@': 'Your_email.com',
    '@PROJECT_NAME_CODE@' : 'YourProjectName',
    '@PROJECT_NAME_HUMAN@': 'your project name',
    '@MAIN_CLASS@' : 'Name of your application class',
    '@MAIN_CLASS_HEADER@' : 'NAME_OF_MAIN_CLASS',
    '@DESCRIPTION@' : 'Description of your project',
    '@PROJECT_WEBSITE' : 'link to your project',
    '@YEARS@' : 'copyright years',
    '    ' : 'your prefered indentation '
}

