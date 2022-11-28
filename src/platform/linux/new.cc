#include <iostream>
#include <string>

#include "include/new.h"

// Runs the Linux version of the new command, which creates a new project
void LinuxNew::newCmd()
{
  // Get the project's name
  std::string projectName = "";
  system("printf \"\e[32mCreating an LGF project...\e[0m\n\"");

  std::cout << "What is your project's name? : ";
  std::cin >> projectName;

  system("printf \"\e[32mCreating project...\e[0m\n\"");
  
  // Make the directories
  std::string rootDirCmd = "mkdir " + projectName;
  std::string buildDirCmd = rootDirCmd + "/build";
  std::string scriptsDirCmd = rootDirCmd + "/scripts";
  std::string lgfDirCmd = rootDirCmd + "/lgf";

  system(rootDirCmd.c_str());
  system(buildDirCmd.c_str());
  system(scriptsDirCmd.c_str());
  system(lgfDirCmd.c_str());

  // Copy the build files
  system("printf \"\e[34mCopying files...\e[0m\n\"");

  std::string cpCmd = "cp ~/.lgf/bin/LuaGraphicsFramework " + projectName + "/build";
  system(cpCmd.c_str());

  // Copy the LGF .lua files (modules)
  std::string cpModCmd = "cp ~/.lgf/*.lua " + projectName + "/build";
  system(cpModCmd.c_str());

  system("printf \"\e[32mSuccessfully created a project!...\e[0m\n\""); 
}
