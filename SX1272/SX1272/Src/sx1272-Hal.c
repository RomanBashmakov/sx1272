/*
 * THE FOLLOWING FIRMWARE IS PROVIDED: (1) "AS IS" WITH NO WARRANTY; AND 
 * (2)TO ENABLE ACCESS TO CODING INFORMATION TO GUIDE AND FACILITATE CUSTOMER.
 * CONSEQUENTLY, SEMTECH SHALL NOT BE HELD LIABLE FOR ANY DIRECT, INDIRECT OR
 * CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE CONTENT
 * OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING INFORMATION
 * CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 * 
 * Copyright (C) SEMTECH S.A.
 */
/*! 
 * \file       sx1272-Hal.c
 * \brief      SX1272 Hardware Abstraction Layer
 *
 * \version    2.0.B2 
 * \date       Nov 21 2012
 * \author     Miguel Luis
 *
 * Last modified by Miguel Luis on Jun 19 2013
 */
#include <stdint.h>
#include <stdbool.h> 

#include "sx1272-Hal.h"
#include "main.h"
#include "stm32l1xx_hal_spi.h"



/*
#define RESET_IOPORT                                GPIOA
#define RESET_PIN                                   GPIO_Pin_1

#define NSS_IOPORT                                  GPIOA
#define NSS_PIN                                     GPIO_Pin_15


#define DIO0_IOPORT                                 GPIOA
#define DIO0_PIN                                    GPIO_Pin_0

#define DIO1_IOPORT                                 GPIOB
#define DIO1_PIN                                    GPIO_Pin_0

#define DIO2_IOPORT                                 GPIOC
#define DIO2_PIN                                    GPIO_Pin_5

#define DIO3_IOPORT                                 
#define DIO3_PIN                                    RF_DIO3_PIN

#define DIO4_IOPORT                                 
#define DIO4_PIN                                    RF_DIO4_PIN

#define DIO5_IOPORT                                 
#define DIO5_PIN                                    RF_DIO5_PIN
#endif

#define RXTX_IOPORT                                 
#define RXTX_PIN                                    FEM_CTX_PIN */


void SX1272InitIo( void )
{
    // Configure NSS as output

    // Configure radio DIO as inputs

    // Configure DIO0
    
    // Configure DIO1
    
    // Configure DIO2
    
    // REAMARK: DIO3/4/5 configured are connected to IO expander

    // Configure DIO3 as input
    
    // Configure DIO4 as input
    
    // Configure DIO5 as input
}

void SX1272SetReset( uint8_t state )
{
    if( state == RADIO_RESET_ON )
    {
        // Set RESET pin to 1
        HAL_GPIO_WritePin(SX1272RESET_GPIO_Port, SX1272RESET_Pin, GPIO_PIN_SET);

        // Configure RESET as output
    }
    else
    {
        // Configure RESET as input
        HAL_GPIO_WritePin(SX1272RESET_GPIO_Port, SX1272RESET_Pin, GPIO_PIN_RESET);
    }
}

void SX1272Write( uint8_t addr, uint8_t data )
{
    SX1272WriteBuffer( addr, &data, 1 );
}

void SX1272Read( uint8_t addr, uint8_t *data )
{
    SX1272ReadBuffer( addr, data, 1 );
}

void SX1272WriteBuffer( uint8_t addr, uint8_t *buffer, uint8_t size )
{
	uint8_t Address[]={addr|0x80 };

    //NSS = 0; Add
	HAL_GPIO_WritePin(NSS_GPIO_Port, NSS_Pin, GPIO_PIN_RESET);

	HAL_SPI_Transmit(&hspi1,&Address[0], 1, 1000);

	//for (int i=0;i<10000;i++);
	//HAL_GPIO_WritePin(NSS_GPIO_Port, NSS_Pin, GPIO_PIN_SET);

	//for (int i=0;i<10000;i++);
	//HAL_GPIO_WritePin(NSS_GPIO_Port, NSS_Pin, GPIO_PIN_RESET);

  	HAL_SPI_Transmit(&hspi1,&buffer[0], size, 1000);

	for (int i=0;i<1000;i++);

    //NSS = 1; Add
	HAL_GPIO_WritePin(NSS_GPIO_Port, NSS_Pin, GPIO_PIN_SET);
}

void SX1272ReadBuffer( uint8_t addr, uint8_t *buffer, uint8_t size )
{
    uint8_t i;
	uint8_t Address[]={addr&0x7F};

    //NSS = 0; Add
	HAL_GPIO_WritePin(NSS_GPIO_Port, NSS_Pin, GPIO_PIN_RESET);

	HAL_SPI_Transmit(&hspi1,&Address[0], 1, 1000);
    HAL_SPI_Receive(&hspi1,&buffer[0], size, 1000);

    //NSS = 1; Add
	HAL_GPIO_WritePin(NSS_GPIO_Port, NSS_Pin, GPIO_PIN_SET);
}

void SX1272WriteFifo( uint8_t *buffer, uint8_t size )
{
    SX1272WriteBuffer( 0, buffer, size );
}

void SX1272ReadFifo( uint8_t *buffer, uint8_t size )
{
    SX1272ReadBuffer( 0, buffer, size );
}

uint8_t SX1272ReadDio0( void )
{
	return HAL_GPIO_ReadPin(DIO0_GPIO_Port, DIO0_Pin);//return GPIO_ReadInputDataBit( DIO0_IOPORT, DIO0_PIN );
}

uint8_t SX1272ReadDio1( void )
{
	return HAL_GPIO_ReadPin(DIO1_GPIO_Port, DIO1_Pin);//return GPIO_ReadInputDataBit( DIO1_IOPORT, DIO1_PIN );
}

uint8_t SX1272ReadDio2( void )
{
	return HAL_GPIO_ReadPin(DIO2_GPIO_Port, DIO2_Pin);//return GPIO_ReadInputDataBit( DIO2_IOPORT, DIO2_PIN );
}

uint8_t SX1272ReadDio3( void )
{
	return HAL_GPIO_ReadPin(DIO3_GPIO_Port, DIO3_Pin);//return IoePinGet( RF_DIO3_PIN );
}

uint8_t SX1272ReadDio4( void )
{
    //return IoePinGet( RF_DIO4_PIN );
}

uint8_t SX1272ReadDio5( void )
{
    //return IoePinGet( RF_DIO5_PIN );
}

/* inline void SX1272WriteRxTx( uint8_t txEnable )
{
    if( txEnable != 0 )
    {
        IoePinOn( FEM_CTX_PIN );
    }
    else
    {
        IoePinOff( FEM_CTX_PIN );
    }
}*/
