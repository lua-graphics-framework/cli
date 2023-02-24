#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

#include "include/update.h"
#include "include/util.h"

#include <Windows.h>

std::string version;

// Updates LGF unconditionally
void WindowsUpdate::unconditionalUpdate()
{
  // Time for an update!
  std::string file = "https://github.com/lua-graphics-framework/lgf/releases/download/lgf-v" + version + "/LGF-v" + version + "/.tar.gz";

  std::string installLocation = getenv("USERPROFILE");
  installLocation += "\\.lgf";

  // Make sure the directory exists
  if (!std::filesystem::is_directory(installLocation))
  {
    std::filesystem::create_directory(installLocation);
  }

  // TODO: Remove .lgf directory

  // Download
  WindowsUtilities::coloredPrint(BLUE, "Downloading...");
  WindowsUtilities::cppSystem("wget " + file + " -o lgf.tar.gz");

  // Extract
  WindowsUtilities::coloredPrint(BLUE, "Extracting...");
  WindowsUtilities::cppSystem("tar zxf lgf.tar.gz");

  // Cleanup
  WindowsUtilities::coloredPrint(BLUE, "Cleaning up...");
  std::filesystem::remove("lgf.tar.gz");
  std::filesystem::remove("version.txt");

  // Move files
  WindowsUtilities::cppSystem("mv LGF-v" + version + " " + installLocation);
  WindowsUtilities::cppSystem("mv $HOME\\.lgf\\LGF-v" + version + "\\*.lua $HOME\\.lgf");
  WindowsUtilities::cppSystem("mv $HOME\\.lgf\\LGF-v" + version + "\\bin $HOME\\.lgf");

  // Remove temporary directory
  WindowsUtilities::cppSystem("rm $HOME\\.lgf\\LGF-v" + version);
  WindowsUtilities::coloredPrint(GREEN, "Done!");
}

void WindowsUpdate::update()
{
  std::string currentVersion = "0.1.0";

  // Get the latest version
  if (!system("curl -o version.txt https://raw.githubusercontent.com/lua-graphics-framework/lgf/main/VERSION --ssl-no-revoke"))
  {
    WindowsUtilities::coloredPrint(RED, "Error: Failed to get the latest version of LGF.\n");
    exit(1);
  }

  // Convert the version file into a string
  std::ifstream data("version.txt");
  std::string line;

  std::getline(data, line);
  version += line;

  data.close();

  // Check if we need to update
  if (currentVersion == version)
  {
    WindowsUtilities::coloredPrint(GREEN, "LGF up to date!");
  }
  else
  {
    WindowsUtilities::coloredPrint(GREEN, "Updating LGF...");
    unconditionalUpdate();
  }

  // Get the latest CLI version
  std::string currentCliVersion = "0.1.0";
  system("curl -o cli_version.txt https://raw.githubusercontent.com/lua-graphics-framework/lgf/main/CLI_VERSION --ssl-no-revoke");

  // convert the version file into a string
  std::ifstream clidata("cli_version.txt");
  std::string line2, cliVersion;

  std::getline(clidata, line2);
  cliVersion += line2;

  clidata.close();

  if (currentCliVersion != cliVersion)
  {
    WindowsUtilities::coloredPrint(GREEN, "Updating CLI...");

    // Download
    std::string file = "https://github.com/lua-graphics-framework/cli/releases/download/v" + version + "/LGFCLI.exe";

    WindowsUtilities::coloredPrint(BLUE, "Downloading...");
    WindowsUtilities::cppSystem("wget " + file + " -o LGF_cli.exe");

    WindowsUtilities::coloredPrint(BLUE, "Installing...");
    WindowsUtilities::cppSystem("mv LGF_cli.exe $HOME\\.lgf\\LGF_cli.ex_");

    WindowsUtilities::cppSystem("mv $HOME\\.lgf\\lgf.exe $HOME\\.lgf\\lgf.exec");
    WindowsUtilities::cppSystem("mv $HOME\\.lgf\\LGF_cli.ex_ $HOME\\.lgf\\lgf.exe");

    WindowsUtilities::coloredPrint(BLUE, "Note: The excess files will be removed the next time you use the CLI.");
    // TODO: Remove lgf.exec
  }
  else
  {
    WindowsUtilities::coloredPrint(GREEN, "CLI up to date!");
  }

  WindowsUtilities::cppSystem("rm cli_version.txt");
  WindowsUtilities::cppSystem("rm version.txt");
}
