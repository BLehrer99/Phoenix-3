#include "globals.h"

void setup() {
  //Wire.begin();

  Serial.begin(9600);
  Serial1.begin(38400);

  //this is a comet

  pinMode(ABORTPIN, INPUT);
  pinMode(FAIRINGPIN, OUTPUT);
  pinMode(MAINIGNITIONPIN, OUTPUT);
  pinMode(LANDIGNITIONPIN, OUTPUT);

//  RollComp0.attach(ROLLCOMP0PIN);
//  RollComp1.attach(ROLLCOMP1PIN);
  LegFin0.attach(LEGS0PIN);
  LegFin1.attach(LEGS1PIN);
  LegFin2.attach(LEGS2PIN);
  LegFin3.attach(LEGS3PIN);
  AFTS.attach(AFTSPIN);

  while(!Serial1);
  
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

