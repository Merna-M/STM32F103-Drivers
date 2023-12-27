/*
 * SPI_interface.h
 *
 *  Created on: Jun 25, 2023
 *      Author: MERNA
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_


/****************************** Macros ***********************************/
/* SPI1 Pins */
#define SPI1_MISO_PIN		6
#define SPI1_MOSI_PIN		7
#define SPI1_SCK_PIN		5
#define SPI1_SS_PIN			4

/* SPI clk */
#define SPI_FCLK_2			0
#define SPI_FCLK_4			1
#define SPI_FCLK_8			2
#define SPI_FCLK_16			3
#define SPI_FCLK_32			4
#define SPI_FCLK_64			5
#define SPI_FCLK_128		6
#define SPI_FCLK_256		7

/* SPI_CR1 Register */
#define SPI_CR1_CPHA		0
#define SPI_CR1_CPOL		1
#define SPI_CR1_MSTR		2
#define SPI_CR1_BR			3
#define SPI_CR1_SPE			6
#define SPI_CR1_LSBFIRST	7
#define SPI_CR1_SSI			8
#define SPI_CR1_SSM			9
#define SPI_CR1_RXONLY		10
#define SPI_CR1_DFF			11
#define SPI_CR1_CRCNEXT		12
#define SPI_CR1_CRCEN		13
#define SPI_CR1_BIDIOE		14
#define SPI_CR1_BIDIMODE	15


/* SPI_SR register */
#define SPI_SR_RXNE			0
#define SPI_SR_TXE			1
#define SPI_SR_CHSIDE		2
#define SPI_SR_UDR			3
#define SPI_SR_CRCERR		4
#define SPI_SR_MODF			5
#define SPI_SR_OVR			6
#define SPI_SR_BSY			7

/****************************** Prototypes *************************************/
/*
 FUNCTION NAME        :
 FUNCTION DESCRIPTION :
 FUNCTION INPUTS      :
 FUNCTION RETURN      :
 */
void SPI_vInit();

/*
 FUNCTION NAME        :
 FUNCTION DESCRIPTION :
 FUNCTION INPUTS      :
 FUNCTION RETURN      :
 */
void SPI_vSendData(uint8 Copy_u8Data);


void SPI_vSendString(uint8* Copy_u8String);

uint8 SPI_u8Receive(void);



#endif /* SPI_INTERFACE_H_ */
