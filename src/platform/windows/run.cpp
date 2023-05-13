#include <iostream>
#include <string>
#include <filesystem>

#include "include/run.hpp"
#include "include/util.hpp"

void WindowsRun::runCmd()
{
  WindowsUtilities::coloredPrint(GREEN, "Running...");
  std::string home = getenv("USERPROFILE");

  if (!std::filesystem::is_directory(home + "\\.lgf\\script_tmp")) {
    std::filesystem::create_directory(home + "\\.lgf\\script_tmp");
  }

  WindowsUtilities::cppSystem("cp .\\scripts\\*.lua " + home + "\\.lgf\\script_tmp");
  WindowsUtilities::cppSystem(home + "\\.lgf\\bin\\LuaGraphicsFramework.exe " + home + "\\.lgf\\script_tmp\\main.lua");
}
