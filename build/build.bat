@echo off
set PATH=%PATH%;C:\Program Files (x86)\MSBuild\12.0\Bin
MSBuild "template_project.sln" /p:Configuration=Release /nologo /verbosity:m

echo.
if ERRORLEVEL 0 echo Build Success
if not ERRORLEVEL 0 echo Build Failed

timeout 100
