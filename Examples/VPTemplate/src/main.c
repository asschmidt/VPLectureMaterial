/******************************************************************************
 * @file main.c
 *
 * @author Andreas Schmidt (a.v.schmidt81@googlemail.com
 * @date   08.02.2025
 *
 * @copyright Copyright (c) 2025
 *
 ******************************************************************************
 *
 * @brief Main file for the VP Template project
 *
 *
 *****************************************************************************/


/***** INCLUDES **************************************************************/
#include "stm32g4xx_hal.h"
#include "System.h"

#include "HardwareConfig.h"

#include "Util/Global.h"
#include "Util/printf.h"
#include "LogOutput.h"

#include "UARTModule.h"
#include "ButtonModule.h"
#include "LEDModule.h"
#include "ADCModule.h"
#include "TimerModule.h"
#include "Scheduler.h"

#include "GlobalObjects.h"


/***** PRIVATE CONSTANTS *****************************************************/


/***** PRIVATE MACROS ********************************************************/


/***** PRIVATE TYPES *********************************************************/


/***** PRIVATE PROTOTYPES ****************************************************/
static int32_t initializePeripherals();


/***** PRIVATE VARIABLES *****************************************************/
static Scheduler gScheduler;            // Global Scheduler instance


/***** PUBLIC FUNCTIONS ******************************************************/

/**
 * @brief Main function of System
 */
int main(void)
{
    // Initialize the HAL
    HAL_Init();

    SystemClock_Config();

    // Initialize Peripherals
    initializePeripherals();

    // Prepare Scheduler
    // ...

    // Initialize Scheduler
    schedInitialize(&gScheduler);

    int globalCounter = 0;

    while (1)
    {
        // Toggle all LEDs to the their functionality (Toggle frequency depends on HAL_Delay at end of loop)
        ledToggleLED(LED0);
        ledToggleLED(LED1);
        ledToggleLED(LED2);
        ledToggleLED(LED3);

        // Read to buttons
        Button_Status_t but1 = buttonGetButtonStatus(BTN_SW1);
        Button_Status_t but2 = buttonGetButtonStatus(BTN_SW2);

        // Read the POT1 input from ADC
        int adcValue = adcReadChannel(ADC_INPUT0);

        // If SW1 is pressed, print some debug message on the terminal
        if (but1 == BUTTON_PRESSED)
        {
            outputLogf("Some Message %d\n\r", globalCounter);
        }

        // If SW2 is pressed, print the ADC digit value on the terminal
        if (but2 == BUTTON_PRESSED)
        {
        	HAL_GPIO_WritePin(BEEP_GPIO_PORT, BEEP_PIN, GPIO_PIN_RESET);
        }
        else
        {
        	HAL_GPIO_WritePin(BEEP_GPIO_PORT, BEEP_PIN, GPIO_PIN_SET);
        }

        outputLogf("ADC Val: %d\n\r", adcValue);

        // Remove this HAL_Delay as soon as there is a Scheduler used
        HAL_Delay(100);
    }
}

/***** PRIVATE FUNCTIONS *****************************************************/

/**
 * @brief Initializes the used peripherals like GPIO,
 * ADC, DMA and Timer Interrupts
 *
 * @return Returns ERROR_OK if no error occurred
 */
static int32_t initializePeripherals()
{
    // Initialize UART used for Debug-Outputs
    uartInitialize(115200);

    // Initialize GPIOs for Buttons
    buttonInitialize();

    // Initialize GPIOs for LED and 7-Segment output
    ledInitialize();
    //displayInitialize();

    // Initialize Timer, DMA and ADC for sensor measurements
    timerInitialize();
    adcInitialize();

    return ERROR_OK;
}
