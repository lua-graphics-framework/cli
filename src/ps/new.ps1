Write-Host "Creating an LGF project..." -ForegroundColor green

$name = Read-Host "What will be the name? "

Write-Host "Creating Project..." -ForegroundColor blue
mkdir $name > $null
cd $name
mkdir scripts > $null
mkdir build > $null
mkdir lgf > $null
cd ..

Write-Host "Copying files..." -ForegroundColor blue

Write-Host "  Copying dlls"
cp $HOME\.lgf\bin\*.dll $name\build

Write-Host "  Copying modules"
cp $HOME\.lgf\*.lua $name\lgf

Write-Host "Writing files..." -ForegroundColor blue
Write-Host "  Writing $name/scripts/main.lua"
"print(""Hello world!"")" | Out-File -FilePath $name\scripts\main.lua 

Write-Host "Successfully created a project!" -ForegroundColor green
