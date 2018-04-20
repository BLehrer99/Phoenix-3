#include "globals.h"

void readTelemetry() {
  telemetry.aglRead();
  float prevAscentRate = telemetry.ascentRate;
  telemetry.ascentRateRead();
  telemetry.accelerationRead(prevAscentRate);
  telemetry.ahrsRead();
}

void Telemetry::aglRead() {
  agl = bme.readAltitude(qfe);
}

void Telemetry::ascentRateRead() {
  ascentSamplesPerSecond = 1000000.0 / float(micros() - prevAltMicros);
  prevAltMicros = micros();
  ascentRate = (agl - float(prevAgl)) * float(ascentSamplesPerSecond);
  prevAgl = agl;
}

void Telemetry::accelerationRead(float prevAscentRate) {
  acceleration = (ascentRate - prevAscentRate) / ascentSamplesPerSecond;
}

void Telemetry::ahrsRead() {
  /* Get a new sensor event */
  sensors_event_t event;
  bno.getEvent(&event);

  /* save the floating point data */
  prevPitch = pitch;
  prevYaw = yaw;
  prevRoll = roll;

  pitch = event.orientation.x;
  yaw = event.orientation.x;
  roll = event.orientation.x;

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
