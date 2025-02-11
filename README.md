# STM32U5 template

Main MCU (STM32U5G9ZJT6Q)[https://www.st.com/en/microcontrollers-microprocessors/stm32u5g9zj.html] 

## Features
Features:
- host unit tests: see *tasks.json* or *test icons* on status bar,
- target build, upload and debug: see *tasks.json*, *launch.json* and *icons* on status bar,
- CubeMX version: 6.13.0


## Setup
Project should work out of box. Admin is must-have for running Docker and VS Code.

- install GDB server (STM32CubeProgrammer for ST-Link or JLink)
- install VS Code
- install CubeMX
- install WSL2
- install [Docker Desktop](https://www.docker.com/products/docker-desktop/)
- clone project `git clone todo`
- run Docker Desktop as admin
- in VS Code open folder with project
- in bottom-left corner with remote options left click and select `reopen in container`
- click newly opened popup if you wish to monitor progress, it will take severa lminutes to setup
- if done successfully open terminal `ctrl + shift + ~` and do what you want in this brand new fancy linux stuff. Check if you have arm compiler: `ls /usr/bin | grep arm-none-eabi`
- noiz 🔥 You have hopefully portable project.

## Usage
To write code which will be cross-platform thus can be tested separatelly on host use (host)[./host] directory. Target application is placed in (target)[./target] dir. Before you upload/debug you app you need to start GDB server, just run on windows host machine [gdb/st_link_gdbserver_run.bat](./gdb/st_link_gdbserver_run.bat) or [jlink_server_run.bat](./gdb/jlink/jlink_server_run.bat). In case of STLink dont be fooled it is so easy, it is still embedded world - from time to time you will have to restart the GBD server because of some unknown bugs. Happy coding though.
To star debug your code hit fancy bugy trinagle located in activity bar, then hit grin triangle related to your debugger to see you code stopped at breakpoint. If you made any changes in your code before debugging it will be rebuilt using cmake.

Check [c_cpp_properties.json](./vscode/c_cpp_properties.json) to see 2 types of configurations: host and target. You can switch between them using bottom right status bar button.

Step by step:
1. Generate code using CubeMX (windows side),
2. Start GDB server,
3. Reopen project in container,
4. Hit `Ctrl + Shift + B` or click fancy bottom status bar icon called `Build`,
5. Do debugging or just upload with fancy `Upload` button on your favourite status bar.

Code not ompiling without any reason. Clean it with fancy `Clean` button! Or just target/discard build dir. Still not working? Check `git diff` and see what got messed up.

## Even further
Want to add custom tasks and debbuging, edit tassk or launch jsons.

## JLink
Update JLink firmware with `JLinkConfig`. Then run `JLink.exe` and try connect to target - type `connect cortex-m33` and proceed with dialogs. Find if your JLink support caches.