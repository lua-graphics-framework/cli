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

  Utilities::coloredPrint(COLORCODE_GREEN, "Success!");
}
