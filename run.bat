@echo off
set "ExePath=%~dp0build\Release\LightboxController.exe"

if not exist "%ExePath%" (
    echo Error: Executable not found.
    echo Please run build.bat first.
    pause
    exit /b 1
)

start "" "%ExePath%"
