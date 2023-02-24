#include <iostream>
#include <string>

#include "include/cmds.hpp"

#ifdef _WIN32
#include "platform/windows/include/new.h"
#include "platform/windows/include/run.h"
#include "platform/windows/include/install.h"
#include "platform/windows/include/update.h"
#include "platform/windows/include/util.h"
#endif

void Commands::help() {
  std::cout << 

  "LGF CLI Version 0.1.0\n\n"
  "commands:\n"

  "new -> creates a new LGF project in a new directory\n"
  "update -> checks for updates and if an update is needed, LGF will update itself\n"
  "install -> installs LGF & LGF CLI\n"
  "run -> runs the LGF project\n" << std::endl;
}

void Commands::install() {
  #ifdef _WIN32
    WindowsInstall::installCmd();
  #endif
}

void Commands::new_() {
  #ifdef _WIN32
    WindowsNew::newCmd();
  #endif
}

void Commands::run() {
  #ifdef _WIN32
    WindowsRun::runCmd();
  #endif
}

void Commands::update() {
  #ifdef _WIN32
    WindowsInstall::installCmd();
  #endif
}
