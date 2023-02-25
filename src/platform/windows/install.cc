#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>

#include "include/install.h"
#include "include/update.h"
#include "include/util.h"

#ifdef _WIN32
#include <Windows.h>
#endif

void WindowsInstall::installCmd()
{
  WindowsUtilities::coloredPrint(GREEN, "Installing LGF CLI...");

  std::string env = getenv("USERPROFILE");

  // Create a .lgf folder
  if (!std::filesystem::is_directory(env + "~\\.lgf"))
  {
    WindowsUtilities::coloredPrint(BLUE, "Creating .lgf folder");
    std::filesystem::create_directory(env + "\\.lgf");
  }

  // Copy the current file
  WindowsUtilities::coloredPrint(BLUE, "Copying self...");

  char path[1000];
  GetModuleFileNameA(NULL, path, 1000);

  // Get the latest LGF version
  system("curl -o version.txt https://raw.githubusercontent.com/lua-graphics-framework/lgf/dev/VERSION --ssl-no-revoke");

  // Convert the version file into a string
  std::ifstream data("version.txt");
  std::string line;

  std::getline(data, line);
  std::string version = line;

  std::filesystem::copy_file(path, env + "\\.lgf\\lgf.exe");
  WindowsUtilities::coloredPrint(BLUE, "Installing LGF...");

  // Install the "real" LGF
  WindowsUpdate::unconditionalUpdate(version);
  WindowsUtilities::coloredPrint(GREEN, "Finished! Do not forget to add \"" + env + "\\.lgf\" to the PATH environment variable!");

  data.close();
  std::filesystem::remove("version.txt");
}
