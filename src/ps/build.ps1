Write-Host "Building project..." -ForegroundColor green

srlua -o build/test.exe scripts/*.lua lgf/*.lua

Write-Host "Finished!" -ForegroundColor green
