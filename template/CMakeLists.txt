cmake_minimum_required(VERSION 2.6)

project(@PROJECT_NAME_CODE@)


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
    src/@PROJECT_NAME_CODE@.cpp
    src/main.cpp
    ${controllers_files}
    ${models_files}
    ${generics_files}
    ${results_files}
    ${contents_files}

    view_web.cpp
)

target_link_libraries(
    @PROJECT_NAME_CODE@
    cppcms
    cppdb
    booster
    sqlite3
    cppcmsskel
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

