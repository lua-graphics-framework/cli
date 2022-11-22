#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

#include "include/update.h"

#include <Windows.h>

// Updates LGF unconditionally
void unconditionalUpdate()
{
  // Time for an update!
  std::string file = "https://github.com/lua-graphics-framework/lgf/releases/download/lgf-v0.1.0/LGF-v0.1.0.tar.gz";

  // Get the user's home directory
  std::string installLocation = getenv("USERPROFILE");
  installLocation += "\\.lgf";

  // Get the file
  std::string updateCmd = "powershell.exe wget " + file + " -o lgf.tar.gz";

  // Make sure the directory exists
  if (!std::filesystem::is_directory(installLocation))
  {
    std::filesystem::create_directory(installLocation);
  }

  if (std::filesystem::is_regular_file(installLocation + "\\bin\\libLuaGraphicsFramework.dll"))
  {
    system("powershell.exe rm $HOME\\.lgf\\*.lua");
    system("powershell.exe rm -r $HOME\\.lgf\\bin");
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

  std::string mv = "powershell.exe mv LGF-v0.1.0 " + installLocation;
  system(mv.c_str());

  std::string mvBin = "powershell.exe mv $HOME\\.lgf\\LGF-v0.1.0\\*.lua $HOME\\.lgf";
  std::string mvSrc = "powershell.exe mv $HOME\\.lgf\\LGF-v0.1.0\\bin $HOME\\.lgf";
  std::string del = "powershell.exe rm $HOME\\.lgf\\LGF-v0.1.0";

  system(mvBin.c_str());
  system(mvSrc.c_str());
  system(del.c_str());

  system("powershell.exe Write-Host Done! -ForegroundColor green");
}

void update()
{
  std::string currentVersion = "0.1.0";

  // Get the latest version
  system("curl -o version.txt https://raw.githubusercontent.com/lua-graphics-framework/lgf/main/VERSION");

  // Convert the version file into a string
  std::ifstream data("version.txt");
  std::string line, version;

  std::getline(data, line);
  version += line;

  data.close();

  // Check if we need to update
  if (currentVersion == version)
  {
    system("powershell.exe Write-Host \"LGF up to date!\" -ForegroundColor green");
  }
  else
  {
    system("powershell.exe Write-Host \"Updating...\" -ForegroundColor green");
    unconditionalUpdate();
  }

  // Get the CLI latest version
  std::string currentCliVersion = "0.1.0";
  system("curl -o cli_version.txt https://raw.githubusercontent.com/lua-graphics-framework/lgf/main/CLI_VERSION");

  // convert the version file into a string
  std::ifstream clidata("cli_version.txt");
  std::string line2, cliVersion;

  std::getline(clidata, line2);
  cliVersion += line2;

  clidata.close();

  if (currentCliVersion != cliVersion)
  {
    system("powershell.exe Write-Host \"Updating CLI...\" -ForegroundColor green");

    std::string installLocation = getenv("USERPROFILE");
    installLocation += "\\.lgf";

    // Download
    std::string file = "https://github.com/lua-graphics-framework/cli/releases/download/v" + version + "/LGFCLI.exe";
    std::string updateCmd = "powershell.exe wget " + file + " -o LGF_cli.ex_";

    system("powershell.exe Write-Host \"Downloading...\" -ForegroundColor blue");
    system(updateCmd.c_str());

    std::string mv = "powershell.exe mv LGF_cli.ex_ " + installLocation;
    system(mv.c_str());

    system("powershell.exe Write-Host \"Installing...\" -ForegroundColor blue");

    std::string env = getenv("USERPROFILE");

    system(("powershell mv " + env + "\\.lgf\\lgf.exe $HOME\\.lgf\\lgf.bak").c_str());
    system(("powershell mv " + env + "\\.lgf\\LGF_cli.ex_ $HOME\\.lgf\\lgf.exe").c_str());

    system("powershell.exe Write-Host \"Cleaning up...\" -ForegroundColor blue");
  }
  else
  {
    system("powershell.exe Write-Host \"CLI up to date!\" -ForegroundColor green");
  }

  system("powershell.exe rm cli_version.txt");
  system("powershell.exe rm version.txt");
}
