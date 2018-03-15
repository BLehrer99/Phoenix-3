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

#define DELTAT 0.1
#define COUNTLENGTH 3

#define BURNTIME 2.4

#define ABORTPIN 48
#define FAIRINGPIN 49
#define IGNITIONPIN0 50
#define IGNITIONPIN1 51

#define THRUSTPIN 2
#define RYAWPIN 3
#define RPITCHPIN 5
//skip 4, sd
#define ROLLCOMP0PIN 6
#define ROLLCOMP1PIN 7
#define ROLLCOMP2PIN 8
#define ROLLCOMP3PIN 9
#define LEGS0PIN 10
#define LEGS1PIN 11
#define LEGS2PIN 12
#define LEGS3PIN 13

#define RYAWTRIM 0
#define RPITCHTRIM 0
#define THRUSTTRIM 0
#define ROLLCOMP0TRIM 0
#define ROLLCOMP1TRIM 0
#define ROLLCOMP2TRIM 0
#define ROLLCOMP3TRIM 0
#define LEGS0TRIM 0
#define LEGS1TRIM 0
#define LEGS2TRIM 0
#define LEGS3TRIM 0

#define SERVORANGE 180
#define MOTORMAX 170
#define MOTORMIN 65
#define MOTORRESET 50

#define ENGINEDELAY 8600 //ms

extern File myFile;

extern int phase; //phase of flight
extern String message; //important message to be written to sd card

extern int countdownStart; //records start time of countdown
extern int tTime;

extern String input;

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
    void setThrust(int);
    void setRYaw(int);
    void setRPitch(int);
    void setRollComp(int);
    void setLegFin(int, int);

    int thrust;
    int rYaw;
    int rPitch;
    int rollComp;
    int launchPitch;
    int legs[4];
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
void decent();
void landing();
void shutoff();
void resetServos();
void serialInput();

extern Servo Thrust;
extern Servo RYaw;
extern Servo RPitch;
extern Servo RollComp0;
extern Servo RollComp1;
extern Servo RollComp2;
extern Servo RollComp3;
extern Servo LegFin0;
extern Servo LegFin1;
extern Servo LegFin2;
extern Servo LegFin3;

#endif
