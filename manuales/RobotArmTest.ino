#include <Servo.h>

Servo servo1, servo2, servo3, servo4;

int potPins[4] = {A0, A1, A2, A3};   // entradas de potenciómetros
int servoPins[4] = {2, 3, 4, 5};   // salidas para servos
Servo servos[4];

void setup() {
  for (int i = 0; i < 4; i++) {
    servos[i].attach(servoPins[i]);
  }
}

void loop() {
  for (int i = 0; i < 4; i++) {
    int val = analogRead(potPins[i]);              // lee potenciómetro (0-1023)
    int angle = map(val, 0, 1023, 0, 180);         // convierte a ángulo (0-180°)
    servos[i].write(angle);                        // mueve servo
  }
}

