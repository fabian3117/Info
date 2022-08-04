#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "LPC845.h"
#include "fsl_debug_console.h"
#include "system_LPC845.h"
#include "General.h"
#include "Gpio.h"
//#define   START_TX()	USART0->INTENSET = (1 << 2)
#include "Leds.h"
#include "DrivSistick.h"
#include "LPC845.h"
#include "timer.h"
#include "Inicializador.h"


//-->	Para jugar con UART	<--
static volatile char buff_RX_UART0[]={0,0};
static volatile char indice_RX_UART0=0;
static volatile char buff_TX_UART0[]={0xFF,0xFF};
static volatile char indice_TX_UART0=0;

volatile int Tiempo=0;
volatile char Buff;
static volatile int control=0;

#include "inicializador.h"
#include "TimerMachine.h"
#include "dr_pll.h"
void Inicia_I2C(void);
void Envia(uint8_t Dir,uint8_t dat);
int main(void) {


   BOARD_InitBootPins();
   BOARD_InitBootClocks();
   BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL

BOARD_InitDebugConsole();
#endif
   // Inicializar_PLL( );
Inicializador::Inicia();
    Inicializador::Inicializar_SYSTICK();	//-->	Tengo mi objeto que se encarga de la inicializacion de mis pelifericos

    //Inicializador::Inicializar_UART0();


//Leds L_Roj=Leds(2,1);	//-->	Se activa directamente por que utiliza el define que pone un false "0"  y estos led se prenden activo bajo	<--
 //  L_Roj.SetEstado(true);	//-->	Como son Activo bajo - Tengo que mandar un 1 para apagar	<--
//Leds L_Roj=Leds(1,1);
//L_Roj.SetEstado(false);
bool estado=false;
    //Inicializador::Inicializar_Pin_Interrupcion(0, 0);

    while(1) {

    	Timer_Machine::TimerEvent();

    	Gpio proba=Gpio(1,0,SALIDA,1);
    	proba.Activa();
    	Gpio Interes=Gpio(0,0,ENTRADA);
    	Interes.Activa();
//    Timer_Machine::TimerEvent(void);
//    	TimerEvent(void);
        //-->	Para los estados puedo tener objeto estatico	<--
    //contador+=1;

    	if(Tiempo>=4*8000){
    		PRINTF((Interes.GetPIN()==0)?"ESTADO 1\n\r":"ESTADO 0 \n\r");
    		//PRINTF("Estado del pin :\n\r"+(Interes.GetPIN()==0)?"1":"0");
    		Tiempo=0;
    		//L_Roj.SetEstado(estado);
    		estado=!estado;
    	//	/contador=(contador=0)?1:0;
    		//estado=!estado;
    		//USART0->TXDAT=0x0F;
    	}
    }
    return 0 ;
}
void Inicia_I2C(void){
	SYSCON->SYSAHBCLKCTRL0|=(1<<5);
	SYSCON->PRESETCTRL0&=~(1<<5);

	I2C0->INTENSET|=(1<<0);	//-->	Habilita interrupciones	<--
	//-->	Asignacion de pines con puertos	<--
	SWM0->PINENABLE0&=~(3<<12);
	uint8_t ModoMaestro=1;
	I2C0->CFG&=(ModoMaestro<<0);
}
void Envia(uint8_t Dir,uint8_t dat){
	I2C0->MSTDAT|=(Dir);

}
