PROJECT(cppcmsskel)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

#set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

set(PROJECT_VERSION "0.20.0")
set(PROJECT_SOVERSION "0")
set(ARCHIVE_NAME ${CMAKE_PROJECT_NAME}-${PROJECT_VERSION})
add_custom_target(
    dist
    COMMAND git archive --prefix=${ARCHIVE_NAME}/ HEAD
        | bzip2 > ${CMAKE_BINARY_DIR}/${ARCHIVE_NAME}.tar.bz2
	WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

###################
# Dependency check
##################
find_library(CPPCMS cppcms)
find_library(BOOSTER booster)
find_library(CPPDB cppdb)
find_library(SQLITE3 sqlite3)



###################
# source files
###################
file(
    GLOB
    framework_generics_files
    cppcms_skel/generics/*
)

file(
    GLOB
    framework_models_files
    cppcms_skel/models/*
)



file(
    GLOB
    framework_controllers_files
    cppcms_skel/controllers/webs/*
    cppcms_skel/controllers/generics/*
)


# used to create libccpcmsskel.so

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    cppcms_skel
)


add_library(
    cppcmsskel
    SHARED
    ${framework_generics_files}
    ${framework_models_files}
    ${framework_controllers_files}
)


# TODO cppdb should not be mandatory
set(
    CPPCMSSKEL_LIBS
    ${CPPCMS}
    ${CPPDB}
    ${BOOSTER}
    ${SQLITE3}
)

target_link_libraries(
    cppcmsskel
    ${CPPCMSSKEL_LIBS}
)



# we install the "template" files (i.e c++ code with placeholders)
# a local copy of them will be made each time we create a new app
install(
    DIRECTORY template
    DESTINATION share/cppcmsskel
    PATTERN "README" EXCLUDE
)


# we install the "tools" (set of script to do basic tasks)
# in (/usr/local)/share/cppcmsskel
# we do not install them in bin to not polluate it
# instead the framework will create a link to them in the tools directory
# of a given application
install(
    DIRECTORY tools
    DESTINATION share/cppcmsskel
    USE_SOURCE_PERMISSIONS
    PATTERN "*.pyc" EXCLUDE
    PATTERN "__pycache__" EXCLUDE
    PATTERN "*.swp" EXCLUDE
)

# to install the libcppcmsskel
install(
    TARGETS cppcmsskel
    LIBRARY DESTINATION lib
)

set_target_properties(cppcmsskel PROPERTIES VERSION ${PROJECT_VERSION} SOVERSION ${PROJECT_SOVERSION})

# install the header files
install(
    DIRECTORY cppcms_skel
    DESTINATION include
    USE_SOURCE_PERMISSIONS
    PATTERN "README" EXCLUDE
    PATTERN "*.cpp" EXCLUDE
)

# to install create_new_cppcmsskel (command to initiate a new
# cppcmsskel directory)
install(
    FILES tools/create_new_cppcmsskel
    DESTINATION bin
    PERMISSIONS
        WORLD_EXECUTE WORLD_READ
        GROUP_EXECUTE GROUP_READ
        OWNER_EXECUTE OWNER_READ
)

###############
# unit tests
###############
enable_testing()

    ######
    # Unit test for Models
    #####

    #we define all the methods that are covered by test

    set(
        MODULE
        models
    )

    ######
    # Note: there's a little hack here 
    # we define the classes   Class1 / Class2
    # and after we define "lists" of methods named Class1_models_methods
    # Class2_models_methods etc.  this way after we can do
    # foreach METHOD ${${CLASS_NAME}_methods}
    # to go through all methods of all class without duplicating cmake code
    #####
    set(
        CLASSES
        SqliteModel
        Users
    )

    set(
        SqliteModel_MODELS_METHODS
        import_sql_file
        check_existence
    )

    set(
        Users_MODELS_METHODS
        username_exists
        email_exists
        is_login_correct 
        add
        change_password
    )

    foreach(CLASS ${CLASSES})
        foreach(METHOD ${${CLASS}_MODELS_METHODS})
            #we are supposed to have a folder named with the
            #method named, and with inside one test by .cpp
            #file
            file(
                GLOB
                TESTS
                tests/${MODULE}/${CLASS}/${METHOD}/*.cpp
            )

            #for each of these tests
            foreach(TEST_FULL_PATH ${TESTS})


                #we do that in two time in order to extract only the test
                #name out of the full path
                string(
                    REGEX MATCH
                    "([^/]+)[.]cpp"
                    TEST
                    ${TEST_FULL_PATH}
                )
                string(
                    REGEX MATCH
                    "[^.]+"
                    TEST
                    ${TEST}
                )

                #just here to factorize
                set(
                    EXECUTABLE_PATH
                    tests/${MODULE}/${CLASS}/${METHOD}
                )

                add_executable(
                    ${EXECUTABLE_PATH}/${TEST}
                    ${EXECUTABLE_PATH}/${TEST}.cpp
                    cppcms_skel/${MODULE}/${CLASS}.cpp
                    cppcms_skel/generics/Config.cpp
                    cppcms_skel/models/SqliteModel.cpp
                    ${EXECUTABLE_PATH} #required to put it like this in order to
                                       #the custom command to know it has to be
                                       #created
                )
                target_link_libraries(${EXECUTABLE_PATH}/${TEST} ${CPPCMSSKEL_LIBS})

                #this command is to create the directory in the build directory
                #in order to have the executable in the same hierarchy as their
                #corresponding .cpp, in order to find them easily without the possiblity
                #to have conflict between test name
                add_custom_command(
                    OUTPUT  ${EXECUTABLE_PATH}
                    COMMAND mkdir -p ${EXECUTABLE_PATH}
                )
                add_test(
                    ${EXECUTABLE_PATH}/${TEST}
                    ${EXECUTABLE_PATH}/${TEST}
                )
            endforeach()
        endforeach()
    endforeach()


