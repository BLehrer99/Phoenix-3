#include <Servo.h>

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

Adafruit_BNO055 bno = Adafruit_BNO055(55);

Adafruit_BMP280 bme;

Servo Zero;
Servo One;

int zero = 90;
int one = 90;

float streamOutputs[5];

float qfe;

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

void setupAHRS() {
  Serial.println("Vehicle is in self-align");
  /* Initialise the sensor */
  if (!bno.begin()) {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.println("No BNO055 detected");
    return;
  }
  delay(1000);
  /* Display some basic information on this sensor */
  displaySensorDetails();
  /* Optional: Display current status */
  displaySensorStatus();
  bno.setExtCrystalUse(true);
}

void setupPressure() {
  if (!bme.begin()) {
    Serial.println("Could not find a valid BMP280 sensor, check wiring!");
    return;
  }
  qfe = bme.readPressure() / 100.0;
}

void sendData() {
  Serial.write((byte*)streamOutputs, 5 * sizeof(streamOutputs[0]));
}

void readTelemetry() {
  sensors_event_t event;
  bno.getEvent(&event);

  streamOutputs[0] = event.orientation.y;
  streamOutputs[1] = event.orientation.z;
  streamOutputs[2] = event.orientation.x;
  streamOutputs[3] = bme.readAltitude(qfe);
  streamOutputs[4] = micros();
}

void setup() {
  Wire.begin();
  Serial.begin(38400);
  Zero.attach(10);
  One.attach(11);

  setupAHRS();
  setupPressure();
}

void loop() {
  if (Serial.available()) {
    unsigned char input = Serial.read();
    if (input >= 128) {
      one = input - 128;
    } else {
      zero = input;
    }
  }
  Zero.write(zero);
  One.write(one);

  readTelemetry();

  sendData();
}
