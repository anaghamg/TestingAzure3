@echo off
REM === CONFIGURATION ===
set QT_DIR=C:\Qt\Qt5.12.1\5.12.1\msvc2015_64
set BUILD_DIR=build
set VC_VARS="C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat"
set PRO_FILE=VTK3DSphereGenerator.pro

REM === Step 1: Set up MSVC compiler environment ===
echo Setting up MSVC compiler environment...
call %VC_VARS% x64
if errorlevel 1 (
    echo Failed to set up MSVC environment.
    pause
    exit /b 1
)

REM === Step 2: Create build directory if it doesn't exist ===
if not exist "%BUILD_DIR%" (
    mkdir "%BUILD_DIR%"
)

REM === Step 3: Run qmake in the build directory ===
echo Running qmake to generate Makefile...
pushd %BUILD_DIR%
"%QT_DIR%\bin\qmake.exe" ..\src\%PRO_FILE% -spec win32-msvc CONFIG+=qtquickcompiler CONFIG+=release
if errorlevel 1 (
    echo qmake failed.
    popd
    pause
    exit /b 1
)

REM === Step 4: Build using nmake ===
echo Building the project with nmake...
nmake
if errorlevel 1 (
    echo Build failed.
    popd
    pause
    exit /b 1
)

REM === Step 5: Deploy Qt DLLs ===
echo Deploying Qt DLLs using windeployqt...
cd release
"%QT_DIR%\bin\windeployqt.exe" .
if errorlevel 1 (
    echo windeployqt failed.
    popd
    pause
    exit /b 1
)

REM Step 6: Copy VTK DLLs
xcopy "..\..\lib\VTK8.2\Release\bin\*.dll" "%CD%" /Y /I

REM === Step 7: Done ===
popd
echo Build and deployment complete. Application is ready in %BUILD_DIR%\release
pause
