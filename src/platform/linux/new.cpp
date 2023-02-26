#include <iostream>
#include <string>
#include <filesystem>

#include "include/new.hpp"
#include "include/util.hpp"

void Linux::newCmd() {
  // Get the project's name
  std::string projName;

  std::cout << "What is your project's name? : ";
  std::cin >> projName;

  Utilities::coloredPrint(COLORCODE_GREEN, "Creating an LGF project...");

  // Create the folders
  std::filesystem::create_directory(projName);
  std::filesystem::create_directory(projName + "/build");
  std::filesystem::create_directory(projName + "/scripts");
  std::filesystem::create_directory(projName + "/lgf");

  // Copy files
  Utilities::coloredPrint(COLORCODE_BLUE, "\tCopying files...");
  Utilities::cppSystem("cp ~/.lgf/*.so " + projName + "/build");
  Utilities::cppSystem("cp ~/.lgf/LuaGraphicsFramework " + projName + "/build");

  // Copy Lua modules
  Utilities::coloredPrint(COLORCODE_BLUE, "\tCopying modules...");
  Utilities::cppSystem("cp ~/.lgf/*.lua " + projName + "/lgf");

  Utilities::coloredPrint(COLORCODE_GREEN, "Success!");
}
