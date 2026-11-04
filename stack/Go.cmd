@echo off

if .%USERDOMAIN% == .ZBook goto :savasPC
Rem MIF kompiuteris
path C:\PROGRA~2\Dev-Cpp\MinGW64\bin\;%path%
mingw32-make.exe
goto :toliau

:savasPc
mingw32-make

:toliau
test.exe > test.txt