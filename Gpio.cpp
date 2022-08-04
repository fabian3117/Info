/*
 * Gpio.cpp
 *
 *  Created on: 16 jun. 2022
 *      Author: nahuu
 */

#include "Gpio.h"

Gpio::Gpio(uint32_t PIN,uint32_t PUERTO,bool Modo,bool ESTADO,uint8_t ELECTRICO) {
Pin=(PIN>Max_Pin)?Pin_Defect:PIN;
Puerto=(PUERTO>Max_Port)?Port_Defect:PUERTO;
Salida=Modo;
Estado=ESTADO;
Modo_Electrico=ELECTRICO;
}
void Gpio::Activa(){
	//-->	Realiza los ajustes adecuados para activar el pin	<--
	//-->	Por como hice todo el puerto 0,0 Esta por defecto asi que en caso de no configurarse bien se va ahi	<---

	SetDIR();	//-->	Configuro como Entrada	-	Salida	<--
	SetPIN();	//-->	Le escribo un valor	(Cosas a ver como cambiar ese valor luego)	<--

}
void Gpio::ActivaInterrupcion(){
	if(Salida==SALIDA){
		return;
	}
	//-->	Primero lo pongo como GPIO entrada	<--

		SYSCON->SYSAHBCLKCTRL0 |= (1 << 6);
		GPIO->DIRSET[Puerto] = (uint32_t)(1 << Pin);	//-->	Es una ENTRADA	<--

			//-->	Habilito la interrupcion	<--

		SYSCON->PINTSEL[0]=(Puerto<=0)?Pin:(Pin+32);	//-->	Conecto la interrupcion 0 Con el Pin GPIO que quiero	<--


}
void Gpio::SetEstado(bool N_Estado){
	Estado=N_Estado;
	Activa();	//-->	Aplico los cambios	<--
}

/*	-->	Escribe un valor en el Pin de la GPIO	<--
 * 	-->	Sin parametros por que todos estan en el objeto	<--
 */
void Gpio::SetPIN(){
	if(Estado)
			GPIO->SET[Puerto] = (uint32_t)(1 << Pin);	//--> Escribo un "1"	<--
		else
			GPIO->CLR[Puerto] = (uint32_t)(1 << Pin);	//--> Escribo "0" Aca prendo la led	<--

}
/*	--->	Configura un Puerto de GPIO como ENTRADA - SALIDA	<--
 *
 */
void Gpio::SetDIR(){
	if(Salida)
			GPIO->DIRSET[Puerto] = (uint32_t)(1 << Pin);	//-->	Es una ENTRADA	<--
		else
			GPIO->DIRCLR[Puerto] = (uint32_t)(1 << Pin);	//-->	Es una SALIDA	<--
}
/*
 * 	-->	Leo el valor de una entrada GPIO	<--
 */
uint32_t Gpio::GetPIN(){
	if(GPIO->PIN[Puerto] & ((uint32_t)(1 << Pin)))
		{
			// Entro por 1	Alto	<---
			return 1;
		}
		else
		{
			// Entro por 0	Bajo	<---
			return 0;
		}

}
//	-->	Configura el modo electrico de una entrada	<--
void Gpio::SetPINMODE_IN(){
	//-->	Tengo que calcular el Offset usando Puerto Pin pero como?	<--

	uint32_t PuertoPin=0;
	IOCON->PIO[PuertoPin] = ((IOCON->PIO[PuertoPin] & (~(IOCON_PIO_MODE_MASK))) | IOCON_PIO_MODE(Modo_Electrico));
}
//	-->	Configura el modo electrico de una salida	<--

void Gpio::SetPINMODE_OUT(){
	uint32_t PuertoPin=0;
	IOCON->PIO[PuertoPin] = ((IOCON->PIO[PuertoPin] & (~(IOCON_PIO_OD_MASK))) | IOCON_PIO_OD(Modo_Electrico));

}
