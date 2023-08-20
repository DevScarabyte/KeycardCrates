@ECHO OFF
setlocal EnableDelayedExpansion
for %%a in ("%~dp0\.") do set "modfoler=%%~nxa"
for %%i in ("%~dp0..") do set "parent=%%~fi"
set pboproject=C:\Program Files (x86)\Mikero\DePboTools\bin\pboProject.exe
echo %parent%
echo %folder%
"%pboProject%" -P -L="%modfoler%Client" +mod="%parent%%modfoler%" "%__CD__%Client"
"%pboProject%" -P -L="%modfoler%Server" +mod="%parent%%modfoler%" "%__CD__%Server" 

endlocal
pause