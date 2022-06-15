#include"Leds.h"
Leds::Leds(){
//-->   Constructor por defecto <--

//color[]={Color_R,Color_R,Color_R,Color_R,Color_R,Color_R};
for(int i=0;i<LedsCant;i++){
color[i]=Color_R;
buff[i]=false;
}
led=0;

}
bool Leds::GetStatus(uint8_t led){
    if(led<LedsCant){
        return buff[led];
    }
return false;

}
void Leds::SetColor(uint8_t Led,uint8_t Color){
    if(Led<LedsCant){
        color[Led]=Color;
        }
    //(Led<LedsCant)?color[Led]=Color:return;
}
void Leds::SetStatus(uint8_t Led,bool estado){
if(Led<LedsCant){
buff[Led]=estado;
}
    
}