

ARCHITECTURE = {
    'controllers' : {
        'Module1' : {},
        'Zrticles' : {
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
        ('MyModel','Zrticles')

    ]



}



REPLACEMENT = {
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


