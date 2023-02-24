#include <iostream>
#include <string>
#include <vector>
#include <filesystem>

#include "include/cmds.hpp"

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
      // Creates a new LGF project
      if (str == "new")
      {
        Commands::new_();
      }

      // Runs the LGF project
      if (str == "run")
      {
        Commands::run();
      }
      
      // Updates LGF
      if (str == "update")
      {
        Commands::update();
      }

      // Installs LGF
      if (str == "install")
      {
        Commands::install();
      }
    }
  }

  if (argc == 1)
  {
    Commands::help();
  }

  return 0;
}