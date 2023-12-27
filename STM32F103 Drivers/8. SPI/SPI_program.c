/*
 * SPI_program.c
 *
 *  Created on: Jun 25, 2023
 *      Author: MERNA
 */

#include "STD_types.h"
#include "BIT_math.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SPI_private.h"
#include "SPI_interface.h"
#include "SPI_config.h"

/**********************************************************************************************/
void SPI_vInit(void)
{
	// Enable Alternate function
	RCC_u8EnablePeripheralClk(RCC_u8_APB2_BUS, AFIOEN);
	//Enable GPIOA
	RCC_u8EnablePeripheralClk(RCC_u8_APB2_BUS, GPIOA_EN);
	//Enable SPI1
	RCC_u8EnablePeripheralClk(RCC_u8_APB2_BUS, SPI1EN);
	#if defined SPI_MASTER_STATUS
	//Initialize MISO PIN as input
	GPIO_vSetPinMode(GPIO_PORT_A, SPI1_MISO_PIN, GPIO_PIN_INPUT);
	GPIO_vSetPinConfig(GPIO_PORT_A, SPI1_MISO_PIN, GPIO_IN_PULL);
	//Initialize MOSI as AF Push pull
	GPIO_vSetPinMode(GPIO_PORT_A, SPI1_MOSI_PIN, GPIO_PIN_OUTPUT_SPD_50);
	GPIO_vSetPinConfig(GPIO_PORT_A, SPI1_MOSI_PIN, AFIO_PUSHPULL);
	//Initialize SCK as AF push pull
	GPIO_vSetPinMode(GPIO_PORT_A, SPI1_SCK_PIN, GPIO_PIN_OUTPUT_SPD_50);
	GPIO_vSetPinConfig(GPIO_PORT_A, SPI1_SCK_PIN, AFIO_PUSHPULL);
	//Initialize SS as output
	GPIO_vSetPinMode(GPIO_PORT_A, SPI1_SS_PIN, GPIO_PIN_OUTPUT_SPD_50);
	GPIO_vSetPinConfig(GPIO_PORT_A, SPI1_SS_PIN, GPIO_OUT_PUSHPULL);

	
	SET_BIT(SPI1->CR1,SPI_CR1_MSTR);
	SPI1->CR1 |= SPI_SCK_FREQ << SPI_CR1_BR; //fclk/2
	SET_BIT(SPI1->CR2,SPI_CR2_SSOE);

	CLR_BIT(SPI1->CR1,SPI_CR1_DFF); // 8bit/frame
	//put 1 at SS
	GPIO_vSetPinValue(GPIO_PORT_A, SPI1_SS_PIN, HIGH);
	#else
		//Initialize MISO PIN as input
	GPIO_vSetPinMode(GPIO_PORT_A, SPI1_MISO_PIN, GPIO_PIN_OUTPUT_SPD_50);
	GPIO_vSetPinConfig(GPIO_PORT_A, SPI1_MISO_PIN, AFIO_PUSHPULL);
	//Initialize MOSI as AF Push pull
	GPIO_vSetPinMode(GPIO_PORT_A, SPI1_MOSI_PIN, GPIO_PIN_INPUT);
	GPIO_vSetPinConfig(GPIO_PORT_A, SPI1_MOSI_PIN, GPIO_IN_PULL);
	//Initialize SCK as AF push pull
	GPIO_vSetPinMode(GPIO_PORT_A, SPI1_SCK_PIN, GPIO_PIN_INPUT);
	GPIO_vSetPinConfig(GPIO_PORT_A, SPI1_SCK_PIN, GPIO_IN_FLOATING);
	//Initialize SS as output
	GPIO_vSetPinMode(GPIO_PORT_A, SPI1_SS_PIN, GPIO_PIN_INPUT);
	GPIO_vSetPinConfig(GPIO_PORT_A, SPI1_SS_PIN, GPIO_IN_PULL);
	
	CLR_BIT(SPI1->CR1,SPI_CR1_MSTR);
	#endif
	
	//enable peripheral
	SET_BIT(SPI1->CR1,SPI_CR1_SPE);
	
}

/**********************************************************************************************/

void SPI_vSendData(uint8 Copy_u8Data)
{
	//select slave
	GPIO_vSetPinValue(GPIO_PORT_A, SPI1_SS_PIN, LOW);
	SPI1->DR = Copy_u8Data;
	while(READ_BIT(SPI1->SR,SPI_SR_BSY) == 1);
	GPIO_vSetPinValue(GPIO_PORT_A, SPI1_SS_PIN, HIGH);
}

/**********************************************************************************************/

void SPI_vSendString(uint8* Copy_u8String)
{
	uint8* LOC_string = Copy_u8String;
	GPIO_vSetPinValue(GPIO_PORT_A, SPI1_SS_PIN, LOW);
	while(*LOC_string != '\0')
	{
		SPI1->DR = *LOC_string;
		while(READ_BIT(SPI1->SR,SPI_SR_BSY) == 1);
		LOC_string++;
	}
	GPIO_vSetPinValue(GPIO_PORT_A, SPI1_SS_PIN, HIGH);
}

/**********************************************************************************************/

uint8 SPI_u8Receive(uint8 Copy_u8Data)
{
	uint8 Return_value;
	while(READ_BIT(SPI1->SR,SPI_SR_BSY) == 1);
	SPI1->DR = Copy_u8Data;
	while(READ_BIT(SPI1->SR,SPI_SR_RXNE) == 0);
	Return_value = SPI1->DR;
	return Return_value;
}

/**********************************************************************************************/
