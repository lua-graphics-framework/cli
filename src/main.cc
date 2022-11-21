#include <iostream>
#include <string>
#include <vector>
#include <filesystem>

#ifdef _WIN32
#include <Windows.h>
#endif

#include "include/help.h"
#include "include/new.h"
#include "include/update.h"
#include "include/run.h"

int main(int argc, char *argv[])
{
  if (argc > 1)
  {
    std::vector<std::string> args;
    
    for (int i = 1; i < argc; i++)
    {
      args.push_back(argv[i]);
    }
    
    for (auto &str : args)
    {
      if (str.find("--", 0) == 0)
      {
        if (str == "--help")
        {
          showHelp();
        }
        else
        {
          std::cout << "Unknown option \"" << str << "\".\n";
          exit(1);
        }
      }
      else
      {
        if (str == "new")
        {
          newCmd();
        }

        if (str == "run")
        {
          runCmd();  
        }

        if (str == "build")
        {
          system("powershell.exe ./src/ps/build.ps1");
        }
        
        if (str == "update")
        {
          update();
        }
      }
    }
  }

  if (argc == 1)
  {
    showHelp();
  }

  return 0;
}