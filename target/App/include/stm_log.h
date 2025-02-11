#pragma once

#include <stdio.h>
#include <stm32u5xx_hal.h>

// ANSI escape codes for text color
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_GRAY    "\x1b[90m"

// Define log levels
#define STM_LOG_LEVEL_DEBUG 0
#define STM_LOG_LEVEL_INFO  1
#define STM_LOG_LEVEL_WARN  2
#define STM_LOG_LEVEL_ERROR 3

// Set the desired log level (adjust as needed)
#ifndef STM_LOG_LEVEL
#define STM_LOG_LEVEL STM_LOG_LEVEL_INFO
#endif

// Define the logging macro
#define _LOG(sym, level, tag, color, format, ...) \
    do { \
        if (level >= STM_LOG_LEVEL) { \
            printf(color sym " [%lu %s] " format ANSI_COLOR_RESET "\n", HAL_GetTick(), tag, ##__VA_ARGS__); \
        } \
    } while (0)

// Define log macros for different log levels
#define STM_LOG(tag, format, ...)  _LOG(" ", STM_LOG_LEVEL_INFO,  tag, ANSI_COLOR_RESET,  format, ##__VA_ARGS__)
#define STM_LOGD(tag, format, ...) _LOG("D", STM_LOG_LEVEL_DEBUG, tag, ANSI_COLOR_BLUE,   format, ##__VA_ARGS__)
#define STM_LOGI(tag, format, ...) _LOG("I", STM_LOG_LEVEL_INFO,  tag, ANSI_COLOR_GREEN,  format, ##__VA_ARGS__)
#define STM_LOGIM(tag, format, ...) _LOG("I", STM_LOG_LEVEL_INFO,  tag, ANSI_COLOR_MAGENTA,  format, ##__VA_ARGS__)
#define STM_LOGIC(tag, format, ...) _LOG("I", STM_LOG_LEVEL_INFO,  tag, ANSI_COLOR_CYAN,  format, ##__VA_ARGS__)
#define STM_LOGIG(tag, format, ...) _LOG("I", STM_LOG_LEVEL_INFO,  tag, ANSI_COLOR_GRAY,  format, ##__VA_ARGS__)
#define STM_LOGIB(tag, format, ...) _LOG("I", STM_LOG_LEVEL_INFO,  tag, ANSI_COLOR_BLUE,  format, ##__VA_ARGS__)
#define STM_LOGW(tag, format, ...) _LOG("W", STM_LOG_LEVEL_WARN,  tag, ANSI_COLOR_YELLOW, format, ##__VA_ARGS__)
#define STM_LOGE(tag, format, ...) _LOG("E", STM_LOG_LEVEL_ERROR, tag, ANSI_COLOR_RED,    format, ##__VA_ARGS__)
