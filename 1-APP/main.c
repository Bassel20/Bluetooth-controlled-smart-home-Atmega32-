/****************************************************************************************/
/****************************************************************************************/
/************************            Author: Bassel Sherif          *********************/
/************************            Layer:    APP                  *********************/
/************************            SWC:      Smart Home           *********************/
/************************            Version: 1.00                  *********************/
/****************************************************************************************/
/****************************************************************************************/

#include "../0-LIB/STD_TYPES.h"
#include "../0-LIB/BIT_MATH.h"

#include "../3-MCAL/DIO/DIO_interface.h"
#include "../3-MCAL/USART/USART_interface.h"
#include "../2-HAL/DCMTR/DCMTR_interface.h"
#include "Smart_Home_interface.h"

int main(void)
{
	PORT_voidInit();
	USART_voidInit();

	DIO_u8SetPinValue(DIO_u8PORTB , DIO_u8PIN5, DIO_u8PIN_LOW);		// Close Door
	DIO_u8SetPinValue(DIO_u8PORTB , DIO_u8PIN6, DIO_u8PIN_LOW);		// Close Door

	u8 Local_u8ReceivedData;	//variable used to take option entered by user from function "Options"

	Username();
	Password();

	while(1)
	{
		Options(&Local_u8ReceivedData);

		switch(Local_u8ReceivedData)
		{
		case '1' :
			DIO_u8SetPinValue(DIO_u8PORTB , DIO_u8PIN0, DIO_u8PIN_HIGH);	// Turn ON LED
			USART_SendString("LED ON \n");	// send status of LED (LED ON)

			break;

		case '2' :
			DIO_u8SetPinValue(DIO_u8PORTB , DIO_u8PIN0, DIO_u8PIN_LOW);	// Turn OFF LED
			USART_SendString("LED OFF \n");  //send status of LED (LED OFF)
			break;

		case '3' :
			DCMTR_voidRotateCW(DIO_u8PIN2, DIO_u8PIN1);	// turn ON motor
			USART_SendString("FAN ON \n");  //send status of Motor (FAN ON)
			break;

		case '4' :
			 DCMTR_voidStop( DIO_u8PIN1, DIO_u8PIN2); // turn OFF motor
			 USART_SendString("FAN OFF \n");  //send status of Motor (FAN OFF)
		 	break;

		case '5' :
			DIO_u8SetPinValue(DIO_u8PORTB , DIO_u8PIN3, DIO_u8PIN_HIGH);	// Turn ON Siren
			USART_SendString("Siren ON \n");  //send status of Siren (Siren ON)
			break;

		case '6' :
			DIO_u8SetPinValue(DIO_u8PORTB , DIO_u8PIN3, DIO_u8PIN_LOW);	// Turn OFF Siren
			USART_SendString("Siren OFF \n");  //send status of Siren (Siren OFF)
		 	break;
		case '7' :
			USART_SendString(
				"Choose one of the following options: \n"
				"-> to turn on the lights press 1 \n"
				"-> to turn off the lights press 2 \n"
				"-> to turn on the fan press 3 \n"
				"-> to turn off the fan press 4 \n"
				"-> to turn on the siren press 5 \n"
				"-> to turn off the siren press 6 \n"
				"-> to repeat the menu press 7 \n \n"
			);
		 	break;

		default :
			USART_SendString("Invalid option \n");	// tell user to enter a valid option
			break;
		}
	}
	return 0;
}
