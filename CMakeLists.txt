cmake_minimum_required(VERSION 3.15)
project(abc)
include(cmake/StandardProjectSettings.cmake)

add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_17)

add_library(project_warnings INTERFACE)

include(cmake/CompilerWarnings.cmake)
set_project_warnings(project_warnings)

add_library(raylib_ext INTERFACE)
target_include_directories(raylib_ext INTERFACE include/)

add_subdirectory(src)
add_subdirectory(third_party)
