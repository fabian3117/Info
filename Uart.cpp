/*
 * Uart.cpp
 *
 *  Created on: 17 jun. 2022
 *      Author: nahuu
 */

#include <Uart.h>
#include "LPC845.h"

//-->	Escribo en el buffer de Tx
void Uart::UART0_pushTx(uint8_t dato){
	bufferTx[inx_tx_in] = dato;
	inx_tx_in++;
	inx_tx_in %= TXBUFFER_SIZE;

	if(txStart == 0){   //si no hay transmisión activa.... la activo
		txStart = 1;
		//Escribo TXDAT y activo int Tx. Es una macro para no pinchar capas
		START_TX();     //#define START_TX()	( USART0->INTENSET = (1 << 2); ) // int tx
	}

}
//-->	Creo que esta es la interrupcion por lo tanto tengo que modificarla	<--

uint16_t Uart::UART0_popTx(void)
{
	uint16_t dato = -1;

	if(inx_tx_in != inx_tx_out){
		dato = (uint8_t) bufferTx[inx_tx_out];
		inx_tx_out++;
		inx_tx_out %= TXBUFFER_SIZE;
	}
	return dato;
}
//-->	Cargo mi buffer de recepcion	<--
void Uart::UART0_pushRx(uint8_t dato)
{
	bufferRx[inx_rx_in] = dato;
	inx_rx_in++;
	inx_rx_in %= RXBUFFER_SIZE;
}
//-->	Lectura del buffer de recepcion	<--
int16_t Uart::UART0_popRx(void)
{
	int16_t dato = -1;

	if(inx_rx_in != inx_rx_out){
		dato = (uint16_t) bufferRx[inx_rx_out],
		inx_rx_out++;
		inx_rx_out %= RXBUFFER_SIZE;
	}
	return dato;
}
//-->	Funcion de alto nivel para envio de cadenas	<--
void Uart::EnviarString (const char *str)
{
	uint8_t i;
	for( i = 0 ; str[i] ; i++ )
		UART0_pushTx(str[i]);
}
void Uart::EnviarString_Entero (uint8_t ENTERO)
{
	uint8_t i;
	for( i = 0 ; ENTERO ; i++ )
		UART0_pushTx(ENTERO);
}
//-->	Inicio la transmicion desde un buffer	<--
int16_t Uart::Transmitir (const void * datos , uint8_t cant )
{
	uint8_t	i;

	if ( cant > MAX_DATOS )
		return -1;

	if (cant == 0)
		cant = (uint8_t)strlen ((const char *)datos);

	for ( i = 0 ; i < cant ; i++ )
		UART0_pushTx( * ( ( uint8_t * ) ( datos + i ) ) );

	return 0 ;
}


//-->	Constructor que inicializa todo con tema de registros	<--
Uart::Uart(){
	uint8_t Uart0=14;
	uint8_t Reset_Uart0=14;


	//SYSCON_Type->SYSAHBCLKCTRL0|=(0x1<<Uart0);	//-->	Le Pongo un 1 en el bit 14 para poder activar UART0	<--0
	//-->	Activar los bits asociados en SYSAHBCLKCTRL  para activar el clock	<--
	//-->	Limpia el peliferico  usando PRESETCTRL	<--
	//PRESETCTRL0|(0x1<<Reset_Uart0);
	//USART0->INTENSET=(1);	//-->	Interrupciones
	//-->	El buffer esta en el registro RXDAT|(0xFF)	--
	//-->	Activar la interrupcion	<--
	//-->	Configura los PINES en la matriz	<--
	//PINASSIGN0
	//uint32_t *PinAsig0=	0x4000C000;
	//*PinAsig0=(0x1918);
}
