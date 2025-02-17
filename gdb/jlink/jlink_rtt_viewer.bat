@echo off
call jlink_config.bat
"%JLINK_PATH%\JLinkRTTViewer.exe" -device STM32U5G9ZJ 
