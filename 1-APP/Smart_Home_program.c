/*************************************************************************/
/*************************************************************************/
/*************************		Author: Bassel Sherif	******************/
/*************************		Layer:APP 				******************/
/*************************		SWC: Smart Home			******************/
/*************************		Version: 1.00			******************/
/*************************		Date: 29-3-2021			******************/
/*************************************************************************/
/*************************************************************************/
#include "../0-LIB/STD_TYPES.h"
#include "../0-LIB/BIT_MATH.h"

#include "../3-MCAL/DIO/DIO_interface.h"

#include "util/delay.h"
#include "../3-MCAL/USART/USART_interface.h"

#include "Smart_Home_interface.h"

u8 Usernames[10][5]={"user0","user1","user2","user3","user4","user5","user6","user7","user8","user9"};
u8 Passwords[10][4]={"0000","1111","2222","3333","4444","5555","6666","7777","8888","9999"};

u8 u8MenuFlag = 1;					//used to prevent repeating the menu of options

u8 Input_Username[5];				//to store username entered by user
u8 Input_Password[4];				//to store password entered by user

u8 Username_Password_Index; 		// Used to indicate which password index to look at

u8 Username_valid_login_flag = 0;	//used to indicate if username is valid
u8 Username_trials = 3;

u8 Password_valid_login_flag = 0;	//used to indicate if password is valid
u8 Password_trials = 3;

void Username(void)
{
	while(Username_trials > 0 && Username_valid_login_flag == 0)
	{
		USART_SendString("Enter Username: ");
		USART_u8ReceiveBufferSynch(Input_Username, 5);	//receive the username

		u8 Local_u8Iterator;
		u8 Local_u8Iterator2;
		u8 Counter = 0;

		_delay_ms(200);

		//Checking if username is valid
		for(Local_u8Iterator = 0; Local_u8Iterator < 10; Local_u8Iterator++)
		{
			for(Local_u8Iterator2 = 0; Local_u8Iterator2 < 5; Local_u8Iterator2++)
			{
				if(Input_Username[Local_u8Iterator2] == Usernames[Local_u8Iterator][Local_u8Iterator2])
				{
					Counter++;
				}
			}

			if(Counter==5)	//username is correct
			{
				Username_Password_Index = Local_u8Iterator;
				break;
			}
			else
			{
				Counter = 0;
			}
		}

		if(Counter==5)	//username is correct
		{
			Username_valid_login_flag = 1;
		    _delay_ms(1000);
		}
		else
		{
			Username_trials--;	//wrong username -1 trial
			USART_SendString("Invalid Username \n");
		    _delay_ms(300);
		}

	}
	if(Username_trials == 0 && Username_valid_login_flag==0)	//out of trials
	{
		USART_SendString("Invalid Username");
	    while(1);
	}
}

void Password(void)
{

	while(Password_trials > 0 && Password_valid_login_flag == 0)
	{
		USART_SendString("Enter Password: ");
		USART_u8ReceiveBufferSynch(Input_Password, 4);	//receive the password
		u8 i;	//Local iterator
		u8 Counter = 0;

		_delay_ms(200);

		//Checking if password is valid
		for(i = 0; i < 4; i++)
		{
			if(Input_Password[i] == Passwords[Username_Password_Index][i])	//Compare input password with correct password
			{
				Counter++;	//Counter increases for every matching letter
			}
		}

		if(Counter == 4)	//password is correct
		{
			Password_valid_login_flag=1;
			USART_SendString("Welcome Home! :) \n");
			DIO_u8SetPinValue(DIO_u8PORTB , DIO_u8PIN5, DIO_u8PIN_LOW);		// Open Door
			DIO_u8SetPinValue(DIO_u8PORTB , DIO_u8PIN6, DIO_u8PIN_HIGH);	// Open Door
			_delay_ms(1000);
		}
		else
		{
			Password_trials--;	//wrong password -1 trial
			USART_SendString("Invalid Password, Try again \n");
			_delay_ms(300);
		}
	}

	if(Password_trials == 0 && Password_valid_login_flag == 0)	//out of trials
	{
	    USART_SendString("Invalid Password, out of tries \n");
	    while(1);
	}
}

void Options(u8 *pu8Option)
{
	u8 *Local_pu8ReceivedData;

	if(u8MenuFlag == 1)
	{
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
	u8MenuFlag = 0;
	}
	else
	{
		USART_SendString("\n");
	}
	while(1)
	{
		USART_u8ReceiveCharSynch(Local_pu8ReceivedData);
		if(*Local_pu8ReceivedData > '0')
			{
				break;
			}
	}
	*pu8Option = *Local_pu8ReceivedData;
}

