cmake_minimum_required(VERSION 3.20)

project(DS_Library 
    VERSION 0.2.0 
    LANGUAGES CXX)

add_library(DS INTERFACE)

add_library(DS::DS ALIAS DS)

target_compile_features(
    DS
    INTERFACE
        cxx_std_17
)

target_include_directories(
    DS
    INTERFACE
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

option(DS_BUILD_TESTS "Build tests" ON)

if(DS_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

option(DS_BUILD_EXAMPLES "Build examples" OFF)

if(DS_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()