/*
 * Gpio.h
 *
 *  Created on: 16 jun. 2022
 *      Author: nahuu
 *      Objeto GPIO
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "LPC845.h"

#define SALIDA		1
#define ENTRADA 	0

#define NO_PULL		0x00
#define PULL_DOWN	0x01
#define PULL_UP		0x02
#define REP			0x03

#define PUSH_PULL	0x00
#define OPEN_DRAIN	0x01

#define Port_Defect 0x0	//-->	Puerto por defecto por si las dudas	<--
#define Pin_Defect  0x0	//-->	Pin por defecto por si las dudas	<--
#define Max_Port 2
#define Max_Pin 31
#define Entrada_Defect ENTRADA
#define Estado_Defect false

//-->	Esta clase es como el controlador de GPIO con un pin asociado	<--
//-->	Tengo que tener en cuenta que si quiero cambiar el pin de entrada a salida  debo permitirlo	<--
class Gpio{
public:
	Gpio(uint32_t PIN=0,uint32_t PUERTO=Pin_Defect,bool Modo=Entrada_Defect,bool ESTADO=Estado_Defect,uint8_t ELECTRICO=NO_PULL);
	//virtual ~Gpio();
	void Activa();	//-->	Con todo cargado activa el Pin como este configurado	<--
	void SetEstado(bool);
	//void SetSalida(bool);
	void SetPIN();
	void SetDIR();
	uint32_t GetPIN();	//-->	Verifico el estado de un pin	<--
	void SetPINMODE_IN();
	void SetPINMODE_OUT();
	//-->	Voy a sobrecargar el operador ! para poder invertir el estado de una GPIO	<--
	//Gpio operator!();
	void ActivaInterrupcion();	//-->	Activa la interrupcion del PIN	<--
private:
	uint32_t Pin;
	uint32_t Puerto;
	bool Salida;
	bool Estado;
	uint8_t Modo_Electrico;
};

#endif /* GPIO_H_ */
