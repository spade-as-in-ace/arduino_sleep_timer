
// Automatic Device Switch with Sleep Timer
// For: @Ade_Kolade
#include <Servo.h>

#define THRESHOLD_VALUE 200
#define SENSOR_PIN A0
#define OUTPUT_PIN 9

Servo servo;
bool toggle;

void setup() {
    servo.attatch(OUTPUT_PIN);
}

void loop() {
    while(analogRead(SENSOR_PIN) > THRESHOLD_VALUE){
        toggle = true;
    }
    if(toggle) {
        sweep();
        toggle = false;
    }
}

void sweep() {
    int pos = 0;
    while(pos++ < 90) {
        servo.write(pos);
        delay(15);
    }
    while(pos-- > 0) {
        servo.write(pos);
        delay(15);
    }
}
