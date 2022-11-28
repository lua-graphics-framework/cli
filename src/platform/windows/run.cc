#include <iostream>
#include <string>

#include "include/run.h"

void WindowsRun::runCmd()
{
  system("powershell.exe Write-Host \"Running...\" -ForegroundColor green");
  system("powershell.exe .\\build\\LuaGraphicsFramework.exe scripts\\main.lua");
}
