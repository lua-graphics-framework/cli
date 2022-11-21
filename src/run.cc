#include <iostream>
#include <string>

#include "include/run.h"

void runCmd()
{
  system("powershell.exe Write-Host \"Running...\" -ForegroundColor green");
  system("powershell.exe cp build\\*.dll .");
  system("powershell.exe lua54 .\\scripts\\main.lua");
  system("powershell.exe rm *.dll");
  system("powershell.exe cd ..");
}
