/*
 * DrivSistick.cpp
 *
 *  Created on: 16 jun. 2022
 *      Author: nahuu
 */

#include <DrivSistick.h>

//-->	Constructor del Systick	<--
/*
Driv_Sistick::Driv_Sistick(uint32_t Ticks){
	if ((Ticks - 1UL) > 0xFFFFFF)
	    {
		this->Ticks=Ticks_Preder;
		Ticks=Ticks_Preder;

	     // return (1UL);                                                   /* Reload value impossible */
//	    }
	//	SYST_RVR = (uint32_t)(Ticks - 1UL);
		//SYST_CVR = 0;

		//CLKSOURCE = 1;
		//ENABLE = 1;
		//TICKINT = 1;

//}

