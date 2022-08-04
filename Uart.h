//-->	Clase que se encarga de manejar la UART	<--

#ifndef UART_H_
#define UART_H_
#include "LPC845.h"
#include "string.h"


#define   START_TX()	USART0->INTENSET = (1 << 2)	//-->	Con esto inicio Tx y no Pincho Capas	<--

#define TXBUFFER_SIZE	120    //arbitrario
#define RXBUFFER_SIZE	120    //arbitrario
#define MAX_DATOS	    30     //arbitrario

//-->	El objeto UART es generico y tiene un flag que indica cual es la asociada	<--

//-->	Falta conectarlo en inicializacion	<--

class Uart {
public:
	Uart();
	void UART0_pushTx(uint8_t dato);
	uint16_t UART0_popTx(void);
	void UART0_pushRx(uint8_t dato);
	int16_t UART0_popRx(void);
	void EnviarString (const char *str);
	int16_t Transmitir (const void * , uint8_t );
	void EnviarString_Entero (uint8_t ENTERO);
private:
	bool txStart=false;  //flag para activar/desactivar transmisión serie

	// Buffer de Transmision
	uint8_t bufferTx[TXBUFFER_SIZE];
	// Buffer de Recepcion
	uint8_t bufferRx[RXBUFFER_SIZE];

	// Indices de Recepcion
	uint8_t inx_rx_in = 0;
	uint8_t inx_rx_out = 0;
	// Indices de Transmision
	uint8_t inx_tx_in = 0;
	uint8_t inx_tx_out = 0;
};

#endif /* UART_H_ */
