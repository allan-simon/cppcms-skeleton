PROJECT(cppcmsskel)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

enable_testing()


include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    cppcms_skel
)


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
    cppcms
    cppdb
    booster
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

#unit tests
set(
    ALL_TESTS
    models_sqlitemodel_load_db_from_file_test
)

foreach(TEST ${ALL_TESTS})
    add_executable(
        ${TEST}
        tests/${TEST}.cpp
        ${framework_generics_files}
        ${framework_models_files}
        ${framework_controllers_files}
    )
    target_link_libraries(${TEST} ${CPPCMSSKEL_LIBS})
    add_test(
        ${TEST}
        ${TEST}
    )
endforeach()


