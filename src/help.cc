#include <iostream>
#include <string>
#include <fstream>

#include "include/help.h"

// Shows the text that shows the user each command and its options
void showHelp()
{
  std::cout << 

  "LGF CLI Version 0.1.0\n\n"
  "commands:\n"

  "new -> creates a new LGF project in a new directory\n"
  "update -> checks for updates and if an update is needed, LGF will update itself\n"
  "install -> installs LGF & LGF CLI\n"
  "run -> runs the LGF project\n\n";
}
