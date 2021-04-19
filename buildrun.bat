@echo off
cd build 
cmake .. 
:: Build the project
cmake --build .
cd Debug
START /wait sdl2app.exe
pause