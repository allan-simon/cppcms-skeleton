cmake_minimum_required(VERSION 2.6)

project(tatoedetect)
include_directories(
    src
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




add_executable(
    tatodetect
    src/tatodetect.cpp
    src/main.cpp
    ${controllers_files}
    ${models_files}
    ${generics_files}
    ${results_files}
    ${contents_files}
    view_web.cpp
)

target_link_libraries(
    tatodetect
    cppcms
    cppdb
    booster
    sqlite3
)

#add_executable(
#    indexer
#    src/indexer.cpp
#    src/contents/Config.cpp
#    src/generics/Languages.cpp
#    src/models/TatoDB.cpp
#)

#target_link_libraries(
#    indexer
#    tato
#    cppcms
#    cppdb
#    tokyodystopia
#)
#


add_custom_command(
    OUTPUT view_web.cpp
    COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/tools/cppcms_tmpl_cc 
        ${CMAKE_CURRENT_SOURCE_DIR}/src/views/web/*/*.tmpl 
        -o view_web.cpp
    DEPENDS
        ${CMAKE_CURRENT_SOURCE_DIR}/src/views/web/*/*.tmpl 
)
