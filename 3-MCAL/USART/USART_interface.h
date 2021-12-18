/*************************************************************************************/
/*************************************************************************************/
/************************         Author: Bassel Sherif          *********************/
/************************         Layer:     MCAL                *********************/
/************************         SWC:      USART                *********************/
/************************         Version: 1.00                  *********************/
/*************************************************************************************/
/*************************************************************************************/


#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_


void USART_voidInit(void);

void USART_u8Send(u8 Copy_u8Data);

u8 USART_u8SendCharSynch(u8 Copy_u8Data);

void USART_SendString(char *string);

u8 USART_u8Receive(void);

u8 USART_u8ReceiveCharSynch(u8* Copy_pu8ReceivedData);

u8 USART_u8ReceiveBufferSynch(u8* Copy_pu8Buffer, u8 Copy_u8BufferSize);

void USART_voidDisable(void);

#endif
