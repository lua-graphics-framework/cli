#include <iostream>
#include <string>
#include <filesystem>

#include "include/run.hpp"
#include "include/util.hpp"

void Linux::runCmd() {
  Utilities::coloredPrint(COLORCODE_GREEN, "Running...");

  std::string home = getenv("HOME");

  if (!std::filesystem::is_directory(home + "\\.lgf\\script_tmp")) {
    std::filesystem::create_directory(home + "\\.lgf\\script_tmp");
  }

  Utilities::cppSystem("cp .\\scripts\\*.lua " + home + "\\.lgf\\script_tmp");
  Utilities::cppSystem(home + "\\.lgf\\bin\\LuaGraphicsFramework.exe " + home + "\\.lgf\\script_tmp\\main.lua");

  Utilities::cppSystem("./build/LuaGraphicsFramework scripts/main.lua");
}
