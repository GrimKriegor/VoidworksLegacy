@echo off
for /f "tokens=2" %%a in ('tasklist^|find /i "DarkSoulsIII.exe"') do (set pid=%%a)
zeus.exe -l %~dp0voidworks.dll -p %pid% -c
