#include <iostream>
#include <string>

#include "include/help.h"
#include "../windows/include/help.h"

// Shows the help menu
void LinuxHelp::showHelp()
{
  // Since on all platforms it's the same, just call the Windows one
  // TODO: maybe a little more directory cleanup?
  WindowsHelp::showHelp();
}
