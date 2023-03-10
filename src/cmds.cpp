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
#elif __linux__
  #include "platform/linux/include/new.hpp"
  #include "platform/linux/include/run.hpp"
  #include "platform/linux/include/update.hpp"
  #include "platform/linux/include/install.hpp"
#endif

// Checks to see if we need to clean up after updating
bool Commands::checkUpdateClean() {
  #ifdef _WIN32
    std::string env = getenv("USERPROFILE");
  #elif __unix__
    std::string env = getenv("HOME");
  #endif

  std::ifstream file(env + "/.lgf/updated");

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
    #ifdef _WIN32
      std::string env = getenv("USERPROFILE");
    #elif __unix__
      std::string env = getenv("HOME");
    #endif

    std::filesystem::remove(env + "/.lgf/updated");

    #ifdef _WIN32
      std::filesystem::remove(env + "/.lgf/lgf_old.exe");
    #elif __linux__
      std::filesystem::remove(env + "/.lgf/lgf_old");
    #endif
  }
}

void Commands::help() {
  clean();

  std::cout << 

  "LGF CLI Version 0.1.0\n\n"
  "commands:\n"

  "new -> creates a new LGF project in a new directory\n"
  "update -> checks for updates and if an update is needed, LGF will update itself\n"
  "install -> installs LGF & LGF CLI\n"
  "run -> runs the LGF project\n" << std::endl;
}

void Commands::install() {
  // clean();

  #ifdef _WIN32
    WindowsInstall::installCmd();
  #elif __linux__
    Linux::install();
  #endif
}

void Commands::new_() {
  clean();

  #ifdef _WIN32
    WindowsNew::newCmd();
  #elif __linux__
    Linux::newCmd();
  #endif
}

void Commands::run() {
  clean();

  #ifdef _WIN32
    WindowsRun::runCmd();
  #elif __linux__
    Linux::runCmd();
  #endif
}

void Commands::update() {
  clean();

  #ifdef _WIN32
    WindowsUpdate::update();
  #elif __linux__
    Linux::updateCmd();
  #endif
}
