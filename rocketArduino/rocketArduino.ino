#include "globals.h"

void setup() {
  Wire.begin();

  Serial.begin(9600);

  pinMode(ABORTPIN, INPUT);
  pinMode(FAIRINGPIN, INPUT);
  pinMode(IGNITIONPIN0, OUTPUT);
  pinMode(IGNITIONPIN1, OUTPUT);

  Thrust.attach(THRUSTPIN);
  RYaw.attach(RYAWPIN);
  RPitch.attach(RPITCHPIN);
  RollComp0.attach(ROLLCOMP0PIN);
  RollComp1.attach(ROLLCOMP1PIN);
  RollComp2.attach(ROLLCOMP2PIN);
  RollComp3.attach(ROLLCOMP3PIN);
  LegFin0.attach(LEGS0PIN);
  LegFin1.attach(LEGS1PIN);
  LegFin2.attach(LEGS2PIN);
  LegFin3.attach(LEGS3PIN);
  delay(2000);
  startup();
}

long prevMillis;
void loop() {
  if (millis() - prevMillis >= 1000 * DELTAT) {
    prevMillis = millis();
    message = "";
    tTime = phase >= 2 ? (millis() - countdownStart) - (1000 * COUNTLENGTH * 60) : -100000;
    readTelemetry();
    checkCase();
    writeSD();
  }
}

