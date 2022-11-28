#include <iostream>
#include <string>
#include <filesystem>

#include "include/install.h"
#include "include/update.h"

#ifdef _WIN32
#include <Windows.h>
#endif

void WindowsInstall::installCmd()
{
  system("powershell.exe Write-Host \"Installing LGF CLI...\" -ForegroundColor green");

  std::string env = getenv("USERPROFILE");

  if (!std::filesystem::is_directory(env + "\\.lgf"))
  {
    system("powershell.exe Write-Host \"Creating .lgf folder\" -ForegroundColor blue");
    std::filesystem::create_directories(env + "\\.lgf");
  }

  system("powershell.exe Write-Host \"Copying\" -ForegroundColor blue");

  char path[1000];
  GetModuleFileNameA(NULL, path, 1000);

  std::filesystem::copy_file(path, env + "\\.lgf\\lgf.exe");

  system("powershell.exe Write-Host \"Installing LGF...\" -ForegroundColor green");

  unconditionalUpdate();
  system("powershell.exe Write-Host \"Finished! Do not forget to add lgf to the PATH environment variable!\" -ForegroundColor green");
}
