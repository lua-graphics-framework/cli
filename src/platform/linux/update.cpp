#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

#include "include/update.hpp"
#include "include/util.hpp"

// Updates LGF unconditionally
void Linux::unconditionalUpdate(std::string version)
{
  // Time for an update!
  std::string file = "https://github.com/lua-graphics-framework/lgf/releases/download/lgf-v" + version + "/LGF-v" + version + "_linux.tar.gz";

  std::string installLocation = getenv("HOME");
  installLocation += "/.lgf";

  // Make sure the directory exists
  if (!std::filesystem::is_directory(installLocation))
  {
    std::filesystem::create_directory(installLocation);
  }

  // Remove files inside .lgf directory
  if (std::filesystem::is_directory(installLocation + "/bin")) {
    Utilities::cppSystem("rm " + installLocation + "/*.lua");
    Utilities::cppSystem("rm -r " + installLocation + "/bin");
  }

  // Download
  Utilities::coloredPrint(COLORCODE_BLUE, "\tDownloading...");
  Utilities::cppSystem("wget -q " + file);

  // Extract
  Utilities::coloredPrint(COLORCODE_BLUE, "\tExtracting...");
  Utilities::cppSystem("tar zxf LGF-v" + version + "_linux.tar.gz");

  // Cleanup
  Utilities::coloredPrint(COLORCODE_BLUE, "\tCleaning up...");
  std::filesystem::remove("LGF-v" + version + "_linux.tar.gz");

  // Move files
  Utilities::cppSystem("mv LGF-v" + version + "_linux " + installLocation);
  Utilities::cppSystem("mv " + installLocation + "/LGF-v" + version + "_linux/*.lua " + installLocation);
  Utilities::cppSystem("mv " + installLocation + "/LGF-v" + version + "_linux/bin "  + installLocation);

  // Remove temporary directory
  Utilities::cppSystem("rm -r " + installLocation + "/LGF-v" + version + "_linux");
  Utilities::coloredPrint(COLORCODE_GREEN, "Done!");
}

void Linux::updateCmd()
{
  std::string currentVersion = "0.1.0";

  // Get the latest version
  system("curl -o version.txt https://raw.githubusercontent.com/lua-graphics-framework/lgf/dev/VERSION --ssl-no-revoke");

  // Convert the version file into a string
  std::ifstream data("version.txt");
  std::string line;

  std::getline(data, line);
  std::string version = line;

  data.close();

  // Check if we need to update
  if (currentVersion == version)
  {
    Utilities::coloredPrint(COLORCODE_GREEN, "LGF up to date!");
  }
  else
  {
    Utilities::coloredPrint(COLORCODE_GREEN, "Updating LGF...");
    unconditionalUpdate(version);
  }

  // Get the latest CLI version
  std::string currentCliVersion = "0.1.0";
  system("curl -o cli_version.txt https://raw.githubusercontent.com/lua-graphics-framework/lgf/dev/CLI_VERSION --ssl-no-revoke");

  // Convert the version file into a string
  std::ifstream clidata("cli_version.txt");
  std::string line2, cliVersion;

  std::getline(clidata, line2);
  cliVersion += line2;

  if (currentCliVersion != cliVersion)
  {
    std::string env = getenv("HOME");
    Utilities::coloredPrint(COLORCODE_GREEN, "Updating CLI...");

    // Download
    std::string file = "https://github.com/lua-graphics-framework/cli/releases/download/v" + cliVersion + "/LGFCLI";

    Utilities::coloredPrint(COLORCODE_BLUE, "\tDownloading...");
    Utilities::cppSystem("wget -q " + file);

    Utilities::coloredPrint(COLORCODE_BLUE, "\tInstalling...");
    Utilities::cppSystem("mv LGFCLI " + env + "/.lgf/LGFCLI.exec");

    Utilities::cppSystem("mv " + env + "/.lgf/lgf " + env + "/.lgf/lgf_old");
    Utilities::cppSystem("mv " + env + "/.lgf/LGFCLI.exec " + env + "/.lgf/lgf");

    Utilities::coloredPrint(COLORCODE_GREEN, "Note: The excess files will be removed the next time you use the CLI.");

    std::ofstream updatedFile(env + "/.lgf/updated");
    updatedFile << "DO NOT DELETE ME.\n";
    updatedFile.close();
  }
  else
  {
    Utilities::coloredPrint(COLORCODE_GREEN, "CLI up to date!");
  }

  data.close();
  clidata.close();

  Utilities::cppSystem("rm cli_version.txt");
  Utilities::cppSystem("rm version.txt");
}
