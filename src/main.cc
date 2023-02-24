#include <iostream>
#include <string>
#include <vector>
#include <filesystem>

#ifdef _WIN32
#include "platform/windows/include/help.h"
#include "platform/windows/include/new.h"
#include "platform/windows/include/run.h"
#include "platform/windows/include/install.h"
#include "platform/windows/include/update.h"
#include "platform/windows/include/util.h"
#endif

#ifdef __linux__
#include "platform/linux/include/help.h"
#include "platform/linux/include/new.h"
#include "platform/linux/include/run.h"
#include "platform/linux/include/install.h"
#include "platform/linux/include/update.h"
#endif

int main(int argc, char *argv[])
{
  WindowsUtilities::coloredPrint(1, "Hello world!");
  WindowsUtilities::coloredPrint(2, "Hello world!");
  WindowsUtilities::coloredPrint(3, "Hello world!");

//   // Make sure the user inputted an argument
//   if (argc > 1)
//   {
//     // Get all of the arguments
//     std::vector<std::string> args;
    
//     for (int i = 1; i < argc; i++)
//     {
//       args.push_back(argv[i]);
//     }
    
//     // Loop through each argument
//     for (auto &str : args)
//     {
//       // If we want to specify a parameter
//       if (str.find("--", 0) == 0)
//       {
//         // Help
//         if (str == "--help")
//         {
// #ifdef _WIN32
//           WindowsHelp::showHelp();
// #elif __linux__
//           LinuxHelp::showHelp();
// #endif
//         }
//         else
//         {
//           std::cout << "Unknown option \"" << str << "\".\n";
//           exit(1);
//         }
//       }
//       // If not, we want to input some options
//       else
//       {
//         // Creates a new LGF project
//         if (str == "new")
//         {
// #ifdef _WIN32
//           WindowsNew::newCmd();
// #elif __linux__
//           LinuxNew::newCmd();
// #endif
//         }

//         // Runs the LGF project
//         if (str == "run")
//         {
// #ifdef _WIN32
//           WindowsRun::runCmd();
// #elif __linux__
//           LinuxRun::runCmd();
// #endif  
//         }
        
//         // Updates LGF
//         if (str == "update")
//         {
// #ifdef _WIN32
//           WindowsUpdate::update();
// #elif __linux__
//           LinuxUpdate::updateCmd();
// #endif
//         }

//         // Installs LGF
//         if (str == "install")
//         {
// #ifdef _WIN32
//           WindowsInstall::installCmd();
// #elif __linux__
//           LinuxInstall::installCmd();
// #endif
//         }
//       }
//     }
//   }

//   if (argc == 1)
//   {
// #ifdef _WIN32
//     WindowsHelp::showHelp();
// #elif __linux__
//     LinuxHelp::showHelp();
// #endif
//   }

  return 0;
}