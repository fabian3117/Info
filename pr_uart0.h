#ifndef PR_UART0_H_
#define PR_UART0_H_

#include "LPC845.h"
#include "pr_uart0.h"


#define TXBUFFER_SIZE	120    //arbitrario
#define RXBUFFER_SIZE	120    //arbitrario
#define MAX_DATOS	    30     //arbitrario

//Primitivas de recepción y transmisión. No están comprometidas con el HW
void UART0_pushTx(uint8_t dato);
uint16_t UART0_popTx(void);
void UART0_pushRx(uint8_t dato);
int16_t UART0_popRx(void);
void EnviarString (const char *str);
int16_t Transmitir (const void * , uint8_t );
void EnviarString_Entero (uint8_t ENTERO);
//------------------------------------------------------------------------

//Macro definida para arrancar la Tx y no pinchar capas
#define   START_TX()	USART0->INTENSET = (1 << 2)


#endif /* PR_UART0_H_ */
