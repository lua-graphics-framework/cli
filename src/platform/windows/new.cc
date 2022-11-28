#include <iostream>
#include <string>
#include <filesystem>

#include "include/new.h"

void newCmd()
{
  std::string projectName = "";
  system("powershell.exe Write-Host \"Creating an LGF project...\" -ForegroundColor green");
  
  std::cout << "What is your project's name? : ";
  std::cin >> projectName;

  system("powershell.exe Write-Host \"Creating project...\" -ForegroundColor green");

  std::filesystem::create_directory(projectName);
  std::filesystem::create_directory(projectName + "\\build");
  std::filesystem::create_directory(projectName + "\\scripts");
  std::filesystem::create_directory(projectName + "\\lgf");

  system("powershell.exe Write-Host \"Copying files...\" -ForegroundColor green");

  std::string cpExeCmd = "powershell.exe cp $HOME\\.lgf\\bin\\*.exe " + projectName + "\\build";
  system(cpExeCmd.c_str());

  system("powershell.exe Write-Host \"\tCopying dlls...\" -ForegroundColor blue");

  std::string cpCmd = "powershell.exe cp $HOME\\.lgf\\bin\\*.dll " + projectName + "\\build";
  system(cpCmd.c_str());

  system("powershell.exe Write-Host \"\tCopying modules...\" -ForegroundColor blue");

  std::string cpModCmd = "powershell.exe cp $HOME\\.lgf\\*.lua " + projectName + "$name\\lgf";
  system(cpModCmd.c_str());

  system("powershell.exe Write-Host \"Successfully created a project!\" -ForegroundColor green");
}
