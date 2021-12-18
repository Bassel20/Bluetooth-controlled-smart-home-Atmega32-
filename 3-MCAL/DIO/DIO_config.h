/*************************************************************************/
/*************************************************************************/
/*************************		Author: Bassel Sherif	******************/
/*************************		Layer: MCAL				******************/
/*************************		SWC: PORT				******************/
/*************************		Version: 1.00			******************/
/*************************		Date: 31-8-2020			******************/
/*************************************************************************/
/*************************************************************************/

#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_

/*Enter 0 for Input , 1 for output*/
#define PORTA_PIN0_DIR	              0
#define PORTA_PIN1_DIR	              0
#define PORTA_PIN2_DIR	              0
#define PORTA_PIN3_DIR	              0
#define PORTA_PIN4_DIR	              0
#define PORTA_PIN5_DIR	              0
#define PORTA_PIN6_DIR	              0
#define PORTA_PIN7_DIR	              0

#define PORTB_PIN0_DIR	              1		/*LED pin*/
#define PORTB_PIN1_DIR	              1		/*Motor pin*/
#define PORTB_PIN2_DIR	              1		/*Motor pin*/
#define PORTB_PIN3_DIR	              1		/*Siren pin*/
#define PORTB_PIN4_DIR	              1
#define PORTB_PIN5_DIR	              1		/*Door Lock pin*/
#define PORTB_PIN6_DIR	              1		/*Door Lock pin*/
#define PORTB_PIN7_DIR	              0

#define PORTC_PIN0_DIR	              0
#define PORTC_PIN1_DIR	              0
#define PORTC_PIN2_DIR	              0
#define PORTC_PIN3_DIR	              0
#define PORTC_PIN4_DIR	              0
#define PORTC_PIN5_DIR	              0
#define PORTC_PIN6_DIR	              0
#define PORTC_PIN7_DIR	              0

#define PORTD_PIN0_DIR	              0		/*RX as input*/
#define PORTD_PIN1_DIR	              1		/*TX as output*/
#define PORTD_PIN2_DIR	              0
#define PORTD_PIN3_DIR	              0
#define PORTD_PIN4_DIR	              0
#define PORTD_PIN5_DIR	              0
#define PORTD_PIN6_DIR	              0
#define PORTD_PIN7_DIR	              1

/*Enter 0 for : 1- floating if input
				2- Low if output

  Enter 1 for : 1-Pulled up if input
				2- High if output		*/
#define PORTA_PIN0_INITIAL_VALUE       0
#define PORTA_PIN1_INITIAL_VALUE       0
#define PORTA_PIN2_INITIAL_VALUE       0
#define PORTA_PIN3_INITIAL_VALUE       0
#define PORTA_PIN4_INITIAL_VALUE       0
#define PORTA_PIN5_INITIAL_VALUE       0
#define PORTA_PIN6_INITIAL_VALUE       0
#define PORTA_PIN7_INITIAL_VALUE       0

#define PORTB_PIN0_INITIAL_VALUE       0
#define PORTB_PIN1_INITIAL_VALUE       0
#define PORTB_PIN2_INITIAL_VALUE       0
#define PORTB_PIN3_INITIAL_VALUE       0
#define PORTB_PIN4_INITIAL_VALUE       0
#define PORTB_PIN5_INITIAL_VALUE       0
#define PORTB_PIN6_INITIAL_VALUE       0
#define PORTB_PIN7_INITIAL_VALUE       0

#define PORTC_PIN0_INITIAL_VALUE       0
#define PORTC_PIN1_INITIAL_VALUE       0
#define PORTC_PIN2_INITIAL_VALUE       0
#define PORTC_PIN3_INITIAL_VALUE       0
#define PORTC_PIN4_INITIAL_VALUE       0
#define PORTC_PIN5_INITIAL_VALUE       0
#define PORTC_PIN6_INITIAL_VALUE       0
#define PORTC_PIN7_INITIAL_VALUE       0

#define PORTD_PIN0_INITIAL_VALUE       0
#define PORTD_PIN1_INITIAL_VALUE       0
#define PORTD_PIN2_INITIAL_VALUE       0
#define PORTD_PIN3_INITIAL_VALUE       0
#define PORTD_PIN4_INITIAL_VALUE       0
#define PORTD_PIN5_INITIAL_VALUE       0
#define PORTD_PIN6_INITIAL_VALUE       0
#define PORTD_PIN7_INITIAL_VALUE       0

#endif
