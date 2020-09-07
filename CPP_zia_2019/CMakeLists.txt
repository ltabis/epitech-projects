cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 17)
project(zia)

## Conan setup
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

## Adding APCPPLib cmakelist
add_subdirectory(APCPPLib)

## Enable Google test library
enable_testing()

## Windows doesn't Threads package
if (UNIX)
    find_package(Threads)
    add_compile_options(-g)
endif()

## Add valgring flag
if (MSVC)
    add_compile_options(/W4 /WX)
endif()

set(TEST_MODULE_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/modules/http/HttpModule.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Exception.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/modules/ModuleException.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/modules/http/TestModule.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/APCPPLib/lib/src/Log/Logger.cpp
)

## Modules sources
set(MODULE_SRC
    ${TEST_MODULE_SRC}
)

## PHPCGI Module
set(MODULE_PHPCGI_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/modules/http/PhpCgi.cpp
)

## Server sources
set(SRC_SERVER
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Core.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/LibLoader.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Shell.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Exception.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ParserJson.cpp
)

## Include headers to program
include_directories(

    ## APCPPLib library
    ${CMAKE_CURRENT_SOURCE_DIR}/APCPPLib/include/
    ${CMAKE_CURRENT_SOURCE_DIR}/APCPPLib/lib/src/Log/
    ${CMAKE_CURRENT_SOURCE_DIR}/APCPPLib/lib/src/Maths/
    ${CMAKE_CURRENT_SOURCE_DIR}/APCPPLib/lib/src/Utils/
    ${CMAKE_CURRENT_SOURCE_DIR}/APCPPLib/lib/src/Exception/
    ${CMAKE_CURRENT_SOURCE_DIR}/APCPPLib/lib/src/Benchmarking/

    # API
    ${CMAKE_CURRENT_SOURCE_DIR}/api/sources/module/
    ${CMAKE_CURRENT_SOURCE_DIR}/api/sources/http/
    ${CMAKE_CURRENT_SOURCE_DIR}/api/sources/
    # Modules
    ${CMAKE_CURRENT_SOURCE_DIR}/src/modules/
    # ${CMAKE_CURRENT_SOURCE_DIR}/src/modules/network/

    ## Source headers
    ${CMAKE_CURRENT_SOURCE_DIR}/include/
    ${CMAKE_CURRENT_SOURCE_DIR}/src/
)

#Build Modules
add_library(testModule SHARED
    ${TEST_MODULE_SRC}
)

add_library(module_phpcgi SHARED ${MODULE_PHPCGI_SRC})

## Client executable
add_executable(zia
    ${SRC_SERVER}
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

## Test sources
set (SRC_TEST
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/UnitTest_LibLoader.cpp
)

## Creating executable of unit tests
include(GoogleTest)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests)

# file(COPY ${CMAKE_CURRENT_BINARY_DIR}/lib/*
#         DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/../../tests/lib/
#     )

## Test executable
add_executable(unit_tests
    ${SRC_SERVER}
    ${HEAD_SERVER}
    ${SRC_TEST}
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/main.cpp
)

##move config file
#file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/example.json
#        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/example.json
#    )

## Linking libraries
target_link_libraries(zia
    APCPPLib
    CONAN_PKG::boost
    CONAN_PKG::rapidjson
    ${CMAKE_THREAD_LIBS_INIT}
    ${CMAKE_DL_LIBS}
)

target_link_libraries(unit_tests PUBLIC
    ${CMAKE_CURRENT_BINARY_DIR}/lib/libAPCPPLib.a
    CONAN_PKG::gtest
    CONAN_PKG::boost
    CONAN_PKG::rapidjson
    ${CMAKE_THREAD_LIBS_INIT}
    ${CMAKE_DL_LIBS}
)