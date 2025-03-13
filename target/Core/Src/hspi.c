/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    hspi.c
  * @brief   This file provides code for the configuration
  *          of the HSPI instances.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "hspi.h"

/* USER CODE BEGIN 0 */
#include "mx66uw1g45g.h"


int32_t HSPI_NOR_demo (void);

/* USER CODE END 0 */

XSPI_HandleTypeDef hxspi1;

/* HSPI1 init function */
void MX_HSPI1_Init(void)
{

  /* USER CODE BEGIN HSPI1_Init 0 */

  /* USER CODE END HSPI1_Init 0 */

  /* USER CODE BEGIN HSPI1_Init 1 */

  /* USER CODE END HSPI1_Init 1 */
  hxspi1.Instance = HSPI1;
  hxspi1.Init.FifoThresholdByte = 4;
  hxspi1.Init.MemoryMode = HAL_XSPI_SINGLE_MEM;
  hxspi1.Init.MemoryType = HAL_XSPI_MEMTYPE_MACRONIX;
  hxspi1.Init.MemorySize = HAL_XSPI_SIZE_1GB;
  hxspi1.Init.ChipSelectHighTimeCycle = 2;
  hxspi1.Init.FreeRunningClock = HAL_XSPI_FREERUNCLK_DISABLE;
  hxspi1.Init.ClockMode = HAL_XSPI_CLOCK_MODE_0;
  hxspi1.Init.WrapSize = HAL_XSPI_WRAP_NOT_SUPPORTED;
  hxspi1.Init.ClockPrescaler = 0;
  hxspi1.Init.SampleShifting = HAL_XSPI_SAMPLE_SHIFT_NONE;
  hxspi1.Init.DelayHoldQuarterCycle = HAL_XSPI_DHQC_DISABLE;
  hxspi1.Init.ChipSelectBoundary = HAL_XSPI_BONDARYOF_NONE;
  hxspi1.Init.MaxTran = 0;
  hxspi1.Init.Refresh = 0;
  if (HAL_XSPI_Init(&hxspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN HSPI1_Init 2 */

  // if (HSPI_NOR_demo() != 0)
  // {
  //   Error_Handler();
  // }

  // // Reset flash
  // MX66UW1G45G_ResetEnable(&hxspi1, MX66UW1G45G_SPI_MODE, MX66UW1G45G_STR_TRANSFER);
  // MX66UW1G45G_ResetMemory(&hxspi1, MX66UW1G45G_SPI_MODE, MX66UW1G45G_STR_TRANSFER);
  // HAL_Delay(MX66UW1G45G_RESET_MAX_TIME);
  
  // /* Enable write operations */
  // MX66UW1G45G_WriteEnable(&hxspi1, MX66UW1G45G_SPI_MODE, MX66UW1G45G_STR_TRANSFER);

  // /* Write Configuration register 2 (with new dummy cycles) */
  // MX66UW1G45G_WriteCfg2Register(&hxspi1, MX66UW1G45G_SPI_MODE, MX66UW1G45G_STR_TRANSFER, MX66UW1G45G_CR2_REG3_ADDR, MX66UW1G45G_CR2_DC_6_CYCLES);

  // /* Enable write operations */
  // MX66UW1G45G_WriteEnable(&hxspi1, MX66UW1G45G_SPI_MODE, MX66UW1G45G_STR_TRANSFER);

  // /* Write Configuration register 2 (with Octal I/O SPI protocol) */
  // MX66UW1G45G_WriteCfg2Register(&hxspi1, MX66UW1G45G_SPI_MODE, MX66UW1G45G_STR_TRANSFER, MX66UW1G45G_CR2_REG1_ADDR, MX66UW1G45G_CR2_DOPI);

  // /* Wait that the configuration is effective and check that memory is ready */
  // HAL_Delay(MX66UW1G45G_WRITE_REG_MAX_TIME);
  
  // MX66UW1G45G_EnableDTRMemoryMappedMode(&hxspi1, MX66UW1G45G_OPI_MODE);


  // TODO test memory
    // // Self-test: Write, Read and Verify
    // uint8_t writeData[256], readData[256];
    // uint32_t testAddr = 0x000000; // Test address in flash

    // // Read back data
    // MX66UW1G45G_ReadDTR(&hxspi1, readData, testAddr, 256);
    
    // // Fill write buffer with a test pattern
    // for (int i = 0; i < 256; i++)
    // {
    //   writeData[i] = (uint8_t)i;
    // }
    
    // // Enable write operations
    // MX66UW1G45G_WriteEnable(&hxspi1, MX66UW1G45G_OPI_MODE, MX66UW1G45G_DTR_TRANSFER);
    
    // // Erase sector before writing
    // MX66UW1G45G_BlockErase(&hxspi1, MX66UW1G45G_OPI_MODE, MX66UW1G45G_DTR_TRANSFER, 
    //                        MX66UW1G45G_4BYTES_SIZE, testAddr, MX66UW1G45G_ERASE_4K);
    // HAL_Delay(MX66UW1G45G_BLOCK_4K_ERASE_MAX_TIME);
    
    // // Write test data
    // MX66UW1G45G_PageProgramDTR(&hxspi1, writeData, testAddr, 256);
    // HAL_Delay(10);
    
    // // Read back data
    // MX66UW1G45G_ReadDTR(&hxspi1, readData, testAddr, 256);
    
    // // Verify the data
    // for (int i = 0; i < 256; i++)
    // {
    //   if (readData[i] != writeData[i])
    //   {
    //     Error_Handler(); // Memory test failed
    //   }
    // }

  /* USER CODE END HSPI1_Init 2 */

}

void HAL_XSPI_MspInit(XSPI_HandleTypeDef* xspiHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};
  if(xspiHandle->Instance==HSPI1)
  {
  /* USER CODE BEGIN HSPI1_MspInit 0 */

  /* USER CODE END HSPI1_MspInit 0 */

  /** Initializes the peripherals clock
  */
    PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_HSPI;
    PeriphClkInit.HspiClockSelection = RCC_HSPICLKSOURCE_SYSCLK;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
    {
      Error_Handler();
    }

    /* HSPI1 clock enable */
    __HAL_RCC_HSPI1_CLK_ENABLE();

    __HAL_RCC_GPIOH_CLK_ENABLE();
    __HAL_RCC_GPIOI_CLK_ENABLE();
    /**HSPI1 GPIO Configuration
    PH9     ------> HSPI1_NCS
    PH10     ------> HSPI1_IO0
    PH11     ------> HSPI1_IO1
    PH12     ------> HSPI1_IO2
    PH13     ------> HSPI1_IO3
    PH14     ------> HSPI1_IO4
    PH15     ------> HSPI1_IO5
    PI0     ------> HSPI1_IO6
    PI1     ------> HSPI1_IO7
    PI2     ------> HSPI1_DQS0
    PI3     ------> HSPI1_CLK
    */
    GPIO_InitStruct.Pin = GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12
                          |GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF8_HSPI1;
    HAL_GPIO_Init(GPIOH, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF8_HSPI1;
    HAL_GPIO_Init(GPIOI, &GPIO_InitStruct);

  /* USER CODE BEGIN HSPI1_MspInit 1 */

  /* USER CODE END HSPI1_MspInit 1 */
  }
}

void HAL_XSPI_MspDeInit(XSPI_HandleTypeDef* xspiHandle)
{

  if(xspiHandle->Instance==HSPI1)
  {
  /* USER CODE BEGIN HSPI1_MspDeInit 0 */

  /* USER CODE END HSPI1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_HSPI1_CLK_DISABLE();

    /**HSPI1 GPIO Configuration
    PH9     ------> HSPI1_NCS
    PH10     ------> HSPI1_IO0
    PH11     ------> HSPI1_IO1
    PH12     ------> HSPI1_IO2
    PH13     ------> HSPI1_IO3
    PH14     ------> HSPI1_IO4
    PH15     ------> HSPI1_IO5
    PI0     ------> HSPI1_IO6
    PI1     ------> HSPI1_IO7
    PI2     ------> HSPI1_DQS0
    PI3     ------> HSPI1_CLK
    */
    HAL_GPIO_DeInit(GPIOH, GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12
                          |GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15);

    HAL_GPIO_DeInit(GPIOI, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);

  /* USER CODE BEGIN HSPI1_MspDeInit 1 */

  /* USER CODE END HSPI1_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */
















/* USER CODE END 1 */
