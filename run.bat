@echo off
echo ====================================================
echo COMPILING
g++ main.cpp -o main.exe ./renderer/printer/printer.cpp ./renderer/global/global.cpp ./renderer/scene/scene.cpp ./src/utils.cpp ./src/word.cpp ./src/tree.cpp ./src/dictionary.cpp ./src/gameManager.cpp
echo COMPILE COMPLETE 
echo ====================================================
@REM cls

echo RUNNING main.exe
main.exe
echo ====================================================


@echo on