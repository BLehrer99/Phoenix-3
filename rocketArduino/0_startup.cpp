#include "globals.h"

void displaySensorDetails(void)
{
  sensor_t sensor;
  bno.getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
  Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println(" xxx");
  Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println(" xxx");
  Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" xxx");
  Serial.println("------------------------------------");
  Serial.println("");
  delay(500);
}

/**************************************************************************/
/*
    Display some basic info about the sensor status
*/
/**************************************************************************/
void displaySensorStatus(void)
{
  /* Get the system status values (mostly for debugging purposes) */
  uint8_t system_status, self_test_results, system_error;
  system_status = self_test_results = system_error = 0;
  bno.getSystemStatus(&system_status, &self_test_results, &system_error);

  /* Display the results in the Serial Monitor */
  Serial.println("");
  Serial.print("System Status: 0x");
  Serial.println(system_status, HEX);
  Serial.print("Self Test:     0x");
  Serial.println(self_test_results, HEX);
  Serial.print("System Error:  0x");
  Serial.println(system_error, HEX);
  Serial.println("");
  delay(500);
}

/**************************************************************************/
/*
    Display sensor calibration status
*/
/**************************************************************************/
void displayCalStatus(void)
{
  /* Get the four calibration values (0..3) */
  /* Any sensor data reporting 0 should be ignored, */
  /* 3 means 'fully calibrated" */
  uint8_t system, gyro, accel, mag;
  system = gyro = accel = mag = 0;
  bno.getCalibration(&system, &gyro, &accel, &mag);

  /* The data should be ignored until the system calibration is > 0 */
  Serial.print("\t");
  if (!system)
  {
    Serial.print("! ");
  }

  /* Display the individual values */
  Serial.print("Sys:");
  Serial.print(system, DEC);
  Serial.print(" G:");
  Serial.print(gyro, DEC);
  Serial.print(" A:");
  Serial.print(accel, DEC);
  Serial.print(" M:");
  Serial.print(mag, DEC);
}

int setupAHRS() {
  Serial.println("Orientation Sensor Test");
  message += "Orientation Sensor Test, ";
  /* Initialise the sensor */
  if (!bno.begin()) {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.println("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    message += "Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!, ";
    phase = 9;
    return 0;
  }
  delay(1000);
  /* Display some basic information on this sensor */
  displaySensorDetails();
  /* Optional: Display current status */
  displaySensorStatus();
  bno.setExtCrystalUse(true);
  return 1;
}












int setupPressure() {
  if (!bme.begin()) {
    message += "Could not find a valid BMP280 sensor, check wiring!, ";
    Serial.println("Could not find a valid BMP280 sensor, check wiring!");
    phase = 9;
    return 0;
  }
  telemetry.qfe = bme.readPressure();
  return 1;
}

void startup() {
  if (!SD.begin(4)) {
    Serial.println("aborted: start sd");
    message += "aborted: start sd, ";
    phase = 9;
    return;
  }
  myFile = SD.open("log.txt", FILE_WRITE);
  if (!myFile) {
    Serial.println("aborted: could not open file");
    message += "aborted: could not open file, ";
    phase = 9;
    return;
  }
  resetServos();

  if (digitalRead(ABORTPIN) == HIGH) {
    Serial.println("aborted: abort switch");
    message += "aborted: abort switch, ";
    phase = 9;
    return;
  }

  if (!setupAHRS())
    return;

  if (!setupPressure())
    return;

  message += "startup initiated: calibrating, ";
  ++phase;
  delay(1000);
}
