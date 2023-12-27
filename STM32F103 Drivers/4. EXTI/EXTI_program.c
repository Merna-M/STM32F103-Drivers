/***************************************************************************/
/* Author  : MERNA */
/* Version : 01    */
/***************************************************************************/

#include "STD_types.h"
#include "BIT_math.h"
#include "AFIO_private.h"
#include "EXTI_private.h"
#include "EXTI_interface.h"

/* global pointers to void functions */
void (*GP_EXT0)(void) = NULL;
void (*GP_EXT1)(void) = NULL;
void (*GP_EXT2)(void) = NULL;
void (*GP_EXT3)(void) = NULL;
void (*GP_EXT4)(void) = NULL;


/**************************************************************************************************************************/

void EXTI_vEnableLine(uint8 Copy_u8Line)
{
	SET_BIT(EXTI->IMR,Copy_u8Line);
}

/**************************************************************************************************************************/

void EXTI_vDisableLine(uint8 Copy_u8Line)
{
	CLR_BIT(EXTI->IMR,Copy_u8Line);
}

/**************************************************************************************************************************/

/*
options:
1. EXTI_RISING_EDGE
2. EXTI_FALLING_EDGE
3. EXTI_ON_CHANGE
*/
void EXTI_vEventType(uint8 Copy_u8Type , uint8 Copy_u8Line)
{
	switch(Copy_u8Type)
	{
		case EXTI_RISING_EDGE:
		SET_BIT(EXTI->RTSR,Copy_u8Line);
		break;
		
		case EXTI_FALLING_EDGE:
		SET_BIT(EXTI->FTSR,Copy_u8Line);
		break;
		
		case EXTI_ON_CHANGE:
		SET_BIT(EXTI->RTSR,Copy_u8Line);
		SET_BIT(EXTI->FTSR,Copy_u8Line);
		break;
	}
}

/**************************************************************************************************************************/

void EXTI_vSWInterrupt(uint8 Copy_u8Line)
{
	SET_BIT(EXTI->SWIER,Copy_u8Line);
}

/**************************************************************************************************************************/
/*
Copy_u8Line options :
1. EXTI_0
2. EXTI_1
3. EXTI_2
4. EXTI_3
5. EXTI_4
*/
void EXTI_vSetCallBack(uint8 Copy_u8Line , void (*ptr_function)(void))
{
	switch(Copy_u8Line)
	{
		case EXTI_0:
		GP_EXT0 = ptr_function;
		break;
		
		case EXTI_1:
		GP_EXT1 = ptr_function;
		break;
		
		case EXTI_2:
		GP_EXT2 = ptr_function;
		break;
		
		case EXTI_3:
		GP_EXT3 = ptr_function;
		break;
		
		case EXTI_4:
		GP_EXT4 = ptr_function;
		break;
		
		default:
		GP_EXT0 = ptr_function;
		break;
	}
}

/**************************************************************************************************************************/
/*
Copy_u8Port options:
1. EXTI_PORTA
2. EXTI_PORTB
3. EXTI_PORTC
4. EXTI_PORTD
5. EXTI_PORTE
6. EXTI_PORTF
7. EXTI_PORTG
*/
void EXTI_vSelectPort(uint8 Copy_u8Line , uint8 Copy_u8Port)
{
	if(Copy_u8Line <= 3)
	{
		AFIO->EXTICR1 &= ~(0xF << Copy_u8Line*4);
		AFIO->EXTICR1 |= (Copy_u8Port << Copy_u8Line*4);
	}
	else if(Copy_u8Line <= 7)
	{
		Copy_u8Line = Copy_u8Line - 4;
		AFIO->EXTICR2 &= ~(0xF << Copy_u8Line*4);
		AFIO->EXTICR2 |= (Copy_u8Port << Copy_u8Line*4);
	}
	else if(Copy_u8Line <= 11)
	{
		Copy_u8Line = Copy_u8Line - 8;
		AFIO->EXTICR3 &= ~(0xF << Copy_u8Line*4);
		AFIO->EXTICR3 |= (Copy_u8Port << Copy_u8Line*4);
	}
	else if(Copy_u8Line <= 15)
	{
		Copy_u8Line = Copy_u8Line - 12;
		AFIO->EXTICR4 &= ~(0xF << Copy_u8Line*4);
		AFIO->EXTICR4 |= (Copy_u8Port << Copy_u8Line*4);
	}
}


/**************************************************************************************************************************/

void EXTI0_IRQHandler(void)
{
	if (GP_EXT0 != NULL)
	{
		GP_EXT0();
	}
	SET_BIT(EXTI->PR , 0);
}

/**************************************************************************************************************************/

void EXTI1_IRQHandler(void)	
{
	if (GP_EXT1 != NULL)
	{
		GP_EXT1();
	}
	SET_BIT(EXTI->PR , 1);
}


/**************************************************************************************************************************/

void EXTI2_IRQHandler(void)	
{
	if (GP_EXT2 != NULL)
	{
		GP_EXT2();
	}
	SET_BIT(EXTI->PR , 2);
}

/**************************************************************************************************************************/

void EXTI3_IRQHandler(void)	
{
	if (GP_EXT3 != NULL)
	{
		GP_EXT3();
	}
	SET_BIT(EXTI->PR , 3);
}

/**************************************************************************************************************************/

void EXTI4_IRQHandler(void)	
{
	if (GP_EXT4 != NULL)
	{
		GP_EXT4();
	}
	SET_BIT(EXTI->PR , 4);
}

/**************************************************************************************************************************/