@echo off
gcc my_functions.c main.c -o main.exe
cls
for %%i in (1 2 3 4 5 6) do call testing.bat %%i