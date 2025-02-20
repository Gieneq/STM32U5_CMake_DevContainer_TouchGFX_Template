cmake_minimum_required(VERSION 3.22)
cmake_policy(SET CMP0135 NEW)
#
# This file is generated only once,
# and is not re-generated if converter is called multiple times.
#
# User is free to modify the file as much as necessary
#

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)


# Define the build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# Set the project name
set(CMAKE_PROJECT_NAME tmplatemkfileu5dk)
message("Build: " ${CMAKE_PROJECT_NAME})

# Define paths for NemaGFX and TouchGFXNema
set(NEMAGFX_ROOT "components/touchgfx_components/gpu2d/NemaGFX")
message("NEMAGFX_ROOT " ${TOUCHGFX_MIDDLEWARE_ROOT})

set(TOUCHGFXNEMA_ROOT "components/touchgfx_components/gpu2d/TouchGFXNema")
message("TOUCHGFXNEMA_ROOT " ${TOUCHGFX_MIDDLEWARE_ROOT})

set(TOUCHGFX_MIDDLEWARE_ROOT "Middlewares/ST/touchgfx")
message("TOUCHGFX_MIDDLEWARE_ROOT " ${TOUCHGFX_MIDDLEWARE_ROOT})

set(TOUCHGFX_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/TouchGFX")
set(TOUCHGFX_TARGET_DIR "${TOUCHGFX_ROOT}/target")
set(TOUCHGFX_GENERATED_DIR "${TOUCHGFX_ROOT}/generated")
set(TOUCHGFX_GUI_DIR "${TOUCHGFX_ROOT}/gui")
message("Touchgfx gui located in " ${TOUCHGFX_GUI_DIR})



# Include toolchain file
include("cmake/gcc-arm-none-eabi.cmake")

# Enable compile command to ease indexing with e.g. clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# Enable CMake support for ASM and C languages
enable_language(C ASM)

# Core project settings
project(${CMAKE_PROJECT_NAME})
message("Build type: " ${CMAKE_BUILD_TYPE})

# Create an executable object type
add_executable(${CMAKE_PROJECT_NAME})

# Add STM32CubeMX generated sources
add_subdirectory(cmake/stm32cubemx)

# Link directories setup
target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined library search paths
    ${NEMAGFX_ROOT}/lib/core/cortex_m33/gcc
    ${TOUCHGFXNEMA_ROOT}/lib/cortex_m33/gcc
    ${TOUCHGFX_MIDDLEWARE_ROOT}/lib/core/cortex_m33/gcc
)

# Find all touchgfx source files
file(GLOB TOUCHGFX_GENERATED_FONTS_SOURCES "${TOUCHGFX_GENERATED_DIR}/fonts/src/*.cpp")

# Guis has some sub dirs
file(GLOB TOUCHGFX_GENERATED_GUI_SOURCES "${TOUCHGFX_GENERATED_DIR}/gui_generated/src/*/*.cpp")

# Images
file(GLOB TOUCHGFX_GENERATED_IMAGES_SOURCES "${TOUCHGFX_GENERATED_DIR}/images/src/*.cpp")
file(GLOB TOUCHGFX_GENERATED__GENERATED_IMAGES_SOURCES "${TOUCHGFX_GENERATED_DIR}/images/src/__generated/*.cpp")
# /workspaces/STM32U5_CMake_DevContainer_TouchGFX_Template/target/TouchGFX/generated/images/src/__generated

# Texts
file(GLOB TOUCHGFX_GENERATED_TEXTS_SOURCES "${TOUCHGFX_GENERATED_DIR}/texts/src/*.cpp")

# Videos dir has bin files
file(GLOB TOUCHGFX_GENERATED_VIDEOS_OBJS "${TOUCHGFX_GENERATED_DIR}/videos/obj/*.bin.o")

# Guis has some sub dirs
file(GLOB TOUCHGFX_GUI_SOURCES "${TOUCHGFX_GUI_DIR}/src/*/*.cpp")
message("Found TouchGFX font sources: ${TOUCHGFX_GUI_SOURCES}")

# Add sources to executable
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user sources here
    "App/app.c"
    "App/logger.c"

    "components/rtt/SEGGER_RTT_printf.c"
    "components/rtt/SEGGER_RTT_Syscalls_GCC.c"
    "components/rtt/SEGGER_RTT.c"

    # Automatically add generated sources
    ${TOUCHGFX_GENERATED_FONTS_SOURCES}
    ${TOUCHGFX_GENERATED_GUI_SOURCES}
    ${TOUCHGFX_GENERATED_IMAGES_SOURCES}
    ${TOUCHGFX_GENERATED__GENERATED_IMAGES_SOURCES}
    ${TOUCHGFX_GENERATED_TEXTS_SOURCES}
    ${TOUCHGFX_GENERATED_VIDEOS_SOURCES}
    ${TOUCHGFX_GUI_SOURCES}
    
    ${TOUCHGFX_GENERATED_VIDEOS_OBJS}
)

# Add include paths
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined include paths
    "App/include"
    
    "components/rtt/include"

    ${NEMAGFX_ROOT}/include
    ${TOUCHGFXNEMA_ROOT}/include
    ${TOUCHGFXNEMA_ROOT}/include/touchgfx_nema
    
    ${TOUCHGFX_MIDDLEWARE_ROOT}/framework/include  # ✅ Add TouchGFX framework
    ${TOUCHGFX_MIDDLEWARE_ROOT}/3rdparty/libjpeg/include  # ✅ Add TouchGFX libjpeg

    ${TOUCHGFX_GENERATED_DIR}/fonts/include
    ${TOUCHGFX_GENERATED_DIR}/gui_generated/include
    ${TOUCHGFX_GENERATED_DIR}/images/include
    ${TOUCHGFX_GENERATED_DIR}/texts/include
    ${TOUCHGFX_GENERATED_DIR}/videos/include

    ${TOUCHGFX_GUI_DIR}/include
)
# Debug: Print include directories
get_target_property(INCLUDE_DIRS ${CMAKE_PROJECT_NAME} INCLUDE_DIRECTORIES)
message("Include directories: ${INCLUDE_DIRS}")

# Add project symbols (macros)
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined symbols
    USE_HARD_FLOAT=1
)

# Add linked libraries
target_link_libraries(${CMAKE_PROJECT_NAME}
    stm32cubemx

    # Add user defined libraries
    nemagfx-float-abi-hard
    touchgfxnema-float-abi-hard

    # TouchGFX Middleware
    touchgfx-float-abi-hard  # ✅ Add TouchGFX core library
)
