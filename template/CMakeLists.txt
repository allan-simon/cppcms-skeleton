cmake_minimum_required(VERSION 2.6)

project(@PROJECT_NAME_CODE@)


enable_testing()

include_directories(
    src
)


set(
    FRAMEWORK_BUILD_DIR
    build
)


file(
    GLOB
    controllers_files
    src/controllers/*
    src/controllers/webs/*
    src/controllers/generics/*
)

file(
    GLOB
    models_files
    src/models/*
)

file(
    GLOB
    results_files
    src/results/*
)

file(
    GLOB
    contents_files
    src/contents/*
)


file(
    GLOB
    generics_files
    src/generics/*
)

####### FRAMEWORK PART 
# TODO we need to compile the framework separately          
#####


add_executable(
    @PROJECT_NAME_CODE@
    src/@MAIN_CLASS@.cpp
    src/main.cpp
    ${controllers_files}
    ${models_files}
    ${generics_files}
    ${results_files}
    ${contents_files}

    view_web.cpp
)

set(
    MAIN_PROJECT_LIBS
    cppcms
    cppdb
    booster
    sqlite3
    cppcmsskel
    #if you need to link with an other lib add it here
)




target_link_libraries(
    @PROJECT_NAME_CODE@
    ${MAIN_PROJECT_LIBS}
)


add_custom_command(
    OUTPUT view_web.cpp
    COMMAND cppcms_tmpl_cc 
        ${CMAKE_CURRENT_SOURCE_DIR}/src/views/webs/layouts/master.tmpl
        ${CMAKE_CURRENT_SOURCE_DIR}/src/views/webs/*/*.tmpl 
        -o view_web.cpp
    DEPENDS
        ${CMAKE_CURRENT_SOURCE_DIR}/src/views/webs/*/*.tmpl 
)


# unit tests

set(
    ALL_TESTS
    #TODO add your tests there
)


foreach(TEST ${ALL_TESTS})
    add_executable(
        ${TEST}
        tests/${TEST}.cpp
        ${controllers_files}
        ${models_files}
        ${generics_files}
        ${results_files}
        ${contents_files}
    )
    target_link_libraries(${TEST} ${MAIN_PROJECT_LIBS})
    add_test(
        ${TEST}
        ${TEST}
    )
endforeach()


