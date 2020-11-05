/**
  ******************************************************************************
  * File Name          : STM32TouchController.cpp
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

/* USER CODE BEGIN STM32TouchController */

#include <STM32TouchController.hpp>
#include <TouchGFXHAL.hpp>
#include <ft5336.h>
#include <stm32f7xx_hal.h>
#include <touchgfx/hal/OSWrappers.hpp>
#include <stm32746g_discovery_ts.h>

static TS_DrvTypeDef* tsDriver;
extern I2C_HandleTypeDef hi2c3;

void STM32TouchController::init()
{
    /* Initialize the TS driver structure */
    tsDriver = &ft5336_ts_drv;

    /* Initialize the TS driver */
    tsDriver->Start(TS_I2C_ADDRESS);
}

bool STM32TouchController::sampleTouch(int32_t& x, int32_t& y)
{
    /* Checking if the screen has been touched */

    if (tsDriver)
    {
        if (tsDriver->DetectTouch(TS_I2C_ADDRESS))
        {
            /* Get each touch coordinates */
            tsDriver->GetXY(TS_I2C_ADDRESS, (uint16_t*)&y, (uint16_t*)&x);
            return true;
        }
    }
    return false;
}

/* USER CODE END STM32TouchController */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/