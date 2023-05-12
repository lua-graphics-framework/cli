#include <iostream>
#include <string>

#include "include/run.hpp"
#include "include/util.hpp"

void WindowsRun::runCmd()
{
  WindowsUtilities::coloredPrint(GREEN, "Running...");
  WindowsUtilities::cppSystem(".\\build\\LuaGraphicsFramework.exe scripts\\main.lua");
}
