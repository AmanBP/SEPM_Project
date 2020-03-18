@echo off
cd ../Program/
setlocal enabledelayedexpansion
dir /b *.cpp  > ../Builder/filelist.txt
set "command=g++ "
set "part2= -l sqlite3"
@echo off
for /f "delims=" %%a in (../Builder/filelist.txt) DO (set "command=!command! %%a")
set command=!command!!part2!
echo Running : !command!
echo Please Wait..........
call !command!
echo Done, want to run program?
set /p yesno="Yes(y) or No(n):"
if "%yesno%"=="y" (
	start a.exe)
echo Done.
cd ../Builder/