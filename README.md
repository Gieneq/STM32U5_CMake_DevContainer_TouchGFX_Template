# STM32U5 template

Easy (hopefully) to setup and use project template of STM32U5 with TouchGFX built with CMake on Docker. Works with STLink and JLink. Main MCU [STM32U5G9ZJT6Q](https://www.st.com/en/microcontrollers-microprocessors/stm32u5g9zj.html), related Discovery board STM32U5G9J-DK2.

## Features 📦
Features:
- Dev Container
- Host Google Tests
- Target build, flash, debug
- CubeMX version: 6.13.0
- TouchGFX 4.24.2
- CMake
- JLink RTT

## Quickstart (JLink) 🚀
First steps will explain setup tooling, the remaining ones will explain tools and test programming capabilities:
- Install:
  * [WSL2](https://learn.microsoft.com/en-us/windows/wsl/install)
  * [Segger JLink](https://www.segger.com/downloads/jlink/)
  * [Docker Desktop](https://www.docker.com/products/docker-desktop/)
  * [CubeMX 6.13.0](https://www.st.com/en/development-tools/stm32cubemx.html)
  * [TouchGFX 4.24.2](https://www.st.com/en/development-tools/touchgfxdesigner.html)
- Run **Docker Desktop** as admin.
- Open **VS Code** as admin.
- Run in **Git Bash** `git clone https://github.com/Gieneq/STM32U5_CMake_DevContainer_TouchGFX_Template.git` Caution! After entering container you will change git user. At best use Git Bash or commit changes after closing remote connection, then VS Code revert windows side git user. Using docker side git user can cause multiuser problems.
- In VS Code open folder with project.
- In VS Code **reopen folder in container**, can be prompted, if not, hit **bottom-left** `Remote Connection` button and select `reopen in container`
- If prompted `Reload window` especially because **Cortex-Debug** extension. Ignore Git related warnings.
- Check your new fancy linux container:
  * Hit `Ctrl + Shift + ~` to open new terminal.
  * Run `ls /usr/bin | grep arm-none-eabi` to see if you have required tools
- Modify **jlink_config.bat** file with path to JLink.
- Open JLink server on windows side [./gdb/jlink/jlink_server_run.bat](./gdb/jlink/jlink_server_run.bat)
- Open JLink RTT viewer to monitor logs [./gdb/jlink/jlink_rtt_viewer.bat](./gdb/jlink/jlink_rtt_viewer.bat)
- Examin bottom **Status Bar** with some super fancy buttons:
  * `🧪 Regenerate`, `🧪 Build & Test` are used to tests multiplatform feature on host using Google Tests, best for quick testing small features without involving target firmware,
  * `📂 Regenerate`, `📂 Build`, `⚡ Build & Flash JLink` are used to build & run on target. Note! `📂 Build & Flash JLink` will flash firmware but JLink will halt code. Use `🔎 Monitor` button to see code execution.
  * `🔎 Monitor` run RTT client interacting with JLink server. At best use **RTT Viewer** on windows side + **Debug Lauch** instead.
- Check **target** programming capabilities:
  * Hit super fancy button `📂 Regenerate` from **Status Bar** to recreate CMake build folder.
  * Hit `Ctrl+Shift+B` or use super fancy button `📂 Build` from **Status Bar** to build **.elf** file.
  * Exter `Run & Debug` from **Activity Bar** and hit green triangle with Debug JLink, it will flash wirmware and run debugging via windows side GDB server. Note second option **Attach**.
  * Hit continue from navigation bar shown ontop window. By default JLink will halt, also after disconnecting from GDB.
- Check **host** testing capabilities:
  * Hit super fancy button `🧪 Regenerate` from **Status Bar** to recreate CMake build folder.
  * Hit super fancy button `🧪 Build & Test` from **Status Bar** to build **.exe** file and run.

> **_Build note:_** at best `📂 Build` should regenerate CMake. Meybe in future.

> **_Important! Language modes:_** there are 2 modes `Host` & `Target`. Select which one you need in bottom-right corner. If not, IntelliSense will not recognise paths properly. See [./.vscode/c_cpp_properties.json](./.vscode/c_cpp_properties.json).

> **_Reopen locally:_** Want to come back to windows side to commit changes - bottom-left `Remote Connections -> `Reopen Folder Locally`.

> **_Holded firmware:_** Want run firmware freely? Send continue command to GDB or just close GDB.

## Project tour-guide 🗺️
Project is separated into 3 directories:
- [./gdb](./gdb) - location for run servers **.bat** files.
- [./host](./host) - host side tests related subproject.
- [./target](./target) - target side firmware related subproject.

### Directory ./gdb

Here you can find STLink related server and settings. If you use STLink modify `st_link_gdbserver_config.txt` file with path to **STMCubeProgrammer**:
```text
###############################################################
-cp C:\Program Files\STMicroelectronics\STM32Cube\STM32CubeProgrammer\bin\
```
To run STLink server, use on windows side `st_link_gdbserver_run.bat`.

JLink related stuff you will find in Jlink directory. Here you have server, viewer (requiring running server), and viewer log file if created.

If you will use JLink, modify **jlink_config.bat** file with path. Here example of using JLink_V812e:

```text
set JLINK_PATH=C:\SEGGER\JLink_V812e
```

### Directory ./host
Modify CMake to add sources of tests. At first gtest will be unknown in source files, try `Regenerate` so that CMake will download Google Trst framework.

### Directory ./target
If you use CubeMX, newly created files will be automatically added, check [./target/cmake](./target/cmake) dir. 

Use TouchGFX to modify project. Note! probably you will need to modify top level **CMakeLists.txt**.

Top level **CMakeLists.txt** modifications:
- sources add by Glob search to pass content of directory or add individual sources to `target_sources(${CMAKE_PROJECT_NAME} PRIVATE`,
- header files pass to `target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE`
- dir with library files pass here `target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE`, CMake will seek for lib in those dirs to find names from `target_link_libraries`
- lib add in `target_link_libraries(${CMAKE_PROJECT_NAME}`. If lib is from CMake pass its project name, if it is static pass filename.

Development:
- place libraries & shared code in [./target/components](./target/components)
- [./target/Core](./target/Core) shoudl be used for HAL/BSP layer C code.
- [./target/App](./target/App) shoudl be used for application layer code - place buisness logic here.
- [./target/TouchGFX](./target/TouchGFX) HMI related, do not modify generated files like **Base** Views Classes.
- TouchGFX Simulator is turned off in Designer config. In long run it is too much involving to maintaing both target and simulator.

## Todo 📒
Some plans:
- Consider adding integration tests, probably requring remote server or run from windows side.
- External memory loading.

## STM32U5G9J-DK2 (MB1918 board) 🎯
Common pins:
- UART debug:
  * PA9  USART1_TX
  * PA10 USART1_RX
- PC13 Button (nopull, active HIGH)
- PD2  Red LED (active LOW)
- PD4  Green LED (active LOW)

## Troubleshooting 🐛

> **_Fun fact #1:_** CubeMX CMake links sources of ThreadX middleware, minimal setup of TouchGFX, but not links TouchGFX middleware nor generated project parts.

> **_Fun fact #1:_** TouchGFX is not generating Nema lib (Neo ChromArt). Copy-paste it from example, meh!

To see all sections:
arm-none-eabi-size -A /workspaces/combinedtemplate/target/build/tmplatemkfileu5dk.elf

arm-none-eabi-objdump -h /workspaces/combinedtemplate/target/build/tmplatemkfileu5dk.elf
