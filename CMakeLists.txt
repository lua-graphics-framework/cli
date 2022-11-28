cmake_minimum_required(VERSION 3.23)
project(LGFCLI VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

if(MSVC OR MINGW)
  set(SRCS src/help.cc src/main.cc src/update.cc src/run.cc src/new.cc src/install.cc)
elseif(LINUX)
  set(SRCS src/main.cc src/platform/linux/help.cc src/platform/windows/help.cc src/platform/linux/new.cc src/platform/linux/run.cc)
endif(MSVC OR MINGW)

add_executable(LGFCLI ${SRCS})
target_link_libraries(LGFCLI -static-libstdc++ -static-libgcc -static)
