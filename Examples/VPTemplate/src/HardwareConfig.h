/******************************************************************************
 * @file HardwareConfig.h
 *
 * @author Andreas Schmidt (a.v.schmidt81@googlemail.com
 * @date   08.02.2025
 *
 * @copyright Copyright (c) 2025
 *
 ******************************************************************************
 *
 * @brief Header file for hardware configuration
 *
 * @details Defines the Pin and Port mappings of the microcontroller for the
 * use of the PiEye EduShield
 *
 *
 *****************************************************************************/
#ifndef _HARDWARE_CONFIGURATION_H_
#define _HARDWARE_CONFIGURATION_H_

/***** INCLUDES **************************************************************/
#include "stm32g4xx_hal.h"

/***** CONSTANTS *************************************************************/


/***** MACROS ****************************************************************/
#define BEEP_PIN                               GPIO_PIN_3
#define BEEP_GPIO_PORT                         GPIOB

/*
 * LED Pin Configuration
 */
#define LED0_PIN                               GPIO_PIN_6
#define LED0_GPIO_PORT                         GPIOB

#define LED1_PIN                               GPIO_PIN_7
#define LED1_GPIO_PORT                         GPIOA

#define LED2_PIN                               GPIO_PIN_6
#define LED2_GPIO_PORT                         GPIOA

#define LED3_PIN                               GPIO_PIN_5
#define LED3_GPIO_PORT                         GPIOA

//#define LED4_PIN                               GPIO_PIN_8
//#define LED4_GPIO_PORT                         GPIOB

/*
 * 7-Segment Pin Configuraiton
*/
/*#define _7SEGA_PIN                              GPIO_PIN_5
#define _7SEGA_GPIO_PORT                        GPIOA
#define _7SEGB_PIN                              GPIO_PIN_6
#define _7SEGB_GPIO_PORT                        GPIOA
#define _7SEGC_PIN                              GPIO_PIN_7
#define _7SEGC_GPIO_PORT                        GPIOA
#define _7SEGD_PIN                              GPIO_PIN_8
#define _7SEGD_GPIO_PORT                        GPIOA
#define _7SEGE_PIN                              GPIO_PIN_9
#define _7SEGE_GPIO_PORT                        GPIOA
#define _7SEGF_PIN                              GPIO_PIN_0
#define _7SEGF_GPIO_PORT                        GPIOC
#define _7SEGG_PIN                              GPIO_PIN_1
#define _7SEGG_GPIO_PORT                        GPIOC

#define _7SEG_COM_PIN                           GPIO_PIN_0
#define _7SEG_COM_GPIO_PORT                     GPIOB*/

/*
 * Analog Input Pin Configuration
*/
#define POT1_PIN                                GPIO_PIN_0
#define POT1_GPIO_PORT                          GPIOA
//#define POT2_PIN                                GPIO_PIN_1
//#define POT2_GPIO_PORT                          GPIOA

/*
 * USART Pin Configuration
*/
#define USART_TX_PIN                            GPIO_PIN_2
#define USART_TX_GPIO_PORT                      GPIOA
#define USART_RX_PIN                            GPIO_PIN_3
#define USART_RX_GPIO_PORT                      GPIOA

/*
 * Input (Button) Pins
*/
#define SW1_PIN                                 GPIO_PIN_1
#define SW1_GPIO_PORT                           GPIOA
#define SW2_PIN                                 GPIO_PIN_4
#define SW2_GPIO_PORT                           GPIOA
#define SW3_PIN                                 GPIO_PIN_0
#define SW3_GPIO_PORT                           GPIOB

#define B1_PIN                                  GPIO_PIN_13
#define B1_GPIO_PORT                            GPIOC


/***** TYPES *****************************************************************/


/***** PROTOTYPES ************************************************************/


#endif
