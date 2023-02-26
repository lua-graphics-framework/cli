#include <iostream>
#include <string>

#include "include/run.hpp"
#include "include/util.hpp"

void Linux::runCmd() {
  Utilities::coloredPrint(COLORCODE_GREEN, "Running...");
  Utilities::cppSystem("./build/LuaGraphicsFramework scripts/main.lua");
}
