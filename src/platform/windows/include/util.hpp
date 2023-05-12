#pragma once
#include <string>

#define BLUE 1
#define RED 2
#define GREEN 3

namespace WindowsUtilities {
  void coloredPrint(int color, std::string text);
  void cppSystem(std::string cmd);
}
