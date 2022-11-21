#include <iostream>
#include <string>
#include <fstream>

#include "include/help.h"

// Shows the text that shows the user each command and its options
void showHelp()
{
  // Read the help.txt file
  std::ifstream file("src/help.txt");
  std::string line, content;

  if (!file.is_open())
  {
    std::cout << "Error: Failed to display `help` message.\n";
    exit(1);
  }

  while (std::getline(file, line))
  {
    content += line + '\n';
  }

  std::cout << content;
}
