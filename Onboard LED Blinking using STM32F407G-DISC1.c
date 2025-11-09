/* USER CODE BEGIN Header */
 /**
 ******************************************************************************
 * @file : main.c
 * @brief : Blink onboard LEDs (PD12, PD13, PD14, PD15)
 ******************************************************************************
 * @attention
 * Compatible Board: STM32F407G-DISC1
 ******************************************************************************
 */
 /* USER CODE END Header */
 /* Includes------------------------------------------------------------------*/
 #include "main.h"
 /* Private function prototypes-----------------------------------------------*/
 void SystemClock_Config(void);
 static void MX_GPIO_Init(void);
 int main(void)
 {
 /* MCU Configuration--------------------------------------------------------*/
 HAL_Init();
 SystemClock_Config();
 MX_GPIO_Init();
 /* Infinite loop */
 while (1)
 {
 // Blink PD12 (Green)
 HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
 HAL_Delay(200);
 HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
 HAL_Delay(200);
 // Blink PD13 (Orange)
 HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
 HAL_Delay(200);
 HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
 HAL_Delay(200);
 // Blink PD14 (Red)
 HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
 HAL_Delay(200);
 HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
 HAL_Delay(200);
 // Blink PD15 (Blue)
 HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
 HAL_Delay(200);
 HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
 HAL_Delay(200);
 }
 }
 /* System Clock Configuration */
 void SystemClock_Config(void)
 {
 RCC_OscInitTypeDef RCC_OscInitStruct = {0};
 RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
 __HAL_RCC_PWR_CLK_ENABLE();
 __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
 RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
 RCC_OscInitStruct.HSIState = RCC_HSI_ON;
 RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
 RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
 RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
 RCC_OscInitStruct.PLL.PLLM = 16;
 RCC_OscInitStruct.PLL.PLLN = 336;
 RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
 RCC_OscInitStruct.PLL.PLLQ = 7;
 if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
 Error_Handler();
 RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
 | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
 RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
 RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
 RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
 RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
 if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
 Error_Handler();
 }
 /* GPIO Initialization Function */
 static void MX_GPIO_Init(void)
 {
 GPIO_InitTypeDef GPIO_InitStruct = {0};
 /* GPIO Ports Clock Enable */
 __HAL_RCC_GPIOD_CLK_ENABLE();
 /* Configure PD12, PD13, PD14, PD15 as output */
 GPIO_InitStruct.Pin = GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
 GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
 GPIO_InitStruct.Pull = GPIO_NOPULL;
 GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
 HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
 /* Start with all LEDs OFF */
 HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15, GPIO_PIN_RESET);
 }
 /* Error Handler */
 void Error_Handler(void)
 {
 while (1)
 {
 // Blink PD14 (Red LED) fast if error occurs
 HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
 HAL_Delay(100);
 }
 }
