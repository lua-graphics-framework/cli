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
          showHelp();
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
          newCmd();
        }

        // Runs the LGF project
        if (str == "run")
        {
          runCmd();  
        }
        
        // Updates LGF
        if (str == "update")
        {
          update();
        }

        // Installs LGF
        if (str == "install")
        {
          installCmd();
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