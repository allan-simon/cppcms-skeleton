from config import APP_ROOT

LOCAL_TEMPLATE_ROOT = "../local_template"

# how the generic .cpp/.h files of a main application
# are named
MAIN_APP_PLACEHOLDER = "@PROJECT_NAME_CODE@"

FOLDERS = {
    #to store the i18n messages
    "locale" : {}, 

    #store the source code itself
    "src" : {
        #store the structures used to transmit data from the
        # view to the controller
        "contents": { 

            # contains the structure used to represent a form,
            # the data contained in it, and the functions to
            # validate it
            "forms" : {}
        },

        #point of entry of the sub-functionnality of the app
        "controllers": {

            # contains the generic code that will be shared
            # between the api/web version of the same module
            "generics" : {},

            # contains the classes that will deal specifically
            # on which contents to fill with which models to
            # generate a page for a website
            "webs" : {},

            # same as for webs except that it will be to generate
            # an api response
            "apis" :{}

        },

        # contains utility classes
        "generics" : {},

        # contains classes used to manipulate/store/retrieve data
        "models" : {},

        #contains classes used to store information for
        #communication between models and controllers
        "results" : {},

        #store the cppcms "template" code that's used to generate
        #what the user will "see" (html/json/xml etc.)
        "views" : { 
            
            #
            "apis" : {
                "layouts" : {}
            },
            "webs" : {
                "layouts" : {},
                "pages" : {}
            }
        }
    },

    # contains additional tools related to this website
    # tools to generate/treat data etc.
    "tools": {},

    # contains the data used by the website 
    # (database etc.)
    "data": {},

    # contains the configuration file of the website
    # and tools that the website use
    "conf": {},

    # contains the unit tests
    "tests": {}


}


TEMPLATE_ROOT = "../template/"


# directory were the template files are stored
CTRL_TEMPLATE_DIR = LOCAL_TEMPLATE_ROOT + "/controllers/webs"
CTRL_OUTPUT_DIR = APP_ROOT + "/src/controllers/webs"
#name of the template that contains the main template of the
# .cpp file of a controller
TMPL_CTRL_CPP = '_template_.cpp.tpl'
#name of the template that contains the main template of the
# .h file of a controller
TMPL_CTRL_H = '_template_.h.tpl'
#name of the template that contains the code for a new
#controller method
TMPL_METHOD_CPP = '_template_method.tpl'
#name of the template that contains the code for a new
#controller method that do only an action
TMPL_ACTION_ONLY_CPP = '_template_action_only.tpl'

#name of the template that contains the code for a new
#controller method header
TMPL_METHOD_H = '_template_method_header.tpl'
#template that contains the code to attach the action
#to the controller
TMPL_METHOD_DISPATCH_CPP = '_template_method_dispatcher_.tpl'

#marker to tell where to put the next method's code in the
#controller file
NEXT_ACTION_MARKER = "%%%NEXT_ACTION_MARKER%%%"
NEXT_ACTION_DISPATCHER_MARKER = "%%%NEXT_ACTION_DISPATCHER_MARKER%%%"


MAIN_APP_TEMPLATE_DIR = LOCAL_TEMPLATE_ROOT
MAIN_APP_DIR = APP_ROOT + "/src"

TMPL_MAIN_APP_DISPATCHER_CPP = 'controller_dispatcher.tpl'
TMPL_MAIN_APP_CONSTRUCT_CPP = 'controller_construct.tpl'

TMPL_MAIN_APP_INCLUDE_H = 'controller_header.tpl'
TMPL_MAIN_APP_ATTR_H = 'controller_header_attr.tpl'

NEXT_CONTROLLER_DISPATCHER_MARKER = '%%%NEXT_CONTROLLER_DISPATCHER_MARKER%%%'
NEXT_MAIN_APP_CTRL_CONSTRUCT_MARKER = '%%%NEXT_MAIN_APP_CTRL_CONSTRUCT_MARKER%%%'

NEXT_CONTROLLER_INCLUDE_MARKER = '%%%NEXT_CONTROLLER_INCLUDE_MARKER%%%'
NEXT_MAIN_APP_CTRL_ATTR = '%%%NEXT_MAIN_APP_CTRL_ATTR%%%'


# content
CONTENT_TMPL_DIR = LOCAL_TEMPLATE_ROOT + "/contents"
CONTENT_OUTPUT_DIR = APP_ROOT + "/src/contents"

TMPL_CONTENT_H = "_controller_content.tpl"
TMPL_CONTENT_INCLUDE_H = '_action_content_.tpl'

NEXT_CONTENT_MARKER = '%%%NEXT_CONTENT_MARKER%%%'

# 
VIEW_CTRL_TMPL_DIR = LOCAL_TEMPLATE_ROOT + '/views/webs'
VIEW_CTRL_OUTPUT_DIR = APP_ROOT + '/src/views/webs'

TMPL_VIEW_ACTION_TPL = '_action_.tpl'

#form page

TMPL_METHOD_FORM_DISPATCH_CPP = '_template_form_dispatcher_.tpl'
TMPL_METHOD_FORM_H = '_template_form_header.tpl'
TMPL_METHOD_FORM_CPP = '_template_form.tpl'
TMPL_CONTENT_FORM_H = '_input_content_.tpl'
TMPL_CONTENT_FORM_INCLUDE_H = '_content_include_form.tpl'
TMPL_VIEW_FORM_TPL = '_form_action_.tpl'

NEXT_CONTENT_FORM_INCLUDE_MARKER = '%%%NEXT_CONTENT_FORM_INCLUDE_MARKER%%%'

# models 


MODEL_TMPL_DIR = LOCAL_TEMPLATE_ROOT + '/models'
MODEL_OUTPUT_DIR = APP_ROOT + '/src/models'

MODEL_CPP_TPL = '_model_.cpp.tpl'
MODEL_H_TPL = '_model_.h.tpl'


#
MODEL_CTRL_TMPL_DIR = LOCAL_TEMPLATE_ROOT + "/controllers/webs"
MODEL_CTRL_OUTPUT_DIR = APP_ROOT + "/src/controllers/webs"

NEW_MODEL_CTRL_TPL = '_new_model_ctrl.tpl'
DEL_MODEL_CTRL_TPL = '_del_model_ctrl.tpl'
INC_MODEL_CTRL_TPL = '_inc_model_ctrl.tpl'
VAR_MODEL_CTRL_TPL = '_var_model_ctrl.tpl'
CLASS_MODEL_CTRL_TPL = '_class_model_ctrl.tpl'

NEXT_NEW_MODEL_CTRL_MARKER = '%%%NEXT_NEW_MODEL_CTRL_MARKER%%%'
NEXT_INC_MODEL_CTRL_MARKER = '%%%NEXT_INC_MODEL_CTRL_MARKER%%%'
NEXT_DEL_MODEL_CTRL_MARKER = '%%%NEXT_DEL_MODEL_CTRL_MARKER%%%'
NEXT_VAR_MODEL_CTRL_MARKER = '%%%NEXT_VAR_MODEL_CTRL_MARKER%%%'
NEXT_CLASS_MODEL_CTRL_MARKER = '%%%NEXT_CLASS_MODEL_CTRL_MARKER%%%'

# models 


FORM_TMPL_DIR = LOCAL_TEMPLATE_ROOT + '/contents/forms'
FORM_OUTPUT_DIR = APP_ROOT + '/src/contents/forms'

FORM_H_TPL = '_form_.h.tpl'


