/*************************************************************************************/
/*************************************************************************************/
/************************         Author: Bassel Sherif          *********************/
/************************         Layer:     MCAL                *********************/
/************************         SWC:      USART                *********************/
/************************         Version: 2.00                  *********************/
/*************************************************************************************/
/*************************************************************************************/

#ifndef USART_CONFIG_H
#define USART_CONFIG_H

/* Select Parity Mode
 * Options: 1- USART_PARITY_DISABLED : Parity Bits Disabled
 *          2- USART_PARITY_EVEN     : Parity Enabled, Even Parity
 *          3- USART_PARITY_ODD      : Parity Enabled, Odd Parity
 */
#define USART_PARITY			USART_PARITY_DISABLED
//*****************************************************************************
/* Set Size of Bits sent in each transmission
 * Options: 1- USART_SEND_5_BIT
 *          2- USART_SEND_6_BIT
 *          3- USART_SEND_7_BIT
 *          4- USART_SEND_8_BIT
 */
#define USART_SEND_SIZE			USART_SEND_8_BIT
//*****************************************************************************
/* Set Size of Stop Bits
 * Options: 1- USART_STOP_1_BIT
 *          2- USART_STOP_2_BIT
 */
#define USART_STOP_SIZE			USART_STOP_1_BIT
//*****************************************************************************
/* Set USART Operation Mode
 * Options: 1- USART_ASYNCHRNOUS_MODE
 *          2- USART_SYNCHRNOUS_MODE
 */
 #define USART_OPERATION_MODE   USART_ASYNCHRNOUS_MODE
//******************************************************************************

#define USART_u32TIMEOUT		50000

#endif
