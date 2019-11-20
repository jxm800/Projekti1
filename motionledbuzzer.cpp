#include "mbed.h"
#include "pitches.h"

Serial pc(USBTX,USBRX);

DigitalIn mybutton(USER_BUTTON);
DigitalOut myled(D2);
PwmOut buzzer(D5);
InterruptIn PIR(D7);                    //motion detector, connections: -> GND, OUTPUT, VNC
int PIR_Detected = 0;

void Buzzer_On()
{
    buzzer.period(1.0 / (NOTE_AS4));
    buzzer.write(0.10f);                //Buzzer volume % of duty cycle
}

void Buzzer_Silence()
{
    buzzer.write(0);
}

void irq_handler(void)
{
    PIR_Detected = 1;
}

int main()
{

    PIR.rise(&irq_handler);

    while(1) {
        if (PIR_Detected) {
            myled = 1;
            Buzzer_On();
            pc.printf("1");     //Raspberry activates the camera after reading this
            pc.printf("\r\n");
            PIR_Detected = 0;
            wait(0.5);
        }

        else {
            myled = 0;
            Buzzer_Silence();
            wait(0.5);		//for warming up time
        }
    }
}
