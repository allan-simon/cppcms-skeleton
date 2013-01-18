# where the application code will be generated
# relative to the "tools" directory
APP_ROOT = "../app"

# this represent the logical structure of your code
# the script init will use this to generate a skeleton
# of code
ARCHITECTURE = {
    'controllers' : {
        ###########
        'Users' : {
            'description': 'Module that manages user',
            'methods' : {
                'logout' : {}
            },
            'forms' : {
                'register_new' : {},
                'login' : {}
            }
        },
        ##########
        'Articles' : {
            'description': 'Module dealing with wiki pages that can be edited/added',
            'methods' : {
               'show' : {}, 
               'remove' : {}
            },
            'forms' : {
                'edit' : {},
                'create' : {}
            }
        },
        ##########
        'History' : {
            'methods' : {
                'show_version': {},
                'revert_to_version': {},
            },
            'forms' : {
                'diff_between' : {}
            }
        },
    },

    'models': {
        'Articles' : {},
        'History' : {},
        'Users' : {},
    },

    'models_controllers': [
        ('Articles','Articles'),
        ('History','History'),
        ('Users','Users')
    ]


}


REPLACEMENTS = { 
    '@AUTHOR@' : 'Allan SIMON',
    '@EMAIL@': 'allan.simon@supinfo.com',
    '@PROJECT_NAME_CODE@' : 'TatoWiki',
    '@PROJECT_NAME_HUMAN@': 'Tatoeba wiki',
    '@MAIN_CLASS_HEADER@' : 'TATOWIKI',
    '@MAIN_CLASS@' : 'TatoWiki',
    '@DESCRIPTION@' : 'Wiki made with cppcmsskel',
    '@PROJECT_WEBSITE' : 'https://github.com/sysko/tatowiki',
    '@YEARS@' : '2012',
    '    ' : '    '
}


