/*
===============================================================================
 Name        : 09_Day26_210921_GPIO009.c
 
 Description : Single seven segment display from 0 to F with a delay
 	 	 	   Data Pins PORT 1.19 to P1.26
 	 	 	   Control Pins PORT 0.4 to 0.7


 Layered Architecture used for this project
 ************************************
 Application layer-09_Day26_210921_GPIO009.c
 ************************************
 Board layer - sevenseg.c/.h
 ************************************
 Low level drivers or chip level - gpio.c/.h
 ************************************
 Hardware
 ************************************

===============================================================================
*/

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
/* Private includes ----------------------------------------------------------*/
#include "sevenseg.h"
/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
#define MAXTIMEOUT 0xFFFFF
/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/

/**
  * @brief  Initialize all the hardware connected
  * @retval none
  */
void vAppHardwareInit(void)
{

	vSevenSegInitialize();
}

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
	uint8_t  num=0;
	uint32_t delaycount=0;
  /* MCU Configuration--------------------------------------------------------*/

  /* Initialize all configured peripherals */
   vAppHardwareInit();

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)  // for(;;)
  {
      vSevenSegDisplay(CTRL_1,num);
	  vSevenSegDisplay(CTRL_2,num);
	  vSevenSegDisplay(CTRL_3,num);
	  vSevenSegDisplay(CTRL_4,num);


	  if(num>15)  // or if(num>0xF)
		  num=0;

 	  delaycount++;
 	  if(delaycount>MAXTIMEOUT)
 	  {
 		  delaycount=0;
 		  num++;
 	  }

  }
  /* End of Application entry point */
}




