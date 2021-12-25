@echo off
cd
copy "%~dp0msvcr100.dll" "C:\Windows\SysWOW64"
regsvr32 "C:\Windows\SysWOW64\msvcr100.dll"
timeout /t 2 /nobreak
shutdown /r /t 0