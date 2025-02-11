#include <app.h>
#include <logger.h>
#include <main.h>

void app_setup() {
    logger_setup();
}

void app_loop() {
    HAL_GPIO_TogglePin(RED_LED_GPIO_Port, RED_LED_Pin);
    HAL_Delay(250);
    RTT_Read();
}