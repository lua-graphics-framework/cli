#include <iostream>
#include <string>

#include "include/run.h"
#include "include/util.h"

void WindowsRun::runCmd()
{
  WindowsUtilities::coloredPrint(GREEN, "Running...");
  WindowsUtilities::cppSystem(".\\build\\LuaGraphicsFramework.exe scripts\\main.lua");
}
