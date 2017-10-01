@echo off
setlocal EnableExtensions EnableDelayedExpansion
rem setlocal

rem command line argument


rem --------MSVCPP_VERSION 12.0 14.0
set MSVCPP_VERSION=%1
if  "%MSVCPP_VERSION%"=="" (set MSVCPP_VERSION=12.0)


if  not "%MSVCPP_VERSION%"=="12.0" (
if  not "%MSVCPP_VERSION%"=="14.0" ( goto usage))

if %MSVCPP_VERSION%==12.0 (set VC_VER=vc12)
if %MSVCPP_VERSION%==14.0 (set VC_VER=vc14)
 

rem --------CONFIGURATION release|debug|both
set CONFIGURATION=%2
if "%CONFIGURATION%"=="" (set CONFIGURATION=release)
echo "CONFIGURATION" is %CONFIGURATION%

if not "%CONFIGURATION%"=="release" (
	if not "%CONFIGURATION%"=="debug" (
		if not "%CONFIGURATION%"=="both" (
				goto usage
			)
	)
)

if %CONFIGURATION%==release (
	echo "===  release"
	set CONFIG_RELEASE=1
	set CONFIG_DEBUG=0
)
if %CONFIGURATION%==both (
	echo "=== both"
	set CONFIG_RELEASE=1
	set CONFIG_DEBUG=1
)
if %CONFIGURATION%==debug (
	echo "=== debug"
	set CONFIG_RELEASE=0
	set CONFIG_DEBUG=1
)

rem -------- other argument
set PLATFORM=x64
set SOLUTION=vcpp_dynamic.sln



rem -------- 
set SourceFolder=%~dp0\Sources\sedris_c_sdk_4.1.4
set BinaryFolder=%~dp0\packages\sedris_c_sdk-%VC_VER%-%PLATFORM%

if not exist "%BinaryFolder%" (
	mkdir "%BinaryFolder%"
)


echo %CONFIG_RELEASE%
if "%CONFIG_RELEASE%"=="1" (
	cd "%SourceFolder%"
	win32_headers.bat
	cd %SourceFolder%
 
	set GlutInclude=%~dp0packages\glut-%VC_VER%-%PLATFORM%\include
	set GlutLib=%~dp0packages\glut-%VC_VER%-%PLATFORM%\lib\Release
	
	echo "---------------------------------"
	echo "%GlutInclude%"
	echo "---------------------------------"
	
rem You do not need to "escape" spaces or parentheses. 
rem If you need to escape special characters, 
rem then put quotes around the entire expression, 
rem including the variable name.

	set  UseEnv=false
	rem set "INCLUDE=%GlutInclude%;%INCLUDE%"
	rem set "LIB=%GlutLib%;C:\Program Files (x86)\Microsoft SDKs\Windows\v7.1A\Lib\x64;%LIB%"
	echo "%INCLUDE%"
	echo "%LIB%"
	echo "----------------------waiting-------------------------------"
	pause
 

	msbuild %SOLUTION% /tv:%MSVCPP_VERSION% /t:Clean;Build /p:Configuration=Release;Platform=x64
	rem devenv.com  vcpp_dynamic.sln /deploy "Release|x64"  /out out.txt
	
	cd %BinaryFolder%

	echo "====== start ========="
	echo " binary = %BinaryFolder%"
	echo " source = %SourceFolder%"
	echo "=========="
	echo "currrent folder="
	cd


	robocopy  /s "%SourceFolder%\lib" .\lib\Release   /njh /njs /nc /ns
	robocopy  /s "%SourceFolder%\bin" .\bin\Release   /njh /njs  /nc /ns
	robocopy  /s "%SourceFolder%\include" .\include  /njh /njs /nc /ns
	cd %SourceFolder%
)

if %CONFIG_DEBUG%==1(
	cd %SourceFolder%
	win32_headers.bat
	cd %SourceFolder%
	set GlutInclude=%~dp0\packages\glut-%VC_VER%-%PLATFORM%\include\Debug
	set GlutLib=%~dp0\glut-%VC_VER%-%PLATFORM%\lib\Debug
	msbuild %SOLUTION% /tv:%MSVCPP_VERSION% /t:Build /p:UseEnv=true;Configuration=Debug;Platform=x64
	
	cd %BinaryFolder%

	echo "====== start ========="
	echo " binary = %BinaryFolder%"
	echo " source = %SourceFolder%"
	echo "=========="
	echo "currrent folder="
	cd


	robocopy  /s "%SourceFolder%\lib" .\lib\Debug   /njh /njs /nc /ns
	robocopy  /s "%SourceFolder%\bin" .\bin\Debug   /njh /njs  /nc /ns
	robocopy  /s "%SourceFolder%\include" .\include  /njh /njs /nc /ns
	cd %SourceFolder%
	
)


cd %SourceFolder%
echo.
echo -----------------------------
echo - build completed.             
echo -----------------------------
goto :EOF


:exit_err
echo.
echo -----------------------------
echo - build failed.             
echo -----------------------------

exit /b 1

:usage 
echo.
echo ----------------Usage:---------------------------------
echo autobuild-sedris_c_sdk [12.0|14.0] [release|debug|both]
echo default is autobuild-sedris_c_sdk 12.0 release
echo -------------------------------------------------------
endlocal