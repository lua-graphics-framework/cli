#include <iostream>
#include <string>
#include <filesystem>

#include "include/new.hpp"
#include "include/util.hpp"

void WindowsNew::newCmd()
{
  // Get the project name
  std::string projectName = "";
  WindowsUtilities::coloredPrint(GREEN, "Creating an LGF project...");
  
  std::cout << "What is your project's name? : ";
  std::cin >> projectName;

  WindowsUtilities::coloredPrint(GREEN, "Creating project...");

  // Create directories
  std::filesystem::create_directory(projectName);
  std::filesystem::create_directory(projectName + "\\build");
  std::filesystem::create_directory(projectName + "\\scripts");

  WindowsUtilities::coloredPrint(GREEN, "Successfully created a project!");
}
