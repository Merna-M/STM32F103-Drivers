/***************************************************************************/
/* Author  : MERNA */
/* Version : 01    */
/***************************************************************************/

#ifndef _EXTI_INTERFACE_H
#define _EXTI_INTERFACE_H

//#include "STD_types.h"
/******************************************** Macros ******************************************************/
#define EXTI_RISING_EDGE		0
#define EXTI_FALLING_EDGE		1
#define EXTI_ON_CHANGE			2

/* EXTI IDs */
#define EXTI_0					0
#define EXTI_1					1
#define EXTI_2					2
#define EXTI_3					3
#define EXTI_4					4


/* select port */
#define EXTI_PORTA				0b0000
#define EXTI_PORTB				0b0001
#define EXTI_PORTC				0b0010
#define EXTI_PORTD				0b0011
#define EXTI_PORTE				0b0100
#define EXTI_PORTF				0b0101
#define EXTI_PORTG				0b0110


#define EXTI_ENABLE				0
#define EXTI_DISABLE			1


/* NVIC */
#define EXTI0_NVIC_ENABLE			6
#define EXTI1_NVIC_ENABLE			7
#define EXTI2_NVIC_ENABLE			8
#define EXTI3_NVIC_ENABLE			9
#define EXTI4_NVIC_ENABLE			10
#define EXTI9_5_NVIC_ENABLE			23
#define EXTI10_15_NVIC_ENABLE		40

/******************************************** Prototypes ******************************************************/

void EXTI_vEnableLine(uint8 Copy_u8Line);

void EXTI_vDisableLine(uint8 Copy_u8Line);

void EXTI_vEventType(uint8 Copy_u8Type , uint8 Copy_u8Line);

void EXTI_vSWInterrupt(uint8 Copy_u8Line);

void EXTI_vSetCallBack(uint8 Copy_u8Line , void(*ptr_function)(void));

void EXTI_vSelectPort(uint8 Copy_u8Line , uint8 Copy_u8Port);



#endif