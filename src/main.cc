#include <iostream>
#include <string>
#include <vector>
#include <filesystem>

#ifdef _WIN32
#include <Windows.h>
#include "include/help.h"
#include "include/new.h"
#include "include/update.h"
#include "include/run.h"
#include "include/install.h"
#endif

#ifdef __linux__
#include "platform/linux/include/help.h"
#include "platform/linux/include/new.h"
#include "platform/linux/include/run.h"
#endif

int main(int argc, char *argv[])
{
  // Make sure the user inputted an argument
  if (argc > 1)
  {
    // Get all of the arguments
    std::vector<std::string> args;
    
    for (int i = 1; i < argc; i++)
    {
      args.push_back(argv[i]);
    }
    
    // Loop through each argument
    for (auto &str : args)
    {
      // If we want to specify a parameter
      if (str.find("--", 0) == 0)
      {
        // Help
        if (str == "--help")
        {
#ifdef _WIN32
          showHelp();
#elif __linux__
          LinuxHelp::showHelp();
#endif
        }
        else
        {
          std::cout << "Unknown option \"" << str << "\".\n";
          exit(1);
        }
      }
      // If not, we want to input some options
      else
      {
        // Creates a new LGF project
        if (str == "new")
        {
#ifdef _WIN32
          showHelp();
#elif __linux__
          LinuxNew::newCmd();
#endif
        }

        // Runs the LGF project
        if (str == "run")
        {
#ifdef _WIN32
          showHelp();
#elif __linux__
          LinuxRun::runCmd();
#endif  
        }
        
        // Updates LGF
        if (str == "update")
        {
#ifdef _WIN32
    showHelp();
#elif __linux__
    LinuxHelp::showHelp();
#endif
        }

        // Installs LGF
        if (str == "install")
        {
#ifdef _WIN32
    showHelp();
#elif __linux__
    LinuxHelp::showHelp();
#endif
        }
      }
    }
  }

  if (argc == 1)
  {
#ifdef _WIN32
    showHelp();
#elif __linux__
    LinuxHelp::showHelp();
#endif
  }

  return 0;
}