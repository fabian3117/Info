/*
 * I2.cpp
 *
 *  Created on: 15 jul. 2022
 *      Author: nahuu
 */

#include <I2.h>

void I2::ManejoInterrupcion(){
	//-->	Interrumpe por dato enviado - recibido o que?	<--
	//bool enviando=I2C0->INTSTAT&(0x1);	//-->	Indica que el maestro esta esperando para continuar la comunicacion - o esta en modo IDLE	<--
	//-->	Ese bit puedo usarlo para saber cuando continuar la transmision o iniciarla	<--
	uint8_t Estado=(I2C0->INTSTAT&(0xF<<1)>>1);	//-->	Aca esta el estado actual de la interrupcion	<--

	switch(Estado){
	case IDLE:
		//-->	Esta en modo IDLE - Esta listo para enviar mas datos	<--

		break;

	case RX_AB:
		//-->	Tengo datos disponible recibidos - Maestro en modo recepcion	<--

		break;
	case Listo_Transmite:
		//-->	Listo para transmitir datos - Maestro en modo transmision	<--
		break;
	case NACK_Add:
		break;
	case NACK_Dat:
		break;
	}

}
void I2::push(uint8_t dir,uint8_t dat){
	//-->	Tengo
	indic=(indic+2>=Tam_Buf)?0:indic+2;
	Buff[indic]=dir;
	Buff[indic+1]=dat;
}
uint8_t I2::pushDat(){
	return Buff[indic+1];
}
uint8_t I2::pushDir(){
	return Buff[indic];
}
void I2::Clear(uint8_t Indi){
	if(Indi<Tam_Buf){
		Buff[indic]=0x0;
		Buff[indic+1]=0x0;
	}
}
