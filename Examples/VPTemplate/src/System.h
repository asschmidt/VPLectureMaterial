/******************************************************************************
 * @file System.h
 *
 * @author Andreas Schmidt (a.v.schmidt81@googlemail.com)
 * @date   08.02.2025
 *
 * @copyright Copyright (c) 2025
 *
 ******************************************************************************
 *
 * @brief Header file for functions used for system initialization and common
 * error handling
 *
 *
 *****************************************************************************/
#ifndef _SYSTEM_H
#define _SYSTEM_H



/***** INCLUDES **************************************************************/


/***** CONSTANTS *************************************************************/


/***** MACROS ****************************************************************/


/***** TYPES *****************************************************************/


/***** PROTOTYPES ************************************************************/

/**
  * @brief System Clock Configuration
  *
  * @retval None
  */
void SystemClock_Config(void);

/**
  * @brief  This function is executed in case of error occurrence.
  *
  * @details The function just implements an endless loop. Therefore, the
  * system will get stuck in this loop in case of an error
  *
  * @retval None
  */
void Error_Handler(void);


#endif
