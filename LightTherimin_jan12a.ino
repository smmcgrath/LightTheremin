// stores the values read from light sensor
int sensorValue;
// min and max values used for calibration
int sensorLow = 1023;
int sensorHigh = 0;

// constant, using onboard LED on pin 13
const int ledPin = 13;

void setup() {
  // turn on LED to signal the beginning of calibration
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  // calibrate during the first 5 seconds
  while (millis() < 5000){
    sensorValue = analogRead(A0);

    // record the maximum sensor value
    if (sensorValue > sensorHigh){
      sensorHigh = sensorValue;
    }

    // record the minimum sensor value
    if (sensorValue < sensorLow){
      sensorLow = sensorValue;  
    }
  }//end while loop

  // signal the end of calibration period
  digitalWrite(ledPin, LOW);
}//end setup

void loop() {
  // read the input from A0
  sensorValue = analogRead(A0);
  
  // map the sensor values to  a wide range of pitches
  // adjust the values below to conform to the maximum
  // and minimum values from the sensor
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);

  // play the tone
  // in the format (pin, pitch, duration)
  tone(8, pitch, 20);

  // wait for period
  delay(10);
  
}//end loop
