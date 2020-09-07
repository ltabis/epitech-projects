cmake_minimum_required(VERSION 3.11)
project("api_zia")

# Set c++ version
set(CMAKE_CXX_STANDARD 17)

# API Headers
SET(API_HEADERS
        sources/Types.hpp

        sources/http/IMessage.hpp
        sources/http/IRequest.hpp
        sources/http/IResponse.hpp
        sources/http/ISocket.hpp

        sources/module/IModule.hpp
        sources/module/ALogger.hpp
        sources/module/ANetwork.hpp
        sources/module/AHttp.hpp
        )

# Examples
add_executable(logger-console
        ${API_HEADERS}
        examples/logger-console/main.cpp
        examples/logger-console/LoggerConsole.cpp
        examples/logger-console/LoggerConsole.hpp)

file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_custom_command(TARGET logger-console POST_BUILD
        COMMAND ${CMAKE_COMMAND}
        ARGS -E copy $<TARGET_FILE:logger-console> ${CMAKE_SOURCE_DIR}/bin)
