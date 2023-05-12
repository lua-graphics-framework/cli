cmake_minimum_required(VERSION 3.0)
project(LGFCLI VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

if(MSVC OR MINGW)
  set(SRCS src/platform/windows/update.cpp src/platform/windows/run.cpp
    src/platform/windows/new.cpp src/platform/windows/install.cpp src/platform/windows/util.cpp)
endif(MSVC OR MINGW)

if(UNIX AND NOT APPLE)
  set(SRCS src/platform/linux/new.cpp src/platform/linux/util.cpp src/platform/linux/run.cpp 
    src/platform/linux/update.cpp src/platform/linux/install.cpp)
endif(UNIX AND NOT APPLE)

add_executable(LGFCLI src/cmds.cpp src/main.cpp ${SRCS})
target_link_libraries(LGFCLI -static-libstdc++ -static-libgcc -static)
