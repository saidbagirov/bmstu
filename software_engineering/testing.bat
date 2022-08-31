@echo off
main.exe in_0%1.txt out.txt
fc out.txt out_0%1.txt
pause