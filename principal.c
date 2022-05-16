#include "./general.h"
#define SystemCoreClock 18000000U
#define DV_FRC_TMR 1000
void Inicializacion (void){
	 SysTickInic (SystemCoreClock/DV_FRC_TMR); //Con esta configuracion, el stick interrumpe cada 4 ms

	//-->	Todo lo de I2C esta en pagina 331	<--
	//-->	Activar el clock de la interfaz (Activar el pin)	<--
	//-->	SYSAHBCLKCTRL	Poner un 1 en bit 5 <--
	//SYSCON->
	 SWM0->PINENABLE0&=~(0x3<<12);
	 IOCON->PIO[IOCON_INDEX_PIO0_11]|=(0x2<<8);
	 IOCON->PIO[IOCON_INDEX_PIO0_10]|=(0x2<<8);
	uint8_t mask_I2C_0=(0x3<<5);
	//SYSCON->SYSAHBCLKCTRL0
//	(0x40048080u)=(0x1<<5);
	SYSCON->SYSAHBCLKCTRL0|=mask_I2C_0;	//-->	Pongo un 1 en el bit de activacion clock de pines I2C0
	SYSCON->FCLKSEL[5]&=(0xFFFFFFF1);	//-->	Esto deberia enviar al I2C el clock principal	<--
	//-->	Ahora reinicio el peliferico	<--
	//-->	PRESETCTRL		Poner en 1 el bit 5 para I2C0	<--
	//SYSCON->PRESETCTRL0|=(0x1<<5);

	//-->	Ahora tengo que habilitar las interrupciones del I2C0	<--

	//I2C0_BASE=(0x151);
	//ISER0=(0x1<<8);	//-->	Puedo hacer esto por que escribir 0 no tiene efecto aca	<--
	I2C0->INTENCLR=1;
	I2C0->INTENSET=1;
	I2C0->STAT=1;
	I2C0->CFG=(0x2);	//-->	I2C_0	Registro de configuracion	<--
	//I2C0->SLVADR[0]=(0x7);
		//-->	Tengo que limpiar las demas interrupciones creoo	<--


	//-->	NVIC	No entendi	<--
	//-->	Uso la tabla ISER0  bit 8 con un 1	Para habilitar la interrupcion de I2C0 	<--

	//-->	La tabla INTENCLR Limpia y habilita pelifericos	<--


	//-->	Tengo que habilitar el SDA y SCL	<--
	SWM0->PINENABLE0&=~(0x3<<12);	//-->	Tengo que hacer con un and de tal manera de poner en 0 los bit 12-13	<-- ~(0x2<<12)

	//-->	Ahora voy a poner el I2C modo Esclavo	<--
	//CFG
}

void I2C0_IRQHandler(void){
	uint8_t datos=0;
	PRINTF("ENTRO INTERRUPCION");
	datos=(I2C0->SLVDAT&0xFF);	//-->	Elimino la basura osea los bits del 8 en adelante
	return;
}