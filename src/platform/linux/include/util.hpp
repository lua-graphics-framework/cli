#pragma once
#include <string>

#define COLORCODE_RED "\x1B[31m"
#define COLORCODE_GREEN "\x1B[32m"
#define COLORCODE_BLUE "\x1B[34m"

namespace Linux {
  namespace Utilities {
    void coloredPrint(const char *colorCode, std::string msg);
    void cppSystem(std::string cmd);
  }
}
