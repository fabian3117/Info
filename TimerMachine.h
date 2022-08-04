/*
 * TimerMachine.h
 *
 *  Created on: 8 jul. 2022
 *      Author: nahuu
 */

#ifndef TIMERMACHINE_H_
#define TIMERMACHINE_H_



#include	"LPC845.h"
//-->	Macros	<--
#define 	DEC			0
#define 	SEG			1
#define 	MINU		2

//#define 	RUN			false
//#define 	PAUSE		true
#define 	N_TIMERS		30
/*
DV_FRC_TMR
	1000  1ms
	 250  4ms
	 100 10ms
 */

#define 	DV_FRC_TMR		1000
#define 	DECIMAS			(DV_FRC_TMR/10)
#define 	SEGUNDOS		10
#define 	MINUTOS			60

#define Cantidad_Cronom 4

typedef void (*Timer_Handler)(void);

class Timer_Machine {
public:
	const bool RUN=false;
	const bool PAUSE=true;
	//-->	Inicializacion	<--

	//-->	Funciones	<--
	static  void TimerEvent(void);
	static void AnalizarTimers(void);
	static void TimerStart(uint8_t event, uint32_t time, Timer_Handler handler , uint8_t base );
	static void SetTimer( uint8_t event, uint32_t time );
	static uint32_t GetTimer( uint8_t event );
	static void StandByTimer( uint8_t event , uint8_t accion);
	static void TimerStop(uint8_t event);

	//-->	Variables globales	<--
	volatile static uint32_t Tmr_Run[ N_TIMERS ];
	static  uint8_t  TMR_Events[ N_TIMERS ];
	static void 	 	(* TMR_handlers [N_TIMERS]) (void);
	volatile static uint8_t  TMR_StandBy[ N_TIMERS ];
	static uint8_t  Tmr_Base[ N_TIMERS ];

	//-->	Cronometros	<--
	static void CronometroStart(uint8_t Cronometro);
	static void CronometroStop(uint8_t Cronometro);
	//-->	Variables/Constantes de Cronometros	<---

	static uint32_t Cronometros[Cantidad_Cronom];	//-->	Cuento los ms
	static uint8_t Crono_Activos;	//-->	Cantidad de cronometros activos	<--
};
//uint8_t Timer_Machine::TMR_Events[0]=0;
#endif /* TIMERMACHINE_H_ */
