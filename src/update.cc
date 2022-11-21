#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

#include "include/update.h"

#include <Windows.h>

void update()
{
  std::string currentVersion = "0.1.0";

  // Get the latest version
  system("curl -o version.txt https://raw.githubusercontent.com/lua-graphics-framework/lgf/main/VERSION");

  // convert the version file into a string
  std::ifstream data("version.txt");
  std::string line, version;

  std::getline(data, line);
  version += line;

  data.close();

  if (currentVersion == version)
  {
    system("powershell.exe Write-Host \"Up to date!\" -ForegroundColor green");
  }
  else
  {
    system("powershell.exe Write-Host \"Updating...\" -ForegroundColor green");

    // Time for an update!
    std::string file = "https://github.com/lua-graphics-framework/lgf/releases/download/lgf-v" + version + "/LGF-v"
      + version + ".tar.gz";

    std::string installLocation = getenv("USERPROFILE");
    installLocation += "\\.lgf";

    std::string updateCmd = "powershell.exe wget " + file + " -o lgf.tar.gz";

    // Make sure the directory exists
    if (!std::filesystem::is_directory(installLocation))
    {
      std::filesystem::create_directory(installLocation);
    }
    
    if (!std::filesystem::is_empty(installLocation))
    {
      std::filesystem::remove_all(installLocation);
    }

    // Download
    system("powershell.exe Write-Host \"Downloading...\" -ForegroundColor blue");
    system(updateCmd.c_str());

    // Extract
    system("powershell.exe Write-Host \"Extracting...\" -ForegroundColor blue");
    system("powershell.exe tar zxf lgf.tar.gz");

    // Cleanup
    system("powershell.exe Write-Host \"Cleaning up...\" -ForegroundColor blue");
    std::filesystem::remove("lgf.tar.gz");
    std::filesystem::remove("version.txt");

    std::string mv = "powershell.exe mv LGF-v" + version + " " + installLocation;
    system(mv.c_str());

    system("powershell.exe Write-Host \"Done!\" -ForegroundColor green");
  }

  // Get the CLI latest version
  std::string currentCliVersion = "0.0.0";
  system("curl -o cli_version.txt https://raw.githubusercontent.com/lua-graphics-framework/lgf/main/CLI_VERSION");

  // convert the version file into a string
  std::ifstream clidata("cli_version.txt");
  std::string line2, cliVersion;

  std::getline(data, line2);
  currentCliVersion += line2;

  clidata.close();

  if (currentCliVersion != cliVersion)
  {
    std::string installLocation = getenv("USERPROFILE");
    installLocation += "\\.lgf";

    std::string file = "https://github.com/lua-graphics-framework/lgf/releases/download/lgf-v" + version + "/LGF-v"
      + version + ".tar.gz";

    std::string updateCmd = "powershell.exe wget " + file + " -o lgf.tar.gz";
  }
}
