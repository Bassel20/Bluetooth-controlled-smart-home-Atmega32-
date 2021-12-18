/****************************************************************************************/
/****************************************************************************************/
/************************            Author: Bassel Sherif          *********************/
/************************            Layer:     HAL                 *********************/
/************************            SWC:      DC Motor             *********************/
/************************            Version: 1.00                  *********************/
/****************************************************************************************/
/****************************************************************************************/
#include "../../0-LIB/STD_TYPES.h"
#include "../../3-MCAL/DIO/DIO_interface.h"

#include "DCMTR_config.h"
#include "DCMTR_interface.h"

void DCMTR_voidRotateCCW(u8 Copy_u8Pin1,u8 Copy_u8Pin2)
{
	DIO_u8SetPinValue(DCMTR_PORT,Copy_u8Pin1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DCMTR_PORT,Copy_u8Pin2,DIO_u8PIN_HIGH);
}

void DCMTR_voidRotateCW(u8 Copy_u8Pin1,u8 Copy_u8Pin2)
{
	DIO_u8SetPinValue(DCMTR_PORT,Copy_u8Pin2,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DCMTR_PORT,Copy_u8Pin1,DIO_u8PIN_HIGH);
}

void DCMTR_voidStop(u8 Copy_u8Pin1,u8 Copy_u8Pin2)
{
	DIO_u8SetPinValue(DCMTR_PORT,Copy_u8Pin2,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DCMTR_PORT,Copy_u8Pin1,DIO_u8PIN_LOW);
}
