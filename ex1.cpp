#include "mbed.h"

AnalogIn Ain(D7);
PwmOut PWM1(D6);
Serial pc( USBTX, USBRX );
AnalogOut Aout(DAC0_OUT);
int sample = 128;
int i;

float ADCdata[128];
int main(){
    PWM1.period(1/1000);
    for( i=0; i<1; i+=0.1 ){
        PWM1 = i;
        wait(0.01);
    }
    for(i=1; i>0; i-=0.1){
        PWM1 = i;
        wait(0.1);
    }
  for (i = 0; i < sample; i++){
    Aout = Ain;
    ADCdata[i] = Ain;
    wait(1./sample);
    
  }
  for (i = 0; i < sample; i++){
    pc.printf("%1.3f\r\n", ADCdata[i]);
    wait(0.1);
  }
}