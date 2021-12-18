/*************************************************************************************/
/*************************************************************************************/
/************************         Author: Bassel Sherif          *********************/
/************************         Layer:     MCAL                *********************/
/************************         Date:    5/8/2021              *********************/
/************************         SWC:      USART                *********************/
/************************         Version: 1.00                  *********************/
/*************************************************************************************/
/*************************************************************************************/

#include "../../0-LIB/STD_TYPES.h"
#include "../../0-LIB/BIT_MATH.h"

#include "USART_register.h"
#include "USART_config.h"
#include "USART_private.h"
#include "USART_interface.h"

static u8 USART_u8BusyState = IDLE;


void USART_voidInit(void)
{
	u8 Local_u8UCSRC = 0;					    // Local variable to hold the UCSRC register value

// Parity mode
#if(USART_PARITY_DISABLED==USART_PARITY)
	CLR_BIT(Local_u8UCSRC,UCSRC_UPM1);
	CLR_BIT(Local_u8UCSRC,UCSRC_UPM0);
#elif(USART_PARITY_EVEN==USART_PARITY)
	SET_BIT(Local_u8UCSRC,UCSRC_UPM1);
	CLR_BIT(Local_u8UCSRC,UCSRC_UPM0);
#elif(USART_PARITY_ODD==USART_PARITY)
	SET_BIT(Local_u8UCSRC,UCSRC_UPM1);
	SET_BIT(Local_u8UCSRC,UCSRC_UPM0);
#else
#error "Invalid USART Parity Mode Configuration"
#endif

// Send bit size
#if(USART_SEND_SIZE==USART_SEND_5_BIT)
	CLR_BIT(Local_u8UCSRC,UCSRC_UCSZ0);
	CLR_BIT(Local_u8UCSRC,UCSRC_UCSZ1);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);
#elif(USART_SEND_SIZE==USART_SEND_6_BIT)
	SET_BIT(Local_u8UCSRC,UCSRC_UCSZ0);
	CLR_BIT(Local_u8UCSRC,UCSRC_UCSZ1);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);
#elif(USART_SEND_SIZE==USART_SEND_7_BIT)
	CLR_BIT(Local_u8UCSRC,UCSRC_UCSZ0);
	SET_BIT(Local_u8UCSRC,UCSRC_UCSZ1);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);
#elif(USART_SEND_SIZE==USART_SEND_8_BIT)
	SET_BIT(Local_u8UCSRC,UCSRC_UCSZ0);
	SET_BIT(Local_u8UCSRC,UCSRC_UCSZ1);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);
#else
#error "Invalid USART Send Size Configuration"
#endif

// Stop bit size
#if(USART_STOP_1_BIT==USART_STOP_SIZE)
	CLR_BIT(Local_u8UCSRC,UCSRC_USBS);
#elif(USART_STOP_2_BIT==USART_STOP_SIZE)
	SET_BIT(Local_u8UCSRC,UCSRC_USBS);
#else
#error "Invalid USART Stop Bits Configuration"
#endif

// Mode of Operation
#if(USART_ASYNCHRNOUS_MODE==USART_OPERATION_MODE)
    CLR_BIT(Local_u8UCSRC,UCSRC_UMSEL);
#elif(USART_SYNCHRNOUS_MODE==USART_OPERATION_MODE)
    SET_BIT(Local_u8UCSRC,UCSRC_UMSEL);
#else
#error "Invalid USART Operation mode"
#endif

	SET_BIT(UCSRB,UCSRB_TXEN);				// Transmitter enable
	SET_BIT(UCSRB,UCSRB_RXEN);				// Receiver enable

	SET_BIT(Local_u8UCSRC,UCSRC_URSEL); 	// select UCSRC register

	UCSRC = Local_u8UCSRC;					// Assign UCSRC value in one operation

	UBRRL = 64;								// baud rate setting to 9600 bps, 10Mhz clock frequency
	UBRRH = 0 ;
}

void USART_u8Send(u8 Copy_u8Data)
{
	while(GET_BIT(UCSRA,UCSRA_UDRE) == 0 );	// wait until transmit buffer is empty
	UDR=Copy_u8Data;						// send the data
}

u8 USART_u8SendCharSynch(u8 Copy_u8Data)
{
    u8 Local_u8ErrorState = OK;

    if(USART_u8BusyState==IDLE)
    {
        u32 Local_u32Counter = 0;

        /* Polling for Transmit Buffer */
        while(((GET_BIT(UCSRA,UCSRA_UDRE))==0) && (Local_u32Counter != USART_u32TIMEOUT ))
        {
            Local_u32Counter++;
        }
        if(Local_u32Counter != USART_u32TIMEOUT)
        {
            UDR = Copy_u8Data;
        }
        else
        {
            Local_u8ErrorState = NOK;
        }
    }
    else
    {
        Local_u8ErrorState = BUSY_FUNC;
    }
    return Local_u8ErrorState;
}

void USART_SendString(char *string)
{
	int p = 0;
	while (string[p] != 0)
	{
		USART_u8Send(string[p]);
		p++;
	}
}

u8 USART_u8Receive(void)
{
	while(GET_BIT(UCSRA,UCSRA_RXC) == 0 );	// Wait for the receive complete flag to be up
	return UDR;								// Return the received data
}

u8 USART_u8ReceiveCharSynch(u8* Copy_pu8ReceivedData)
{
	u8 Local_u8ErrorState = OK;

	if(Copy_pu8ReceivedData != NULL)
	{
		while((GET_BIT(UCSRA,UCSRA_RXC))==0);	//Waiting for data to be received
		*Copy_pu8ReceivedData = UDR;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}

	return Local_u8ErrorState;
}

u8 USART_u8ReceiveBufferSynch(u8* Copy_pu8Buffer, u8 Copy_u8BufferSize)
{
	u8 Local_u8ErrorState=OK;

	if(Copy_pu8Buffer != NULL)
	{
		u8 Local_u8Counter;

		for(Local_u8Counter = 0; Local_u8Counter < Copy_u8BufferSize; Local_u8Counter++)
		{
			Local_u8ErrorState = USART_u8ReceiveCharSynch(Copy_pu8Buffer + Local_u8Counter);
		}
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}

	return Local_u8ErrorState;
}

void USART_voidDisable(void)
{
    CLR_BIT(UCSRB,UCSRB_TXEN);	// Disable Transmit
    CLR_BIT(UCSRB,UCSRB_RXEN);	// Disable Receive
}

