/*
 * I2.h
 *
 *  Created on: 15 jul. 2022
 *      Author: nahuu
 */

#ifndef I2_H_
#define I2_H_
#include "Inicializador.h"
#define Tam_Buf 10
//-->	Por ahora hago que esta clase se encargue de los buffers solamente	<--

class I2 {
private:
	//-->	Cambiare el buffer por uno circular	<--

	static uint8_t Buff[Tam_Buf];	//-->	Se lee de 2 en 2 Por que contiene el par Direccion - Dato	<--
	static uint8_t indic;
	static uint8_t Cant;
	enum {
		IDLE=0x0,
		RX_AB=0x1,
		Listo_Transmite=0x2,
		NACK_Add=0x3,
		NACK_Dat=0x4
	};
public:
	uint8_t getDir();		//-->	Retorna la direccion del dispocitivo a comunicarse		<--
	uint8_t getDat();		//-->	Retorna el dato a enviar al dispositivo a comunicarse	<--
	static void push(uint8_t dir,uint8_t dat);	//-->	Cargo al buffer otro par DIR-DAT		<--
	uint8_t pushDat();		//-->	Retorno el dato apuntado	<--
	uint8_t pushDir();		//-->	Retorno la direccion		<--
	void Clear(uint8_t);	//-->	Saco un dir-dar del buff	<--
	static void ManejoInterrupcion(void);
	const bool Read=1;
	const bool Write=0;
};

#endif /* I2_H_ */
