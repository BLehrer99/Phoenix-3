#ifndef GLOBALS_H
#define GLOBALS_H

#include "Arduino.h"

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

extern Adafruit_BNO055 bno;

#include <Adafruit_BMP280.h>

#define BMP_SCK 13
#define BMP_MISO 12
#define BMP_MOSI 11
#define BMP_CS 10

extern Adafruit_BMP280 bme;

#include <SPI.h>

#include <SD.h>

#include <Servo.h>

#define MASS 1.0 //kg
#define FORCEBURN1 (2.0*11.17 + 2.0*4.74) //N
#define FORCEBURN2 (2.0*11.17) //N
#define GRAVITYFREE -8.5 //m/s2
#define GRAVITYBURN -9.0 //m/s2
#define TIMEBURN1 1.86 //s
#define TIMEBURN2 (2.44-TIMEBURN1) //s

#define DELTAT 0.1
#define COUNTLENGTH 3.0

#define BURNTIME 2.4

#define ABORTPIN 48
#define MAINIGNITIONPIN 50
#define LANDIGNITIONPIN 51

//skip 4, sd
#define FAIRINGPIN 5
#define ROLLCOMP0PIN 6
#define ROLLCOMP1PIN 7
#define ROLLCOMP2PIN 8
#define ROLLCOMP3PIN 9
#define AFTSPIN 10
#define LEGS0PIN 11
#define LEGS1PIN 12
#define LEGS2PIN 13
#define LEGS3PIN 14

#define ROLLCOMP0TRIM 0
#define ROLLCOMP1TRIM 0
#define ROLLCOMP2TRIM 0
#define ROLLCOMP3TRIM 0

#define AFTSON 100
#define AFTSOFF 30

#define ENGINEDELAY 6200 //ms

extern File myFile;

extern int phase; //phase of flight
extern String message; //important message to be written to sd card

extern int countdownStart; //records start time of countdown
extern long tTime;

extern String input;

extern int burnHeight;

class Telemetry {
  public:
    void aglRead();
    void ascentRateRead();
    void accelerationRead(float prevAscentRate);
    void ahrsRead();

    float mag;
    float agl;
    float prevAgl;
    float ascentRate;
    float pitch;
    float yaw;
    float roll;
    float pitchRate;
    float yawRate;
    float rollRate;
    float acceleration;

    double qfe;
    double temp;

  private:
    unsigned long prevAltMicros = 0;
    unsigned long prevGyroMicros = 0;
    int ascentSamplesPerSecond;
};

extern Telemetry telemetry;

class Servos {
  public:
    void setRollComp();
    void setLegFin();
    void lightMain();
    void lightLand();
    void fireAFTS();
    void lightFairing();

    bool mainLight = false;
    bool landLight = true;
    bool triggerAFTS = false;
    bool fairingLight = false;

    int rollComp;
    int launchPitch;
    int legs[4];
    int fins[4];

    long lightTime = 0;
};

extern Servos servos;

void readTelemetry();
void checkCase();
void updateControls();
void writeSD();
void startup();
void test();
void countdown();
void ignition();
void ascent();
void apogee();
void descent();
void landing();
void shutoff();
void resetServos();
void serialInput();
void checkAFTS();

extern const int LegsLand[4];
extern const int LegsStow[4];
extern const int LegsAsc[4];

extern Servo AFTS;
extern Servo RollComp0;
extern Servo RollComp1;
extern Servo RollComp2;
extern Servo RollComp3;
extern Servo LegFin0;
extern Servo LegFin1;
extern Servo LegFin2;
extern Servo LegFin3;

#endif
