#include <logger.h>
#include <stm_log.h>
#include <stdio.h>

#include <usart.h>
#include <SEGGER_RTT.h>

// extern UART_HandleTypeDef huart1;

static const char TAG[] = "Logger";


int __io_putchar(int ch) {
	if(ch == '\n') {
		const char ch_r = '\r';
		// HAL_UART_Transmit(&huart1, (uint8_t *)&ch_r, 1, HAL_MAX_DELAY);
		SEGGER_RTT_Write(0, (const void *)&ch_r, 1);
	}
	// HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
	SEGGER_RTT_Write(0, (const void *)&ch, 1);
	return ch;
}


void logger_setup() {
	SEGGER_RTT_ConfigUpBuffer(0, NULL, NULL, 0, SEGGER_RTT_MODE_NO_BLOCK_SKIP);
    SEGGER_RTT_WriteString(0, "Hello, J-Link RTT!\r\n");
    SEGGER_RTT_WriteString(0, "Heasdllo, J-Link RTasdasdT!\r\n");

    STM_LOGI(TAG, "Logger initialized!");  
    STM_LOGW(TAG, "Logger initialized!");  
    STM_LOGE(TAG, "Logger initialized!");   
}

void RTT_Read(void) {
	char input;
	uint32_t size = 0;
	do {
		size = SEGGER_RTT_Read(0, &input, 1u);
		if (size > 0) {
			SEGGER_RTT_printf(0, "%c", input);
		}
	} while (size > 0);
}