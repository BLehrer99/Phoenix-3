#include <SPI.h>
#include <SD.h>

File myFile;

bool sdStart = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  if (!SD.begin(4)) {
    while (1);
  } else {
    sdStart = true;
  }
}

void loop() {
  if (sdStart) {
    digitalWrite(2, HIGH);
  } else {
    digitalWrite(2, LOW);
  }
  if (Serial.available()) {
    myFile = SD.open("LOG.txt", FILE_WRITE);
    myFile.write(Serial.read());
    myFile.close();
  }
}
