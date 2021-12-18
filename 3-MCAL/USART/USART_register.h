/****************************************************************************************/
/****************************************************************************************/
/************************            Author: Bassel Sherif          *********************/
/************************            Layer:     MCAL                *********************/
/************************            SWC:      UART                 *********************/
/************************            Version: 1.00                  *********************/
/****************************************************************************************/
/****************************************************************************************/

#ifndef UART_REGISTER_H_
#define UART_REGISTER_H_


#define UCSRA			*((volatile u8*)0x2B)
#define UCSRA_RXC				7			// Receive complete flag
#define UCSRA_TXC				6			// Transmit complete flag
#define UCSRA_UDRE				5			// Data Register Empty
#define UCSRA_FE				4			// Frame Error
#define UCSRA_DOR				3			// Data OverRun
#define UCSRA_PE				2			// Parity Error
#define UCSRA_U2X				1			// Double the USART Transmission Speed
#define UCSRA_MPCM				0			// Multi-processor Communication Mode

#define UCSRB			*((volatile u8*)0x2A)
#define UCSRB_RXCIE				7			// RX Complete Interrupt Enable
#define UCSRB_TXCIE				6			// TX Complete Interrupt Enable
#define UCSRB_UDRIE				5			// Data Register Empty Interrupt Enable
#define UCSRB_RXEN				4			// Receiver Enable
#define UCSRB_TXEN				3			// Transmitter Enable
#define UCSRB_UCSZ2				2			// Character Size
#define UCSRB_RXB8				1			// Receive Data Bit 8
#define UCSRB_TXB8				0			// Transmit Data Bit 8

#define UCSRC			*((volatile u8*)0x40)
#define UCSRC_URSEL				7			// Register Select
#define UCSRC_UMSEL				6			// USART Mode Select
#define UCSRC_UPM1				5			// Parity mode
#define UCSRC_UPM0				4           // Parity mode
#define UCSRC_USBS				3			// Stop Bit Select
#define UCSRC_UCSZ1				2			// Character Size
#define UCSRC_UCSZ0				1           // Character Size
#define UCSRC_UCPOL				0			// Clock Polarity

#define UDR				*((volatile u8*)0x2C)

#define UBRRH			*((volatile u8*)0x40)   //Baud rate register
#define UBRRH_URSEL				7           // Register Select
#define UBRRH_UBRRH3			3
#define UBRRH_UBRRH2			2
#define UBRRH_UBRRH1			1
#define UBRRH_UBRRH0			0

#define UBRRL			*((volatile u8*)0x29)   //Baud rate register
#define UBRRL_UBRRL7			7
#define UBRRL_UBRRL6			6
#define UBRRL_UBRRL5			5
#define UBRRL_UBRRL4			4
#define UBRRL_UBRRL3			3
#define UBRRL_UBRRL2			2
#define UBRRL_UBRRL1			1
#define UBRRL_UBRRL0			0



#endif
