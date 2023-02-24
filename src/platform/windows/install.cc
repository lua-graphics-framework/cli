#include <iostream>
#include <string>
#include <filesystem>

#include "include/install.h"
#include "include/update.h"
#include "include/util.h"

#ifdef _WIN32
#include <Windows.h>
#endif

void WindowsInstall::installCmd()
{
  WindowsUtilities::coloredPrint(GREEN, "Installing LGF CLI...");

  // Create a .lgf folder
  if (!std::filesystem::is_directory("$HOME\\.lgf"))
  {
    WindowsUtilities::coloredPrint(BLUE, "Creating .lgf folder");
    std::filesystem::create_directory("$HOME\\.lgf");
  }

  // Copy the current file
  WindowsUtilities::coloredPrint(BLUE, "Copying self...");

  char path[1000];
  GetModuleFileNameA(NULL, path, 1000);

  std::filesystem::copy_file(path, "$HOME\\.lgf\\lgf.exe");
  WindowsUtilities::coloredPrint(BLUE, "Installing LGF...");

  // Install the "real" LGF
  WindowsUpdate::unconditionalUpdate();
  WindowsUtilities::coloredPrint(GREEN, "Finished! Do not forget to add \"$HOME\\.lgf\" to the PATH environment variable!");
}
