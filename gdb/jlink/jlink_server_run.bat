@echo off
call jlink_config.bat
"%JLINK_PATH%\JLinkGDBServer.exe" -device STM32U5G9ZJ -if SWD -speed 4000 -port 61234 -log ".\jlink_log.txt"
