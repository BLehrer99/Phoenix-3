#include "globals.h"

void setup() {
  Wire.begin();

  Serial.begin(9600);
  Serial1.begin(9600);

  pinMode(ABORTPIN, INPUT);
  pinMode(FAIRINGPIN, INPUT);
  pinMode(MAINIGNITIONPIN, OUTPUT);
  pinMode(LANDIGNITIONPIN, OUTPUT);

  RollComp0.attach(ROLLCOMP0PIN);
  RollComp1.attach(ROLLCOMP1PIN);
  RollComp2.attach(ROLLCOMP2PIN);
  RollComp3.attach(ROLLCOMP3PIN);
  LegFin0.attach(LEGS0PIN);
  LegFin1.attach(LEGS1PIN);
  LegFin2.attach(LEGS2PIN);
  LegFin3.attach(LEGS3PIN);
  AFTS.attach(AFTSPIN);
  Fairing.attach(FAIRINGPIN);
  delay(2000);
  startup();
}

long prevMillis;
void loop() {
  if (millis() - prevMillis >= 1000.0 * DELTAT) {
    prevMillis = millis();
    message = "";
    tTime = phase >= 2 ? (millis() - countdownStart) - (1000.0 * COUNTLENGTH * 60.0) : -100000.0;
    readTelemetry();
    if (phase >= 4 && phase <= 6) {
      checkAFTS();
    }
    checkCase();
    updateControls();
    writeSD();
  }
}

