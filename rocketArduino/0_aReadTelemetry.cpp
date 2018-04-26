#include "globals.h"


float streamInputs[5];
long micro;

void readTelemetry() {
  while (!Serial1.available());
  if(Serial1.readBytes((byte*)streamInputs, 5 * sizeof(streamInputs[0])) != 5){
    message += "failed to read stream, ";
  }

  micro = streamInputs[4];
  
  telemetry.aglRead();
  float prevAscentRate = telemetry.ascentRate;
  telemetry.ascentRateRead();
  telemetry.accelerationRead(prevAscentRate);
  telemetry.ahrsRead();
}

void Telemetry::aglRead() {
  //agl = bme.readAltitude(qfe);
  agl = streamInputs[3];
}

void Telemetry::ascentRateRead() {
  ascentSamplesPerSecond = 1000000.0 / float(micro - prevAltMicros);
  prevAltMicros = micro;
  ascentRate = (agl - float(prevAgl)) * float(ascentSamplesPerSecond);
  prevAgl = agl;
}

void Telemetry::accelerationRead(float prevAscentRate) {
  acceleration = (ascentRate - prevAscentRate) / ascentSamplesPerSecond;
}

void Telemetry::ahrsRead() {
//  /* Get a new sensor event */
//  sensors_event_t event;
//  bno.getEvent(&event);

  /* save the floating point data */
  prevPitch = pitch;
  prevYaw = yaw;
  prevRoll = roll;

//  pitch = event.orientation.y;
//  yaw = event.orientation.z;
//  roll = event.orientation.x;

  pitch = streamInputs[0];
  yaw = streamInputs[1];
  roll = streamInputs[0];

  int rate = (int(pitch) - int(prevPitch)) % 360;
  if (rate >= 180 || rate <= -180) {
    pitchRate = rate * ascentSamplesPerSecond;
  } else {
    pitchRate = (int(pitch) - int(prevPitch)) * ascentSamplesPerSecond;
  }

  rate = (int(yaw) - int(prevYaw)) % 360;
  if (rate >= 180 || rate <= -180) {
    yawRate = rate * ascentSamplesPerSecond;
  } else {
    yawRate = (int(yaw) - int(prevYaw)) * ascentSamplesPerSecond;
  }

  rate = (int(roll) - int(prevRoll)) % 360;
  if (rate >= 180 || rate <= -180) {
    rollRate = rate * ascentSamplesPerSecond;
  } else {
    rollRate = (int(roll) - int(prevRoll)) * ascentSamplesPerSecond;
  }
}
