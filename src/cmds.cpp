#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

#include "include/cmds.hpp"

#ifdef _WIN32
  #include "platform/windows/include/new.h"
  #include "platform/windows/include/run.h"
  #include "platform/windows/include/install.h"
  #include "platform/windows/include/update.h"
  #include "platform/windows/include/util.h"
#endif

// Checks to see if we need to clean up after updating
bool Commands::checkUpdateClean() {
  std::ifstream file("$HOME/.lgf/updated");

  // We need to clean up
  if (file.is_open()) {
    file.close();
    return true;
  }

  return false;
}

// Cleans the temporary files after updating if needed
void Commands::clean() {
  if (checkUpdateClean()) {
    std::filesystem::remove("$HOME/.lgf/updated");

    #ifdef _WIN32
      std::filesystem::remove("$HOME/.lgf/lgf.exec");
    #endif
  }
}

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
