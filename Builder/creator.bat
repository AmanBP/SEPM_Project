@echo off
setlocal enabledelayedexpansion
echo Deleting filelist.txt if found
IF EXIST *.txt (
    echo filelist.txt found!
    echo Deleting filelist.txt  ....
    DEL /F *.txt
    echo done.
                )
cd ../Program/
echo Stopping a.exe if found running:
TASKLIST|FIND "a.exe" > NUL
@echo off
if %ERRORLEVEL% equ 0 (taskkill /im a.exe /f)
@echo off
echo done.
echo Deleting a.exe if found
IF EXIST a.exe (
    echo a.exe found!
    echo Deleting a.exe  ....
    DEL /F a.exe
    echo done.
                )
IF EXIST a.exe DEL /F a.exe
dir /b *.c*  > ../Builder/filelist.txt
set "command=g++ "
set "part2= ../dependencies/sqlite3.o"
@echo off
for /f "delims=" %%a in (../Builder/filelist.txt) DO (set "command=!command! %%a")
set command=!command!!part2!
echo Running : !command!
echo Please Wait..........
call !command!
echo Done compiling, want to run program?
set /p yesno="Yes(y) or No(n):"
if "%yesno%"=="y" (start a.exe)
call cd ..
call cd Builder
echo Finished!