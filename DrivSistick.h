/*
 * DrivSistick.h
 *
 *  Created on: 16 jun. 2022
 *      Author: nahuu
 */

#ifndef DRIVSISTICK_H_
#define DRIVSISTICK_H_
#include "LPC845.h"
/*
#define DV_FRC_TMR 1000
#define Ticks_Preder (SystemCoreClock/DV_FRC_TMR)
typedef struct
		{
			union{
				volatile uint32_t SYST_CSR;
				struct{
					volatile uint32_t ENABLE:1;
					volatile uint32_t TICKINT:1;
					volatile uint32_t CLKSOURCE:1;
					volatile uint32_t RESERVED0:13; //bit 3 a 15
					volatile uint32_t COUNTFLAG:1;
					volatile uint32_t RESERVED1:15; //bit 17 a 31
				}bits;
			};
			volatile uint32_t SYST_RVR;
			volatile uint32_t SYST_CVR;
			volatile uint32_t  SYST_CALIB;
		}systick_t;

#define 	SYSTICK		( (systick_t *) 0xE000E010UL )

class Driv_Sistick {
public:
			Driv_Sistick(uint32_t Ticks=Ticks_Preder);	//-->	Constructor y Genera el inicio del systick	<--
private:

		__IO uint8_t SYST_CSR	=	SYSTICK->SYST_CSR;
		__IO uint8_t ENABLE		=	SYSTICK->bits.ENABLE;
		__IO uint8_t TICKINT	=	SYSTICK->bits.TICKINT;
		__IO uint8_t CLKSOURCE	=	SYSTICK->bits.CLKSOURCE;
		__IO uint8_t COUNTFLAG	=	SYSTICK->bits.COUNTFLAG;
		__IO uint8_t SYST_RVR	=	SYSTICK->SYST_RVR;
		__IO uint8_t SYST_CVR	=	SYSTICK->SYST_CVR;
		__IO uint8_t SYST_CALIB	=	SYSTICK->SYST_CALIB;
		__IO uint8_t Ticks;
};
*/

#endif /* DRIVSISTICK_H_ */
