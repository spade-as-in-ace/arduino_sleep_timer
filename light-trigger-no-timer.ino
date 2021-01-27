
// Automatic Device Switch, No Timer Needed
// For: @Ade_Kolade
#include <Servo.h>

#define THRESHOLD_VALUE 200
#define SENSOR_PIN A0
#define OUTPUT_PIN 9
#define POWER_PIN 8

Servo servo;
bool toggle;

void setup() {
    pinMode(POWER_PIN, OUTPUT);
    servo.attach(OUTPUT_PIN);
}

void loop() {
    while(analogRead(SENSOR_PIN) > THRESHOLD_VALUE){
        toggle = true;
    }
    if(toggle) {
        digitalWrite(POWER_PIN) = 1;
        sweep();
        digitalWrite(POWER_PIN) = 0;
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
