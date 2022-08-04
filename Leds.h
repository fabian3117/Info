/*
 * Leds.h
 *
 *  Created on: 16 jun. 2022
 *      Author: nahuu
 */

#ifndef LEDS_H_
#define LEDS_H_
//-->	Pines asociados con los leds	<--

#define Pin_R 1,0
#define Pin_G 1,2
#define Pin_B 1,1
#define Color_R 0
#define Color_G 1
#define Color_B 2
#define Color_Null 3
#define LedsCant 7
#define LedsColumnas 5
#include "LPC845.h"
#include "Gpio.h"
#define Led_Prende false
#define Led_Apaga 	true
class Leds :public Gpio{
public:
	//-->	Para activar el Led tengo que Ponerlo modo salida	<--
		Leds(uint8_t Pin,uint8_t Port):Gpio(Pin,Port,SALIDA,true){

			Activa();	//-->	Aca se activa de una ya el led	<--
		};	//-->	Esto se encarga de manejar la led	<--

		//-->	Para olvidar ese tema de prende por activo bajo y todo eso hago esto - Total sobra memoria	<--

		void Apagar();
		void Prender();
	    bool GetStatus(uint8_t);
	    uint8_t GetColor(uint8_t led);
	    void SetStatus(uint8_t ,bool );
	    void SetStatus(bool );
	    void SetColor(uint8_t led,uint8_t color);
	    uint8_t Linea;
	    void MostrarEror(); //-->   A futuro podria llenar un bufer que sea codigo de error <--
private:

	    bool _[LedsColumnas][LedsCant] = {{0,0,0,0,0,0,0},{ 0,0,0,0,0,0,0},{ 0,0,0,0,0,0,0}, {0,0,0,0,0,0,0}, {0,0,0,0,0,0,0}};
	    bool A[LedsColumnas][LedsCant] = {{0,1,1,1,1,1,1}, {1,0,0,1,0,0,0}, {1,0,0,1,0,0,0}, {1,0,0,1,0,0,0}, {0,1,1,1,1,1,1}};
	    bool B[LedsColumnas][LedsCant] = {{1,1,1,1,1,1,1}, {1,0,0,1,0,0,1}, {1,0,0,1,0,0,1}, {1,0,0,1,0,0,1}, {0,1,1,0,1,1,0}};
	    bool C[LedsColumnas][LedsCant] = {{0,1,1,1,1,1,0}, {1,0,0,0,0,0,1}, {1,0,0,0,0,0,1}, {1,0,0,0,0,0,1}, {1,0,0,0,0,0,1}};
	    bool D[LedsColumnas][LedsCant] = {{1,1,1,1,1,1,1}, {1,0,0,0,0,0,1}, {1,0,0,0,0,0,1}, {1,0,0,0,0,0,1}, {0,1,1,1,1,1,0}};
	    bool E[LedsColumnas][LedsCant] = {{1,1,1,1,1,1,1}, {1,0,0,1,0,0,1}, {1,0,0,1,0,0,1}, {1,0,0,1,0,0,1}, {1,0,0,1,0,0,1}};
	    bool F[LedsColumnas][LedsCant] = {{1,1,1,1,1,1,1}, {1,0,0,1,0,0,0}, {1,0,0,1,0,0,0}, {1,0,0,1,0,0,0}, {1,0,0,1,0,0,0}};
	    bool G[LedsColumnas][LedsCant] = {{1,1,1,1,1,1,1}, {1,0,0,0,0,0,1}, {1,0,0,1,0,0,1}, {1,0,0,1,0,0,1}, {1,0,0,1,1,1,1}};
	    bool H[LedsColumnas][LedsCant] = {{1,1,1,1,1,1,1}, {0,0,0,1,0,0,0}, {0,0,0,1,0,0,1}, {0,0,0,1,0,0,0}, {1,1,1,1,1,1,1}};
	    bool I[LedsColumnas][LedsCant] = {{1,0,0,0,0,0,1}, {1,0,0,0,0,0,1}, {1,1,1,1,1,1,1}, {1,0,0,0,0,0,1}, {1,0,0,0,0,0,1}};
	    bool J[LedsColumnas][LedsCant] = {{0,0,0,0,1,1,0}, {0,0,0,0,0,0,1}, {0,0,0,0,0,0,1}, {0,0,0,0,0,0,1}, {1,1,1,1,1,1,0}};
	    bool K[LedsColumnas][LedsCant] = {{1,1,1,1,1,1,1}, {0,0,0,1,0,0,0}, {0,0,1,0,1,0,0}, {0,1,0,0,0,1,0}, {1,0,0,0,0,0,1}};
	    bool L[LedsColumnas][LedsCant] = {{1,1,1,1,1,1,1}, {0,0,0,0,0,0,1}, {0,0,0,0,0,0,1}, {0,0,0,0,0,0,1}, {0,0,0,0,0,0,1}};
	    bool M[LedsColumnas][LedsCant] = {{1,1,1,1,1,1,1}, {0,1,0,0,0,0,0}, {0,0,1,1,0,0,0}, {0,1,0,0,0,0,0}, {1,1,1,1,1,1,1}};
	    bool N[LedsColumnas][LedsCant] = {{1,1,1,1,1,1,1}, {0,1,0,0,0,0,0}, {0,0,1,0,0,0,0}, {0,0,0,1,0,0,0}, {1,1,1,1,1,1,1}};
	    bool O[LedsColumnas][LedsCant] = {{0,1,1,1,1,1,0}, {1,0,0,0,0,0,1}, {1,0,0,0,0,0,1}, {1,0,0,0,0,0,1}, {0,1,1,1,1,1,0}};
	    bool P[LedsColumnas][LedsCant] = {{1,1,1,1,1,1,1}, {1,0,0,1,0,0,0}, {1,0,0,1,0,0,0}, {1,0,0,1,0,0,0}, {0,1,1,0,0,0,0}};
	    bool Q[LedsColumnas][LedsCant] = {{0,1,1,1,1,0,0}, {1,0,0,0,0,1,0}, {1,0,0,0,0,1,0}, {1,0,0,0,0,1,0}, {0,1,1,1,1,0,1}};
	    bool R[LedsColumnas][LedsCant] = {{1,1,1,1,1,1,1}, {1,0,0,1,0,0,0}, {1,0,0,1,0,0,0}, {1,0,0,1,0,0,0}, {0,1,1,0,1,1,1}};
	    bool S[LedsColumnas][LedsCant] = {{0,1,1,0,0,0,0}, {1,0,0,1,0,0,1}, {1,0,0,1,0,0,1}, {1,0,0,1,0,0,1}, {0,0,0,0,1,1,0}};
	    bool T[LedsColumnas][LedsCant] = {{1,0,0,0,0,0,0}, {1,0,0,0,0,0,0}, {1,1,1,1,1,1,1}, {1,0,0,0,0,0,0}, {1,0,0,0,0,0,0}};
	    bool U[LedsColumnas][LedsCant] = {{1,1,1,1,1,1,0}, {0,0,0,0,0,0,1}, {0,0,0,0,0,0,1}, {0,0,0,0,0,0,1}, {1,1,1,1,1,1,0}};
	    bool V[LedsColumnas][LedsCant] = {{1,1,1,1,1,0,0}, {0,0,0,0,0,1,0}, {0,0,0,0,0,0,1}, {0,0,0,0,0,1,0}, {1,1,1,1,1,0,0}};
	    bool W[LedsColumnas][LedsCant] = {{1,1,1,1,1,1,1}, {0,0,0,0,0,1,0}, {0,0,0,0,1,0,0}, {0,0,0,0,0,1,0}, {1,1,1,1,1,1,1}};
	    bool X[LedsColumnas][LedsCant] = {{1,0,0,0,0,0,1}, {0,1,0,0,0,1,0}, {0,0,1,1,1,0,0}, {0,1,0,0,0,1,0}, {1,0,0,0,0,0,1}};
	    bool Y[LedsColumnas][LedsCant] = {{1,1,1,0,0,0,0}, {0,0,0,1,0,0,0}, {0,0,0,0,1,1,1}, {0,0,0,1,0,0,0}, {1,1,1,0,0,0,0}};
	    bool Z[LedsColumnas][LedsCant] = {{1,0,0,0,0,1,1}, {1,0,0,0,1,0,1}, {1,0,0,1,0,0,1}, {1,0,1,0,0,0,1}, {1,1,0,0,0,0,1}};

};

#endif /* LEDS_H_ */
