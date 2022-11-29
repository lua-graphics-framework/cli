#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

#include "include/update.h"

std::string version;

void LinuxUpdate::checkVersion()
{
  system("printf \"\e[32mChecking for updates...\e[0m\n\"");

  // Get the latest LGF version
  system("curl -o version.txt https://raw.githubusercontent.com/lua-graphics-framework/lgf/main/VERSION --ssl-no-revoke");

  // Convert the version file into a string
  std::ifstream data("version.txt");
  std::string line;

  std::getline(data, line);
  version += line;

  data.close();
}

// Unconditionally updates LGF
void LinuxUpdate::unconditionalUpdate()
{
  system("printf \"\e[32mUpdating LGF...\e[0m\n\"");
  std::string file = "https://github.com/lua-graphics-framework/lgf/releases/download/lgf-v" + version + "/LGF-v" + version + ".tar.gz";

  system("printf \"\e[34m Downloading...\e[0m\n\"");
  // Downloading time!
  std::string update = "wget -q " + file + " -o lgf.tar.gz";

  // Make sure the .lgf directory exists
  if (std::filesystem::is_directory("~/.lgf"))
  {
    std::cout << "Error: LGF not installed. Install LGF by running `lgf install`.\n";
    exit(1);
  }

  if (std::filesystem::exists("~/.lgf/bin/LuaGraphicsFramework"))
  {
    system("rm ~/.lgf/*.lua");
    system("rm -r ~/.lgf/bin");
  }

  // Finally, download the file
  system(update.c_str());

  // Extract
  system("printf \"\e[34m Extracting...\e[0m\n\"");
  system(std::string("tar zxf LGF-v" + version + ".tar.gz").c_str());

  // Moving lgf contents into .lgf folder and cleaning up
  system("printf \"\e[34m Cleaning up...\e[0m\n\"");

  system("rm lgf.tar.gz");
  system(std::string("rm LGF-v" + version + ".tar.gz").c_str());
  system("rm version.txt");

  std::string mv = "mv LGF-v" + version + " ~/.lgf";
  system(mv.c_str());

  // Move the contents into the parent folder
  std::string mvBin = "mv ~/.lgf/LGF-v" + version + "/*.lua ~/.lgf";
  std::string mvSrc = "mv ~/.lgf/LGF-v" + version + "/bin ~/.lgf";
  std::string del = "rm -rf ~/.lgf/LGF-v" + version;

  system(mvBin.c_str());
  system(mvSrc.c_str());
  system(del.c_str());

  // All done now!
  system("printf \"\e[32mAll done!\e[0m\n\"");
}

void LinuxUpdate::updateCmd()
{
  std::string currentLGFVersion = "0.1.0";
  checkVersion();

  // Check to see if we are up to date
  if (currentLGFVersion == version)
  {
    system("printf \"\e[32mLGF is up to date!...\e[0m\n\"");
  }
  
  // If we need to update
  if (currentLGFVersion != version)
  {
    unconditionalUpdate();
  }
}
