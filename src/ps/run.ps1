Write-Host "Running..." -ForegroundColor green
cp build\*.dll .
lua54 .\scripts\main.lua
rm *.dll
cd ..

Write-Host "Finished." -ForegroundColor green
