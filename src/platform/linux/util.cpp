#include <iostream>
#include <string>

#include "include/util.hpp"

void Linux::Utilities::coloredPrint(const char *colorCode, std::string msg) {
  printf("\033[1m%s%s\x1B[0m\n", colorCode, msg.c_str());
}

void Linux::Utilities::cppSystem(std::string cmd) {
  const char *cCmd = cmd.c_str();
  system(cCmd);
}
