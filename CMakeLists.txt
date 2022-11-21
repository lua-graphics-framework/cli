cmake_minimum_required(VERSION 3.23)
project(LGFCLI VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(SRCS src/help.cc src/main.cc src/update.cc src/run.cc src/new.cc)

add_executable(LGFCLI ${SRCS})
