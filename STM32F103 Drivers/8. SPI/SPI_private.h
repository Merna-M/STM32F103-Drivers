/*
 * SPI_private.h
 *
 *  Created on: Jun 25, 2023
 *      Author: MERNA
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define SPI_BASE_ADDRESS		(0x40013000)

typedef struct
{
	volatile uint32 CR1;
	volatile uint32 CR2;
	volatile uint32 SR;
	volatile uint32 DR;
	volatile uint32 CRCPR;
	volatile uint32 RXCRCR;
	volatile uint32 TXCRCR;
	volatile uint32 I2SCFGR;
	volatile uint32 I2SPR;
}SPI_t;

#define SPI1		((SPI_t*)(SPI_BASE_ADDRESS))

#endif /* SPI_PRIVATE_H_ */
