
# where the application code will be generated
# relative to the "tools" directory
APP_ROOT = "../app"



ARCHITECTURE = {
    'controllers' : {
        'Module1' : {},
        'Articles' : {
            'description': 'a module that does something',
            'methods' : {
                'show' : {},
                'do_something_else' : {}
            },
            'forms' : {
                'add_comment' : {}
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



REPLACEMENTS = {
    '@AUTHOR@' : 'Allan',
    '@EMAIL@': 'Your_email.com',
    '@PROJECT_NAME_CODE@' : 'TatoWiki',
    '@PROJECT_NAME_HUMAN@': 'Tato wiki',
    '@MAIN_CLASS@' : 'TatoWiki',
    '@MAIN_CLASS_HEADER@' : 'TATOWIKI',
    '@DESCRIPTION@' : 'Description of your project',
    '@PROJECT_WEBSITE' : 'link to your project',
    '@YEARS@' : 'copyright years'
}


