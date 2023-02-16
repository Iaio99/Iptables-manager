cmake_minimum_required(VERSION 3.13)
project(nc-iptables C)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(nc-iptables
        src/main.c
        src/rules.h
        src/rules.c
	    src/ui.c
        src/ui.h
        src/utils/io.c
        src/utils/io.h
        src/utils/parsing.c
        src/utils/parsing.h
)


if(MSVC)
    add_compile_options(PRIVATE /W4 /WX)
else()
    add_compile_options(PRIVATE -Wall -Wextra -Wpedantic -Werror -O2)
endif()
