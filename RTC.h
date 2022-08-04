/*
 * RTC.h
 *
 *  Created on: 9 jul. 2022
 *      Author: nahuu
 */

#ifndef RTC_H_
#define RTC_H_
#include "LPC845.h"

#define RTC_Segundos_L      	 0x81h   //-->   Direcion de Lectura de Segundos     <--
#define RTC_Segundos_E      	 0x80h   //-->   Direcion de Escritura de Segundos   <--
#define RTC_Minutos_L       	 0x83h   //-->   Direcion de Lectura de Minutos      <--
#define RTC_Minutos_E       	 0x82h   //-->   Direcion de Escritura de Minutos    <--
#define RTC_Hora_L          	 0x85h   //-->   Direcion de Lectura Hora            <--
#define RTC_Hora_E          	 0x84h   //-->   Direcion de Escritura de hora       <--
#define RTC_Mes_L           	 0x89h   //-->   Direcion de Lectura de mes          <--
#define RTC_Mes_E           	 0x88h   //-->   Direcion de Escritura de mes        <--
#define RTC_Anio_L          	 0x8Dh   //-->   Direcion de Lectura de anio         <--
#define RTC_Anio_E          	 0x8Ch   //-->   Direcion de Escritura de anio       <--
#define RTC_Dia_L       	     0x8Bh   //-->   Direcion de Lectura del dia del sem <--
#define RTC_Dia_E  		         0x8Ah   //-->   Direcion de Escitura del dia de sem <--
#define DS1302_ENABLE            0x8E                                                                    //|
#define DS1302_TRICKLE           0x90

#define DS1302_D0 0                                                                                      //|
#define DS1302_D1 1                                                                                      //|
#define DS1302_D2 2                                                                                      //|
#define DS1302_D3 3                                                                                      //|
#define DS1302_D4 4                                                                                      //|
#define DS1302_D5 5                                                                                      //|
#define DS1302_D6 6                                                                                      //|
#define DS1302_D7 7

#define DS1302_READBIT DS1302_D0
//  Bit for clock (0) or ram (1) area, called R/C-bit (bit in address)                                   //|
#define DS1302_RC DS1302_D6
//  Seconds Register                                                                                     //|
#define DS1302_CH DS1302_D7                              // 1 = Clock Halt, 0 = start                    //|
//  Hour Register                                                                                        //|
#define DS1302_AM_PM DS1302_D5                           // 0 = AM, 1 = PM                               //|
#define DS1302_12_24 DS1302 D7                           // 0 = 24 hour, 1 = 12 hour                     //|
//  Enable Register                                                                                      //|
#define DS1302_WP DS1302_D7                              // 1 = Write Protect, 0 = enabled               //|
//  Trickle Register                                                                                     //|
#define DS1302_ROUT0 DS1302_D0                                                                           //|
#define DS1302_ROUT1 DS1302_D1                                                                           //|
#define DS1302_DS0   DS1302_D2                                                                           //|
#define DS1302_DS1   DS1302_D2                                                                           //|
#define DS1302_TCS0  DS1302_D4                                                                           //|
#define DS1302_TCS1  DS1302_D5                                                                           //|
#define DS1302_TCS2  DS1302_D6                                                                           //|
#define DS1302_TCS3  DS1302_D7                                                                           //|


#define Format_PM true
#define Fromat_AM false



class RTC {
	//-->	Manejador de RTC	<--
public:
	RTC(uint8_t UART_CONNECT=0);	//-->	Deberia hacer la conexion
	static uint8_t Hora;
	static uint8_t Minutos;
	void setSegundos(uint8_t);
	void setMinutos(uint8_t);
	void setHora(uint8_t);
	void setDia(uint8_t);
	void setMes(uint8_t);
	void setAnio(uint16_t);

	uint8_t getSegundos();
	uint8_t getMinutos();
	uint8_t getHora();
	uint8_t getDia();
	uint8_t getMes();
	uint16_t getAnio();
	bool Format();  //-->   Te dice que formato tiene si AM-PM      <--

};

#endif /* RTC_H_ */
