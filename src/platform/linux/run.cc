#include <iostream>
#include <string>

#include "include/run.h"

// Runs the Linux version of the "run" command
void LinuxRun::runCmd()
{
  system("printf \"\e[32mRunning...\e[0m\n\"");
  system("./build/LuaGraphicsFramework.exe scripts/main.lua");
}
