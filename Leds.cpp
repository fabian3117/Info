/*
 * Leds.cpp
 *
 *  Created on: 16 jun. 2022
 *      Author: nahuu
 */

#include "Leds.h"

void Leds::SetStatus(bool statud){
	SetEstado(statud);
	//Estado=statud;
	Activa();

}
void Leds::Apagar(){

SetEstado(false);
Activa();
}
void Leds::Prender(){

	SetEstado(true);
	Activa();

}
