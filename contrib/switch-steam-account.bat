@echo off

set steam_lib_path="%programfiles(x86)%\Steam\steamapps"
set steam_lib_path_real="%programfiles(x86)%\Steam\steamapps-main"

set main="CHANGEME"
set alt1="CHANGEME"

TITLE Select Steam account
taskkill.exe /F /IM steam.exe
cls
echo 1) %main%
echo 2) %alt1%

CHOICE /M Select /C 12
If Errorlevel 2 Goto 2
If Errorlevel 1 Goto 1

:2
set username=%alt1%
set steam_lib_path_real="%programfiles(x86)%\Steam\steamapps-alt"
Goto end
:1
set username=%main%
Goto end

:end
reg add "HKCU\Software\Valve\Steam" /v AutoLoginUser /t REG_SZ /d %username% /f
reg add "HKCU\Software\Valve\Steam" /v RememberPassword /t REG_DWORD /d 1 /f
rmdir %steam_lib_path%
mklink /J %steam_lib_path% %steam_lib_path_real%
start steam://open/main

exit
)
