/**
  ******************************************************************************
  * @file          : app_tof.c
  * @author        : IMG SW Application Team
  * @brief         : This file provides code for the configuration
  *                  of the STMicroelectronics.X-CUBE-TOF1.3.3.0 instances.
  ******************************************************************************
  *
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "app_tof.h"
#include "main.h"
#include <stdio.h>
#include <stdbool.h>
#include "custom_ranging_sensor.h"
#include "stm32f4xx_nucleo.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
/* uncomment following to use directly the bare driver instead of the BSP */
/* #define USE_BARE_DRIVER */
#define TIMING_BUDGET (30U) /* 5 ms < TimingBudget < 100 ms */
#define RANGING_FREQUENCY (15U) /* Ranging frequency Hz (shall be consistent with TimingBudget value) */
#define POLLING_PERIOD (1000U/RANGING_FREQUENCY) /* refresh rate for polling mode (milliseconds) */

/* Private variables ---------------------------------------------------------*/

static RANGING_SENSOR_Capabilities_t Cap;
static RANGING_SENSOR_Capabilities_t Cap2;
static RANGING_SENSOR_Capabilities_t Cap3;

static RANGING_SENSOR_ProfileConfig_t Profile;
static RANGING_SENSOR_ProfileConfig_t Profile2;
static RANGING_SENSOR_ProfileConfig_t Profile3;

static RANGING_SENSOR_Result_t Result;
static RANGING_SENSOR_Result_t Result2;
static RANGING_SENSOR_Result_t Result3;

uint32_t Id1,Id2,Id3;

uint16_t TOF2_I2C_ADDRESS = (VL53L5CX_DEFAULT_I2C_ADDRESS +(16+2));
uint16_t TOF3_I2C_ADDRESS = (VL53L5CX_DEFAULT_I2C_ADDRESS +(16+4));

//static int32_t status = 0;
volatile uint8_t ToF_EventDetected = 0;

/* Private function prototypes -----------------------------------------------*/
#ifdef USE_BARE_DRIVER
static uint8_t map_target_status(uint8_t status);
static int32_t convert_data_format(VL53L5CX_Object_t *pObj,
    VL53L5CX_ResultsData *data, RANGING_SENSOR_Result_t *pResult);
#endif
static void MX_VL53L5CX_SimpleRanging_Init(uint32_t Instance);
static void MX_VL53L5CX_SimpleRanging_Process_TOF(void);

static void print_TOF1(RANGING_SENSOR_Result_t *Result);
static void print_TOF2(RANGING_SENSOR_Result_t *Result);
static void print_TOF3(RANGING_SENSOR_Result_t *Result);

//ARA
void MX_TOF_Init(void)
{

	//TOF1
	MX_VL53L5CX_SimpleRanging_Init(CUSTOM_VL53L5CX);//INIT TOF1 ARA

	//TOF2
	MX_VL53L5CX_SimpleRanging_Init(CUSTOM_VL53L5CX2);//INIT TOF2 ARA

	//TOF3
    MX_VL53L5CX_SimpleRanging_Init(CUSTOM_VL53L5CX3);//INIT TOF2 ARA

	CUSTOM_RANGING_SENSOR_SetAddress(CUSTOM_VL53L5CX3, TOF3_I2C_ADDRESS); //changement adresse TOF3
	HAL_Delay(2);
	HAL_GPIO_WritePin(CUSTOM_VL53L5CX_LPn3_PORT, CUSTOM_VL53L5CX_LPn3_PIN, GPIO_PIN_RESET);
	HAL_Delay(2);
	HAL_GPIO_WritePin(CUSTOM_VL53L5CX_LPn2_PORT, CUSTOM_VL53L5CX_LPn2_PIN, GPIO_PIN_SET);

	CUSTOM_RANGING_SENSOR_SetAddress(CUSTOM_VL53L5CX2, TOF2_I2C_ADDRESS); //changement adresse TOF2
	HAL_Delay(2);
	HAL_GPIO_WritePin(CUSTOM_VL53L5CX_LPn3_PORT, CUSTOM_VL53L5CX_LPn3_PIN, GPIO_PIN_SET);
	HAL_Delay(2);
	HAL_GPIO_WritePin(CUSTOM_VL53L5CX_LPn_PORT, CUSTOM_VL53L5CX_LPn_PIN, GPIO_PIN_SET);

	//TOF2 start
	CUSTOM_RANGING_SENSOR_ReadID(CUSTOM_VL53L5CX2, &Id2);
	CUSTOM_RANGING_SENSOR_GetCapabilities(CUSTOM_VL53L5CX2, &Cap2);
	Profile2.RangingProfile = RS_PROFILE_8x8_CONTINUOUS;
	Profile2.TimingBudget = TIMING_BUDGET; /* 5 ms < TimingBudget < 100 ms */
	Profile2.Frequency = RANGING_FREQUENCY; /* Ranging frequency Hz (shall be consistent with TimingBudget value) */
	Profile2.EnableAmbient = 0; /* Enable: 1, Disable: 0 */
	Profile2.EnableSignal = 0; /* Enable: 1, Disable: 0 */
	CUSTOM_RANGING_SENSOR_ConfigProfile(CUSTOM_VL53L5CX2, &Profile2);
	CUSTOM_RANGING_SENSOR_Start(CUSTOM_VL53L5CX2, RS_MODE_BLOCKING_ONESHOT);

	//TOF1 start
	CUSTOM_RANGING_SENSOR_ReadID(CUSTOM_VL53L5CX, &Id1);
	CUSTOM_RANGING_SENSOR_GetCapabilities(CUSTOM_VL53L5CX, &Cap);
	Profile.RangingProfile = RS_PROFILE_8x8_CONTINUOUS;
	Profile.TimingBudget = TIMING_BUDGET; /* 5 ms < TimingBudget < 100 ms */
	Profile.Frequency = RANGING_FREQUENCY; /* Ranging frequency Hz (shall be consistent with TimingBudget value) */
	Profile.EnableAmbient = 0; /* Enable: 1, Disable: 0 */
	Profile.EnableSignal = 0; /* Enable: 1, Disable: 0 */
	CUSTOM_RANGING_SENSOR_ConfigProfile(CUSTOM_VL53L5CX, &Profile);
	CUSTOM_RANGING_SENSOR_Start(CUSTOM_VL53L5CX, RS_MODE_BLOCKING_ONESHOT);

	//TOF3 start
	CUSTOM_RANGING_SENSOR_ReadID(CUSTOM_VL53L5CX3, &Id3);
	CUSTOM_RANGING_SENSOR_GetCapabilities(CUSTOM_VL53L5CX3, &Cap3);
	Profile3.RangingProfile = RS_PROFILE_8x8_CONTINUOUS;
	Profile3.TimingBudget = TIMING_BUDGET; /* 5 ms < TimingBudget < 100 ms */
	Profile3.Frequency = RANGING_FREQUENCY; /* Ranging frequency Hz (shall be consistent with TimingBudget value) */
	Profile3.EnableAmbient = 0; /* Enable: 1, Disable: 0 */
	Profile3.EnableSignal = 0; /* Enable: 1, Disable: 0 */
	CUSTOM_RANGING_SENSOR_ConfigProfile(CUSTOM_VL53L5CX3, &Profile3);
	CUSTOM_RANGING_SENSOR_Start(CUSTOM_VL53L5CX3, RS_MODE_BLOCKING_ONESHOT);

}

/*
 * LM background task
 */
void MX_TOF_Process(void)
{
	MX_VL53L5CX_SimpleRanging_Process_TOF();
}

static void MX_VL53L5CX_SimpleRanging_Init(uint32_t Instance)
{
	int32_t status;

	status = CUSTOM_RANGING_SENSOR_Init(Instance);

    if (status != BSP_ERROR_NONE)
    {
	  printf("CUSTOM_RANGING_SENSOR_Init failed for instance %ld\n", Instance);
	  while(1);
    }
}

#ifdef USE_BARE_DRIVER
static void MX_VL53L5CX_SimpleRanging_Process(void)
{
  VL53L5CX_Object_t *pL5obj = CUSTOM_RANGING_CompObj[CUSTOM_VL53L5CX];
  static VL53L5CX_ResultsData data;
  uint8_t NewDataReady = 0;

  Profile.RangingProfile = RS_PROFILE_8x8_CONTINUOUS;
  Profile.TimingBudget = TIMING_BUDGET; /* 5 ms < TimingBudget < 100 ms */
  Profile.Frequency = RANGING_FREQUENCY; /* Ranging frequency Hz (shall be consistent with TimingBudget value) */
  Profile.EnableAmbient = 0; /* Enable: 1, Disable: 0 */
  Profile.EnableSignal = 0; /* Enable: 1, Disable: 0 */

  pL5obj->IsAmbientEnabled = Profile.EnableAmbient;
  pL5obj->IsSignalEnabled = Profile.EnableSignal;

  /*
     use case VL53L5CX_PROFILE_4x4_CONTINUOUS:
  */
  status = vl53l5cx_set_resolution(&(pL5obj->Dev), VL53L5CX_RESOLUTION_4X4);
  status |= vl53l5cx_set_ranging_mode(&(pL5obj->Dev), VL53L5CX_RANGING_MODE_CONTINUOUS);
  status |= vl53l5cx_set_integration_time_ms(&(pL5obj->Dev), TIMING_BUDGET);
  status |= vl53l5cx_set_ranging_frequency_hz(&(pL5obj->Dev), RANGING_FREQUENCY);

  if (status != VL53L5CX_STATUS_OK)
  {
    printf("ERROR : Configuration programming error!\n\n");
    while (1);
  }

  status = vl53l5cx_start_ranging(&(pL5obj->Dev));
  if (status != VL53L5CX_STATUS_OK)
  {
    printf("vl53l5cx_start_ranging failed\n");
    while(1);
  }

  while (1)
  {
    /* polling mode */
    (void)vl53l5cx_check_data_ready(&(pL5obj->Dev), &NewDataReady);

    if (NewDataReady != 0)
    {
      status = vl53l5cx_get_ranging_data(&(pL5obj->Dev), &data);

      if (status == VL53L5CX_STATUS_OK)
      {
        /*
         Convert the data format to Result format.
         Note that you can print directly from data format
        */
        if (convert_data_format(pL5obj, &data, &Result) < 0)
        {
          printf("convert_data_format failed\n");
          while(1);
        }
        print_result(&Result);
      }
    }

    HAL_Delay(POLLING_PERIOD);
  }
}
#else
static void MX_VL53L5CX_SimpleRanging_Process_TOF(void)
{
    static int count = 0;

    //TOF2
    CUSTOM_RANGING_SENSOR_GetDistance(CUSTOM_VL53L5CX2, &Result2);
    print_TOF2(&Result2);

	//TOF1
	CUSTOM_RANGING_SENSOR_GetDistance(CUSTOM_VL53L5CX, &Result);
	print_TOF1(&Result);

	//TOF3
	CUSTOM_RANGING_SENSOR_GetDistance(CUSTOM_VL53L5CX3, &Result3);
	print_TOF3(&Result3);

	HAL_Delay(POLLING_PERIOD);
    count++;
    if (count == 15)
     {
        printf("Nombre de matrices 8x8 par seconde : %d\n", count);
         count = 0;
     }
}


#endif /* USE_BARE_DRIVER */
static void print_TOF1(RANGING_SENSOR_Result_t *Result)
{
    printf("Matrix 8x8 Values: TOF 1\n");

    for (int l = 0; l < RANGING_SENSOR_NB_TARGET_PER_ZONE; l++)
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                long distance_value = (long)Result->ZoneResult[i * 8 + j].Distance[l];
                if (distance_value > 3000)
                {
                    printf("  *** ");
                }
                else
                {
                    printf("%5ld ", distance_value);
                }
            }
            printf("\n");
        }
        printf("\n");
    }

}

static void print_TOF2(RANGING_SENSOR_Result_t *Result)
{
    printf("Matrix 8x8 Values: TOF 2\n");

    for (int l = 0; l < RANGING_SENSOR_NB_TARGET_PER_ZONE; l++)
    {
        // Parcours de la matrice
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                long distance_value = (long)Result->ZoneResult[i * 8 + j].Distance[l];

                if (distance_value > 3000)
                {
                    printf("  *** ");
                }
                else
                {
                   printf("%5ld ", distance_value);
                }
            }
            printf("\n");
        }
       printf("\n");
    }
}

static void print_TOF3(RANGING_SENSOR_Result_t *Result)
{
    printf("Matrix 8x8 Values: TOF 3\n");

    for (int l = 0; l < RANGING_SENSOR_NB_TARGET_PER_ZONE; l++)
    {
        // Parcours de la matrice
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                long distance_value = (long)Result->ZoneResult[i * 8 + j].Distance[l];

                if (distance_value > 3000)
                {
                    printf("  *** ");
                }
                else
                {
                   printf("%5ld ", distance_value);
                }
            }
           printf("\n");
        }
       printf("\n");
    }
}
#ifdef USE_BARE_DRIVER
static uint8_t map_target_status(uint8_t status)
{
  uint8_t ret;

  if ((status == 5U) || (status == 9U))
  {
    ret = 0U; /* ranging is OK */
  }
  else if (status == 0U)
  {
    ret = 255U; /* no update */
  }
  else
  {
    ret = status; /* return device status otherwise */
  }

  return ret;
}

static int32_t convert_data_format(VL53L5CX_Object_t *pObj,
    VL53L5CX_ResultsData *data, RANGING_SENSOR_Result_t *pResult)
{
  int32_t ret;
  uint8_t i, j;
  uint8_t resolution;
  uint8_t target_status;

  if ((pObj == NULL) || (pResult == NULL))
  {
    ret = VL53L5CX_INVALID_PARAM;
  }
  else if (vl53l5cx_get_resolution(&pObj->Dev, &resolution) != VL53L5CX_STATUS_OK)
  {
    ret = VL53L5CX_ERROR;
  }
  else
  {
    pResult->NumberOfZones = resolution;

    for (i = 0; i < resolution; i++)
    {
      pResult->ZoneResult[i].NumberOfTargets = data->nb_target_detected[i];

      for (j = 0; j < data->nb_target_detected[i]; j++)
      {
        pResult->ZoneResult[i].Distance[j] = (uint32_t)data->distance_mm[(VL53L5CX_NB_TARGET_PER_ZONE * i) + j];

        /* return Ambient value if ambient rate output is enabled */
        if (pObj->IsAmbientEnabled == 1U)
        {
          /* apply ambient value to all targets in a given zone */
          pResult->ZoneResult[i].Ambient[j] = (float_t)data->ambient_per_spad[i];
        }
        else
        {
          pResult->ZoneResult[i].Ambient[j] = 0.0f;
        }

        /* return Signal value if signal rate output is enabled */
        if (pObj->IsSignalEnabled == 1U)
        {
          pResult->ZoneResult[i].Signal[j] =
            (float_t)data->signal_per_spad[(VL53L5CX_NB_TARGET_PER_ZONE * i) + j];
        }
        else
        {
          pResult->ZoneResult[i].Signal[j] = 0.0f;
        }

        target_status = data->target_status[(VL53L5CX_NB_TARGET_PER_ZONE * i) + j];
        pResult->ZoneResult[i].Status[j] = map_target_status(target_status);
      }
    }

    ret = VL53L5CX_OK;
  }

  return ret;
}
#endif

#ifdef __cplusplus
}
#endif
