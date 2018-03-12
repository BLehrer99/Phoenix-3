#include "globals.h"

void readTelemetry() {
  telemetry.magRead();
  telemetry.aglRead();
  float prevAccentRate = telemetry.accentRate;
  telemetry.accentRateRead();
  telemetry.accelerationRead(prevAccentRate);
  telemetry.gyroRead();
}

void Telemetry::magRead() {
  compass.read();
  mag = compass.heading();
}

void Telemetry::aglRead() {
  double P = getPressure();
  if (P == -9999)
    P = 0;
  agl = pressure.altitude(P, qfe);
}

void Telemetry::accentRateRead() {
  accentSamplesPerSecond = 1000000.0 / float(micros() - prevAltMicros);
  prevAltMicros = micros();
  accentRate = (agl - prevAgl) * accentSamplesPerSecond;
}

void Telemetry::accelerationRead(float prevAccentRate) {
  acceleration = (accentRate - prevAccentRate) / accentSamplesPerSecond;
}

void Telemetry::gyroRead() {
  gyro.read();
  float samplesPerSecond = 1000000.0 / float(micros() - prevGyroMicros);
  prevGyroMicros = micros();

  pitchRate = float(gyro.g.x);
  yawRate = float(gyro.g.y);
  rollRate = float(gyro.g.z);

  float deltaPitch = pitchRate * samplesPerSecond;
  float deltaYaw = yawRate * samplesPerSecond;
  float deltaRoll = rollRate * samplesPerSecond;

  pitch = int(pitch + deltaPitch) % 360;
  yaw = int(yaw + deltaYaw) % 360;
  roll = int(roll + deltaRoll) % 360;
}

double Telemetry::getPressure() {
  char status;
  double P;
  status = pressure.getPressure(P, temp);
  if (status != 0) {
    return (P);
  } else {
    message += "error: retrieving pressure measurement, ";
    return -9999;
  }
}
