
#include <TimerMachine.h>

void Timer_Machine::AnalizarTimers(){
//-->	Realiza los decrementos a cada vector contador	<--
	uint32_t i;
	/*
	extern uint32_t Tmr_Run[ N_TIMERS ];

		for(i=0; i< N_TIMERS ; i++)
		{

			if(Tmr_Run[ i ])
			{
				if ( !TMR_StandBy[ i ] )
				{
					Tmr_Run[ i ]--;
					if(!Tmr_Run[ i ])
						TMR_Events[ i ] = 1;
				}
			}


} */
		//-->	Tengo que ver como incrementar los cronometros	<--
		for(i=0;i<Cantidad_Cronom;i++){
			//Cronometros[i]++;
		}
}
void Timer_Machine::TimerEvent(){
	//-->	LLama a las funciones asociadas de los timers vencidos <--
	//-->	Debe llamarse en el loop principal de la funcion	<--
	uint8_t i;
		for( i=0 ; i < N_TIMERS ; i++ )
		{


			if(Timer_Machine::TMR_Events[ i ])
			{
			//TMR_handlers[ i ]( );	//-->	Invoco a la funcion asociada con este timer	<--
				//TMR_Events[ i ] = 0;	//-->	Limpio el timer asociado
			}

		}
}
void Timer_Machine::TimerStart(uint8_t event, uint32_t time, Timer_Handler handler , uint8_t base){
	switch ( base )
		{
			case DEC:
				time *= DECIMAS;
				break;
			case SEG:
				time *= ( SEGUNDOS * DECIMAS );
				break;
			case MINU:
				time *= ( MINUTOS * SEGUNDOS * DECIMAS );
				break;
		}

		Tmr_Base[event] = base;

		if(time != 0)	//el tiempo no es 0, lo cargo
		{
			Tmr_Run[event] = time;
			TMR_Events[event] = 0;
		}
		else	//el tiempo es cero, el timer vence automáticamente
		{
			Tmr_Run[event] = 0;
			TMR_Events[event] = 1;
		}
		TMR_handlers[event] = handler;
}
void Timer_Machine::SetTimer(uint8_t event,uint32_t time){
	switch ( Tmr_Base[event] )
		{
			case DEC:
				time *= DECIMAS;
				break;
			case SEG:
				time *= ( SEGUNDOS * DECIMAS );
				break;
			case MINU:
				time *= ( MINUTOS * SEGUNDOS * DECIMAS );
				break;
		}
		Tmr_Run[event] = time;
}
uint32_t Timer_Machine::GetTimer(uint8_t event){
	uint32_t time = Tmr_Run[event];

		switch ( Tmr_Base[event] )
		{
			case DEC:
				time /= DECIMAS;
				break;
			case SEG:
				time /= ( SEGUNDOS * DECIMAS );
				break;
			case MINU:
				time /= ( MINUTOS * SEGUNDOS * DECIMAS );
				break;
		}
		return time;
}
void Timer_Machine::StandByTimer(uint8_t event,uint8_t accion){

	TMR_StandBy[event]=accion;
}
