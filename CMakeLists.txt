cmake_minimum_required(VERSION 3.10)
project(Swallow C)

set(CMAKE_C_STANDARD 17)

add_executable(Swallow Terminal/terminal.c Terminal/commands.c Terminal/detect.c Arduino/tests.c)

target_compile_options(Swallow PRIVATE -Wall -Wextra)
