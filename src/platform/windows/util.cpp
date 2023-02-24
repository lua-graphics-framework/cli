#include <iostream>
#include <string>

#include "include/util.h"

// 1 = blue, 2 = red, 3 = green
void WindowsUtilities::coloredPrint(int color, std::string text) {
  std::string cmd = "powershell.exe Write-Host \"" + text + "\" -ForegroundColor ";

  switch (color) {
  case 1:
    cmd += "blue";
    break;
  case 2:
    cmd += "red";
    break;
  case 3:
    cmd += "green";
    break;
  }

  system(cmd.c_str());
}

// Executes a system command with a C++ string rather than a C string
void WindowsUtilities::cppSystem(std::string cmd) {
  std::string modified = "powershell.exe " + cmd;
  const char *cCmd = modified.c_str();
  system(cCmd);
}
