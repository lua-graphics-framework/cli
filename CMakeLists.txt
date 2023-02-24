cmake_minimum_required(VERSION 3.23)
project(LGFCLI VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

if(MSVC OR MINGW)
  set(SRCS src/main.cc src/platform/windows/update.cc src/platform/windows/run.cc 
    src/platform/windows/new.cc src/platform/windows/install.cc src/platform/windows/util.cpp)
endif(MSVC OR MINGW)

add_executable(LGFCLI src/cmds.cpp ${SRCS})
target_link_libraries(LGFCLI -static-libstdc++ -static-libgcc -static)
