$ErrorActionPreference = "Stop"

$ExePath = "build\Release\LightboxController.exe"

if (-Not (Test-Path $ExePath)) {
    Write-Host "Error: Executable not found at $ExePath." -ForegroundColor Red
    Write-Host "Please run .\build.ps1 first to build the project." -ForegroundColor Yellow
    exit 1
}

Write-Host "Starting LightboxController..." -ForegroundColor Cyan

# Check if DLLs are present (simple check for Qt5Core)
$QtCorePath = "build\Release\Qt5Core.dll"
if (-Not (Test-Path $QtCorePath)) {
    Write-Host "Warning: Qt5Core.dll not found in Release folder. It might not launch unless Qt is in your system PATH." -ForegroundColor Yellow
}

# Run the app
Start-Process -FilePath $ExePath
