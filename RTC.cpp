#include"RTC.h"
/*
RTC::RTC(double Anio=2022,double Mes=1,double Dia=1,bool Formato=Format_PM,double Hora=12,double Min=0,double Seg=0){


};*/
RTC::RTC(uint8_t SLK,uint8_t IO,uint8_t CE){
this->SLK=SLK;
this->IO=IO;
this->CE=CE;

}
uint8_t RTC::getAnio(){return Anios;}
uint8_t RTC::getDia(){return DiaDeLaSemana;}
uint8_t RTC::getHora(){return Horas;}
uint8_t RTC::getMinutos(){return Minutos;}
uint8_t RTC::getSegundos(){return Segundos;}

void RTC::setAnio(uint16_t a){
    Anios=a;
}
void RTC::setMes(uint8_t m){
    Meses=m;
}
void RTC::setDia(uint8_t di){
    DiaDeLaSemana=di;
}
void RTC::setHora(uint8_t hr){
    Horas=hr;
}
void RTC::setMinutos(uint8_t m){
    Minutos=m;
}
void RTC::setSegundos(uint8_t s){
    Segundos=s;
}
void RTC::initRTC(){

  DS1302_write (DS1302_ENABLE, 0);
  DS1302_write (DS1302_TRICKLE, 0x00);
}
void RTC::DS1302_write(uint32_t address,uint8_t data){
    // bitClear( address, DS1302_READBIT);                                                                    //|    |

    //_DS1302_start();                                                                                       //|    |

  // don't release the I/O-line                                                                          //|    |
  //_DS1302_togglewrite( address, false);                                                                  //|    |
                                                                                                         //|    |
  // don't release the I/O-line                                                                          //|    |
  //_DS1302_togglewrite( data, false);                                                                     //|    |
  //_DS1302_stop();

}
void RTC::_DS1302_start(void){
  /*  
  digitalWrite(CE, LOW );                 // default, not enabled                            //|    |
  pinMode( CE, OUTPUT );                                                                      //|    |

  digitalWrite(SLK, LOW );               // default, clock low                              //|    |
  pinMode(SLK, OUTPUT );                                                                    //|    |

  pinMode( IO, OUTPUT );                                                                      //|    |

  digitalWrite(CE, HIGH );                // start the session                               //|    |
  delayMicroseconds( 4 );  */
}
void RTC::updateTime(void){
//DS1302_clock_burst_read( (uint8_t *) &rtc);               // Read all clock data at once (burst mode)


}
void RTC::DS1302_clock_burst_read( uint8_t *p){
int i;                                                                                                 //|    |
  _DS1302_start();                                                                                       //|    |
                                                                                                         //|    |
// Instead of the address, the CLOCK_BURST_READ command is issued the I/O-line is released for the data  //|    |
  /*_DS1302_togglewrite( DS1302_CLOCK_BURST_READ, true);                                                   //|    |
                                                                                                         //|    |
  for( i=0; i<8; i++)  {                                                                                 //|    |
    *p++ = _DS1302_toggleread();                                                                         //|    |
  }                                                                                                      //|    |
  _DS1302_stop();    
*/
}
void RTC::_DS1302_togglewrite( uint8_t data, uint8_t release)  {                              //|    |
/*
  int i;                                                                                                 //|    |
                                                                                                         //|    |
  for( i = 0; i <= 7; i++ )  {                                                                           //|    |
    // set a bit of the data on the I/O-line                                                             //|    |
    digitalWrite( DS1302_IO_PIN, bitRead(data, i) );                                                     //|    |
    delayMicroseconds( 1 );                                     // tDC = 200ns                           //|    |
                                                                                                         //|    |
    // clock up, data is read by DS1302                                                                  //|    |
    digitalWrite( DS1302_SCLK_PIN, HIGH );                                                               //|    |
    delayMicroseconds( 1 );                                     // tCH = 1000ns, tCDH = 800ns            //|    |
                                                                                                         //|    |
//  If this write is followed by a read, the I/O-line should be released after the last bit, before the  //|    |
//  clock line is made low.  This is according the datasheet.  I have seen other programs that don't     //|    |
//  release the I/O-line at this moment, and that could cause a shortcut spike on the I/O-line.          //|    |
    if( release && i == 7 )  {                                                                           //|    |
      pinMode( DS1302_IO_PIN, INPUT );                                                                   //|    |
    }  else  {                                                                                           //|    |
      digitalWrite( DS1302_SCLK_PIN, LOW );                                                              //|    |
      delayMicroseconds( 1 );                                   // tCL=1000ns, tCDD=800ns                //|    |
    }                                                                                                    //|    |
  }   */                                                                                                   //|    |
}     