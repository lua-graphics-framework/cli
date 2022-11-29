#include <iostream>
#include <string>

#include <filesystem>
#include <unistd.h>

#include "include/install.h"
#include "include/update.h"

void LinuxInstall::installCmd()
{
  system("printf \"\e[32mInstalling LGF CLI...\e[0m\n\"");
  
  if (!std::filesystem::is_directory("~/.lgf"))
  {
    system("mkdir ~/.lgf");
  }

  system("printf \"\e[32mCopying...\e[0m\n\"");

  char path[1000];
  if (!getcwd(path, 1000))
  {
    std::cout << "Error when trying to get the path of LGFCLI.exe.\n";
    exit(1);
  }

  std::string p = path;
  std::string cpCmd = "cp " + p + "/LGFCLI ~/.lgf/lgf";
  system(cpCmd.c_str());

  system("printf \"\e[32mInstalling LGF...\e[0m\n\"");
  
  LinuxUpdate::checkVersion();
  LinuxUpdate::unconditionalUpdate();

  system("printf \"\e[32mDone. Remember to add ~/.lgf to the PATH environment variable in .bashrc or move ~/lgf/lgf to /usr/bin.\e[0m\n\"");
}
