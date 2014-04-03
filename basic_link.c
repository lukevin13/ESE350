#include "mbed.h"
#include <stdio.h>
#include <AnalogIn.h>

Serial pc(USBTX, USBRX);

AnalogIn ain(p19);
DigitalOut les(LED1);
DigitalOut aout(p18);

float i;

int main() {
    while(1) {
        i = ain.read();
        pc.printf("Force : %f \r\n", i);
        if (i > 0.5) {
            les = 1;
            aout = 1;
            pc.printf("Out : %f \r\n", aout.read());
        }
        else {
            les = 0;
            aout = 0;
        }
        wait(0.3);
    }
}
    