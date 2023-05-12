#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>

#include "include/install.hpp"
#include "include/update.hpp"
#include "include/util.hpp"

#include <libgen.h>
#include <unistd.h>

void Linux::install()
{
  std::string env = getenv("HOME");

  if (std::filesystem::is_directory(env + "/.lgf")) {
    Utilities::coloredPrint(COLORCODE_RED, "LGF is already installed! If you want to update, use the `lgf update` command.");
    exit(1);
  }

  Utilities::coloredPrint(COLORCODE_GREEN, "Installing LGF CLI...");

  // Create a .lgf folder
  Utilities::coloredPrint(COLORCODE_BLUE, "Creating .lgf folder");
  std::filesystem::create_directory(env + "/.lgf");

  // Copy the current file
  Utilities::coloredPrint(COLORCODE_BLUE, "Copying self...");

  char result[PATH_MAX];
  ssize_t count = readlink("/proc/self", result, PATH_MAX);
  std::string path = getenv("PWD");

  // Get the latest LGF version
  system("curl -o version.txt https://raw.githubusercontent.com/lua-graphics-framework/lgf/dev/VERSION --ssl-no-revoke");

  // Convert the version file into a string
  std::ifstream data("version.txt");
  std::string line;

  std::getline(data, line);
  std::string version = line;

  Utilities::cppSystem("cp " + path + "/LGFCLI " + env + "/.lgf/lgf");
  Utilities::coloredPrint(COLORCODE_BLUE, "Installing LGF...");

  // Install the "real" LGF
  Linux::unconditionalUpdate(version);

  // TODO: Add to PATH

  data.close();
  std::filesystem::remove("version.txt");
}
