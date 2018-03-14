#include "globals.h"

void readTelemetry() {
  telemetry.aglRead();
  float prevAscentRate = telemetry.ascentRate;
  telemetry.ahrsRead();
}

void Telemetry::aglRead() {

}

void Telemetry::ascentRateRead() {
  ascentSamplesPerSecond = 1000000.0 / float(micros() - prevAltMicros);
  prevAltMicros = micros();
  ascentRate = (agl - prevAgl) * ascentSamplesPerSecond;
}

void Telemetry::accelerationRead(float prevAscentRate) {
  acceleration = (ascentRate - prevAscentRate) / ascentSamplesPerSecond;
}

void Telemetry::ahrsRead() {
  /* Get a new sensor event */
  sensors_event_t event;
  bno.getEvent(&event);

  /* save the floating point data */
  telemetry.pitch = event.orientation.x;
  telemetry.yaw = event.orientation.x;
  telemetry.roll = event.orientation.x;
}
