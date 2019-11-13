#include "mbed.h"
#include "pwm_tone.h"

DigitalIn mybutton(USER_BUTTON);
DigitalOut myled(D2);
PwmOut Buzzer(D5);

float C_4 = 1000000/Do4;

int main() {

      myled = 1;
      wait(0.2); // 200 ms
      Tune(Buzzer, C_4, 4);
      wait(0.2); // 200 ms
}
