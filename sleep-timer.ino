// Automatic Device Switch with Sleep Timer
// For: @Ade_Kolade
#include <Chrono.h>

#define THRESHOLD_VALUE 200
#define SLEEP_TIME 5000
#define SENSOR_PIN A0
#define OUTPUT_PIN 9

Chrono uptime;
bool toggle;

void setup() {
    pinMode(OUTPUT_PIN, OUTPUT);
}

void loop() {
    while(analogRead(SENSOR_PIN) > THRESHOLD_VALUE){
        toggle = true;
    }
    if(toggle) {
        digitalWrite(OUTPUT_PIN, HIGH);
        uptime.restart();
        while(!uptime.hasPassed(SLEEP_TIME));
        uptime.stop();
        digitalWrite(OUTPUT_PIN, LOW);
        toggle = false;
    }
}
