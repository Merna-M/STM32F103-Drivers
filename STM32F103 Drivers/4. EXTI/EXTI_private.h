/***************************************************************************/
/* Author  : MERNA */
/* Version : 01    */
/***************************************************************************/

#ifndef _EXTI_PRIVATE_H
#define _EXTI_PRIVATE_H

#define EXTI_BASE_ADDRESS			0x40010400

typedef struct 
{
	volatile uint32 IMR;
	volatile uint32 EMR;
	volatile uint32 RTSR;
	volatile uint32 FTSR;
	volatile uint32 SWIER;
	volatile uint32 PR;
}EXTI_Reg_t;

#define EXTI 		((EXTI_Reg_t*)EXTI_BASE_ADDRESS)


#endif