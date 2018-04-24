/*
   Code Developed by Selcuk ARTUT 2018
   This code is developed for the RGB Tilt Workshop
   RGB Leds flux pins are 9(Red),10(Green),11(Blue) and 3(Red),5(Green),6(Blue)

*/
const int rPinLed1 = 3;
const int gPinLed1 = 5;
const int bPinLed1 = 6;

const int rPinLed2 = 9;
const int gPinLed2 = 10;
const int bPinLed2 = 11;

int rPinLedRandomValue;
int gPinLedRandomValue;
int bPinLedRandomValue;

const int tiltSensor = 2;
int sensorValue;

void setup() {
  // define led pins as outputs
  pinMode(rPinLed1, OUTPUT);
  pinMode(gPinLed1, OUTPUT);
  pinMode(bPinLed1, OUTPUT);
  pinMode(rPinLed2, OUTPUT);
  pinMode(gPinLed2, OUTPUT);
  pinMode(bPinLed2, OUTPUT);

  // define tilt pin as input
  pinMode(tiltSensor, INPUT);
}

void loop() {
  // let's check the tilt sensor
  sensorValue = digitalRead(tiltSensor);
  if (sensorValue == HIGH) {
    //begin randomization
    rPinLedRandomValue = random(0, 255);
    gPinLedRandomValue = random(0, 255);
    bPinLedRandomValue = random(0, 255);
    turnLedsOff();//keep leds off during the randomization for the surprise
  } else {
    analogWrite(rPinLed1, rPinLedRandomValue);
    analogWrite(gPinLed1, gPinLedRandomValue);
    analogWrite(bPinLed1, bPinLedRandomValue);
    analogWrite(rPinLed2, rPinLedRandomValue);
    analogWrite(gPinLed2, gPinLedRandomValue);
    analogWrite(bPinLed2, bPinLedRandomValue);
  }
  delay(100);
}

void turnLedsOff() {

  digitalWrite(rPinLed1, LOW);
  digitalWrite(gPinLed1, LOW);
  digitalWrite(bPinLed1, LOW);
  digitalWrite(rPinLed2, LOW);
  digitalWrite(gPinLed2, LOW);
  digitalWrite(bPinLed2, LOW);
}

