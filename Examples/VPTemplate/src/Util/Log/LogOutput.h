/******************************************************************************
 * @file LogOutput.h
 *
 * @author Andreas Schmidt (a.v.schmidt81@googlemail.com)
 * @date   08.02.2025
 *
 * @copyright Copyright (c) 2025
 *
 ******************************************************************************
 *
 * @brief Header file for debug and log outputs
 *
 *
 *****************************************************************************/
#ifndef _LOG_OUTPUT_H_
#define _LOG_OUTPUT_H_

/***** INCLUDES **************************************************************/


/***** CONSTANTS *************************************************************/


/***** MACROS ****************************************************************/


/***** TYPES *****************************************************************/


/***** PROTOTYPES ************************************************************/

/**
 * @brief Outputs a simple string message to the UART output
 *
 * @param msg Zero terminated string to output
 */
void outputLog(const char* msg);

/**
 * @brief Outputs a formatted string to the UART output
 *
 *
 * @param format    Format string accroding printf specification
 * @param ...       Variable parameter
 *
 * @return Returns number of chars written to UART
 */
int outputLogf(const char* format, ...);


#endif
