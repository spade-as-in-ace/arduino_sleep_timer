// Automatic Trigger for Light Motion Sensor
// For: @Ade_Kolade

#define THRESHOLD_VALUE 200
#define SENSOR_PIN A0
#define OUTPUT_PIN 9

void setup() {
    pinMode(OUTPUT_PIN, OUTPUT);
}

void loop() {
    while(analogRead(SENSOR_PIN) < THRESHOLD_VALUE) {
        if(digitalRead(OUTPUT_PIN) == 0) {
          digitalWrite(OUTPUT_PIN, 1);
        }
    }
    if(digitalRead(OUTPUT_PIN) == 1) {
      digitalWrite(OUTPUT_PIN, 0);
    }
}
