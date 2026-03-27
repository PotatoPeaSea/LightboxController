$QtPath = "C:/Qt/5.15.2/msvc2019_64"

Write-Host "Configuring CMake..." -ForegroundColor Cyan
cmake -S . -B build -DCMAKE_PREFIX_PATH=$QtPath
if ($LASTEXITCODE -ne 0) {
    Write-Host "CMake configuration failed!" -ForegroundColor Red
    exit $LASTEXITCODE
}

Write-Host "`nBuilding project (Release)..." -ForegroundColor Cyan
cmake --build build --config Release
if ($LASTEXITCODE -ne 0) {
    Write-Host "Build failed!" -ForegroundColor Red
    exit $LASTEXITCODE
}

Write-Host "`nDeploying Qt dependencies with windeployqt..." -ForegroundColor Cyan
$WindeployqtPath = "$QtPath/bin/windeployqt.exe"
$ExePath = "build\Release\LightboxController.exe"

if (Test-Path $WindeployqtPath) {
    # Run windeployqt with --qmldir to scan QML imports
    & $WindeployqtPath --qmldir qml $ExePath
    if ($LASTEXITCODE -ne 0) {
        Write-Host "windeployqt encountered an error, but continuing..." -ForegroundColor Yellow
    }
} else {
    Write-Host "Warning: windeployqt.exe not found at $WindeployqtPath. App may fail to start if Qt DLLs are not in PATH." -ForegroundColor Yellow
}

Write-Host "`nBuild complete! Run the app with: .\run.ps1" -ForegroundColor Green
