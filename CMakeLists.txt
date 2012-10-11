PROJECT(cppcmsskel)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)


include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
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


add_library(
    cppcmsskel
    SHARED
    ${framework_generics_files}
    ${framework_models_files}
    ${framework_controllers_files}
)

target_link_libraries(
    cppcmsskel
    cppcms
    cppdb
)


install(
    TARGETS cppcmsskel
    LIBRARY DESTINATION lib
)
