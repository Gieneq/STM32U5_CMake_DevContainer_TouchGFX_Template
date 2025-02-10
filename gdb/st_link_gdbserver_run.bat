@echo off
cmd /K "ST-LINK_gdbserver.exe -c st_link_gdbserver_config.txt || echo GDB server exited"
