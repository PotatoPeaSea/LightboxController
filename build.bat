@echo off
set "QtPath=C:\Qt\5.15.2\msvc2019_64"
set "OutDir=build\Release"

echo ===================================
echo  LightboxController Build Script
echo ===================================
echo.

echo [1/3] Configuring CMake...
cmake -S . -B build -DCMAKE_PREFIX_PATH="%QtPath%"
if %ERRORLEVEL% neq 0 (
    echo CMake configuration failed!
    pause
    exit /b %ERRORLEVEL%
)

echo.
echo [2/3] Building project (Release)...
cmake --build build --config Release
if %ERRORLEVEL% neq 0 (
    echo Build failed!
    pause
    exit /b %ERRORLEVEL%
)

echo.
echo [3/3] Packaging Qt dependencies...

REM ─── Core DLLs ───────────────────────────────────────────
for %%F in (
    Qt5Core Qt5Gui Qt5Widgets Qt5Quick Qt5Qml Qt5QmlModels
    Qt5QuickControls2 Qt5QuickTemplates2 Qt5Network Qt5Multimedia
    Qt5MultimediaWidgets
    Qt53DCore Qt53DRender Qt53DInput Qt53DExtras Qt53DLogic
    Qt53DQuick Qt53DQuickExtras Qt53DQuickRender Qt53DQuickInput
    Qt53DAnimation Qt53DQuickAnimation
    Qt5QmlWorkerScript Qt5OpenGL Qt5Svg
    Qt5Concurrent Qt5Gamepad
    libEGL libGLESv2 d3dcompiler_47 opengl32sw
    assimp-vc141-mt
) do (
    if exist "%QtPath%\bin\%%F.dll" (
        copy /Y "%QtPath%\bin\%%F.dll" "%OutDir%\" >nul
    )
)

REM ─── Platform plugin (required to launch) ────────────────
if not exist "%OutDir%\platforms" mkdir "%OutDir%\platforms"
copy /Y "%QtPath%\plugins\platforms\qwindows.dll" "%OutDir%\platforms\" >nul

REM ─── Style plugins ───────────────────────────────────────
if not exist "%OutDir%\styles" mkdir "%OutDir%\styles"
if exist "%QtPath%\plugins\styles" (
    xcopy /Y /E /Q "%QtPath%\plugins\styles\*" "%OutDir%\styles\" >nul
)

REM ─── Image format plugins ────────────────────────────────
if not exist "%OutDir%\imageformats" mkdir "%OutDir%\imageformats"
if exist "%QtPath%\plugins\imageformats" (
    xcopy /Y /E /Q "%QtPath%\plugins\imageformats\*" "%OutDir%\imageformats\" >nul
)

REM ─── Icon engine plugins ─────────────────────────────────
if not exist "%OutDir%\iconengines" mkdir "%OutDir%\iconengines"
if exist "%QtPath%\plugins\iconengines" (
    xcopy /Y /E /Q "%QtPath%\plugins\iconengines\*" "%OutDir%\iconengines\" >nul
)

REM ─── Render plugins (for Qt 3D) ──────────────────────────
if not exist "%OutDir%\renderplugins" mkdir "%OutDir%\renderplugins"
if exist "%QtPath%\plugins\renderplugins" (
    xcopy /Y /E /Q "%QtPath%\plugins\renderplugins\*" "%OutDir%\renderplugins\" >nul
)

if not exist "%OutDir%\renderers" mkdir "%OutDir%\renderers"
if exist "%QtPath%\plugins\renderers" (
    xcopy /Y /E /Q "%QtPath%\plugins\renderers\*" "%OutDir%\renderers\" >nul
)

REM ─── Scene parsers (for Qt 3D) ───────────────────────────
if not exist "%OutDir%\sceneparsers" mkdir "%OutDir%\sceneparsers"
if exist "%QtPath%\plugins\sceneparsers" (
    xcopy /Y /E /Q "%QtPath%\plugins\sceneparsers\*" "%OutDir%\sceneparsers\" >nul
)

REM ─── Geometry loaders (for Qt 3D) ────────────────────────
if not exist "%OutDir%\geometryloaders" mkdir "%OutDir%\geometryloaders"
if exist "%QtPath%\plugins\geometryloaders" (
    xcopy /Y /E /Q "%QtPath%\plugins\geometryloaders\*" "%OutDir%\geometryloaders\" >nul
)

REM ─── Media service plugins (for video playback) ──────────
if not exist "%OutDir%\mediaservice" mkdir "%OutDir%\mediaservice"
if exist "%QtPath%\plugins\mediaservice" (
    xcopy /Y /E /Q "%QtPath%\plugins\mediaservice\*" "%OutDir%\mediaservice\" >nul
)

REM ─── QML modules ─────────────────────────────────────────
for %%M in (
    QtQuick.2
    QtQuick\Controls.2
    QtQuick\Controls.2\Material
    QtQuick\Layouts
    QtQuick\Templates.2
    QtQuick\Window.2
    QtQuick\Scene3D
    Qt3D\Core
    Qt3D\Render
    Qt3D\Input
    Qt3D\Extras
    Qt3D\Logic
    Qt3D\Quick
    Qt3D\QuickExtras
    Qt3D\QuickRender
    Qt3D\QuickInput
    Qt\labs\platform
) do (
    if exist "%QtPath%\qml\%%M" (
        if not exist "%OutDir%\qml\%%M" mkdir "%OutDir%\qml\%%M"
        xcopy /Y /E /Q "%QtPath%\qml\%%M\*" "%OutDir%\qml\%%M\" >nul
    )
)

REM ─── Write qt.conf to tell Qt where to find plugins/qml ──
(
    echo [Paths]
    echo Plugins = .
    echo Qml2Imports = ./qml
) > "%OutDir%\qt.conf"

echo.
echo ===================================
echo  Build complete!
echo  Output: %OutDir%\LightboxController.exe
echo  Run with: run.bat
echo ===================================
pause
