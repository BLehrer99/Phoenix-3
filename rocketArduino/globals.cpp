#include "globals.h"

//Adafruit_BNO055 bno = Adafruit_BNO055(55);
//
//Adafruit_BMP280 bme;

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
long countdownStart;

String input = "";

long tTime;

int burnHeight;

const int LegsLand[4] = {40, 10, 90, 65};
const int LegsStow[4] = {105, 65, 35, 115};
const int LegsAsc[4] = {95, 60, 45, 110};

Telemetry telemetry;
Servos servos;

File myFile;

Servo AFTS;
Servo LegFin0;
Servo LegFin1;
Servo LegFin2;
Servo LegFin3;
