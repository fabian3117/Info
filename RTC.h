#define uint32_t int
#define uint8_t char
#define uint16_t char


#define RTC_Segundos_L      0x81h   //-->   Direcion de Lectura de Segundos     <--
#define RTC_Segundos_E      0x80h   //-->   Direcion de Escritura de Segundos   <--
#define RTC_Minutos_L       0x83h   //-->   Direcion de Lectura de Minutos      <--
#define RTC_Minutos_E       0x82h   //-->   Direcion de Escritura de Minutos    <--
#define RTC_Hora_L          0x85h   //-->   Direcion de Lectura Hora            <--
#define RTC_Hora_E          0x84h   //-->   Direcion de Escritura de hora       <--
#define RTC_Mes_L           0x89h   //-->   Direcion de Lectura de mes          <--
#define RTC_Mes_E           0x88h   //-->   Direcion de Escritura de mes        <--
#define RTC_Anio_L          0x8Dh   //-->   Direcion de Lectura de anio         <--
#define RTC_Anio_E          0x8Ch   //-->   Direcion de Escritura de anio       <--
#define RTC_Dia_L           0x8Bh   //-->   Direcion de Lectura del dia del sem <--
#define RTC_Dia_E           0x8Ah   //-->   Direcion de Escitura del dia de sem <--
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



#define Write(x) (x<<1)|(0x1<<7)          //-->   Deja listo para enviar como escritura       - 1-0-A4-A3-A2-A1-A0-0    <--
#define Read(x) (x<<1)|(0x1<<7)|(0x1)    //-->    Deja listo para enviar como Lectura         - 1-0-A4-A3-A2-A1-A0-1    <--

class RTC{

        public: 
RTC();
RTC(uint8_t SLK,uint8_t IO,uint8_t CE);
void setSegundos(uint8_t);
void setMinutos(uint8_t);
void setHora(uint8_t);
void setDia(uint8_t);
void setMes(uint8_t);
void setAnio(uint16_t);

void DS1302_write(uint32_t,uint8_t);
void bitClear(uint32_t,uint8_t);
uint8_t getSegundos();
uint8_t getMinutos();
uint8_t getHora();
uint8_t getDia();
uint8_t getMes();
uint16_t getAnio();

void initRTC();

        private:
uint8_t SLK,IO,CE;

uint8_t Segundos;                                                                                     //|
uint8_t Minutos;                                                                                     //|
uint8_t Horas;                                                                                       //|
uint8_t DiaDeLaSemana;                                                                                   //|
uint8_t DiaDelMes;                                                                                  //|
uint8_t Meses;                                                                                       //|
int Anios;

  void _DS1302_start();                                                                                       
 // void _DS1302_togglewrite( uint32_t, bool);
 // void _DS1302_togglewrite(uint8_t, bool);
  void _DS1302_stop();
  void updateTime();
  void DS1302_clock_burst_read( uint8_t *p);
};