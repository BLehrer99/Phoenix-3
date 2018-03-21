#include "globals.h"

Adafruit_BNO055 bno = Adafruit_BNO055(55);

Adafruit_BMP280 bme;

int phase = 0;
/*
   phases
   0: startup, calibration
   1: control surface test
   2: countdown
   3: ignition
   4: ascent
   5: apogee
   6: descent
   7: landing
   8: shutoff
   9: powered off
*/


String message; //stores important info to write to sd card
int countdownStart;

String input = "";

int tTime;

int burnHeight;

const int LegsLand[4] = {0, 0, 0, 0};
const int LegsStow[4] = {0, 0, 0, 0};
const int LegsAsc[4] = {0, 0, 0, 0};

Telemetry telemetry;
Servos servos;

File myFile;

Servo RollComp0;
Servo RollComp1;
Servo RollComp2;
Servo RollComp3;
Servo LegFin0;
Servo LegFin1;
Servo LegFin2;
Servo LegFin3;
