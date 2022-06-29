/* Using the TMP36 sensor to take temperature readings,
   display it on the 4 digit 7 segment.

   Components:
                - Arduino Uno
                - TMP36 temperature sensor
                - 4 digit 7 segment display
                - 1kOhm resistor (x 4)

   Datasheet: https://www.analog.com/media/en/technical-documentation/data-sheets/TMP35_36_37.pdf

   Created on 10 June 2022 by c010rblind3ngineer
*/

int pinA = 11;
int pinB = 7;
int pinC = 4;
int pinD = 2;
int pinE = 1;
int pinF = 10;
int pinG = 5;
int pinDP = 3;

int D1 = 12;
int D2 = 9;
int D3 = 8;
int D4 = 6;

int sensorPin = 0;
float supplyVoltage = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinA, OUTPUT);  //11
  pinMode(pinB, OUTPUT);  //7
  pinMode(pinC, OUTPUT);  //4
  pinMode(pinD, OUTPUT);  //2
  pinMode(pinE, OUTPUT);  //1
  pinMode(pinF, OUTPUT);  //10
  pinMode(pinG, OUTPUT);  //5
  pinMode(D1, OUTPUT);    //12
  pinMode(D2, OUTPUT);    //9
  pinMode(D3, OUTPUT);    //8
  pinMode(D4, OUTPUT);    //6

}

void loop() {
  // get voltage reading from TMP36
  int reading = analogRead(sensorPin);

  // convert the reading to voltage
  float voltage = reading * supplyVoltage / 1024;

  // convert voltage to temperature
  float tempC = (voltage - 0.5) * 100; // we need to convert from 10mV per degreee with 0.5V offset

  // display temperature digits on 4 digit 7 segment display
  int tempd1 = int(tempC / 10);
  int tempd2 = int((int)tempC % 10);

  // 'for' loop ensures the display is constantly ON within a period of time (approx. 10s)...
  // ...before sensor takes another reading.
  // Temperature reading
  for (int i = 0; i < 2000; i++) {
    digitalWrite(D1, LOW);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, HIGH);
    disp(tempd1);
    delay(1);

    digitalWrite(D1, HIGH);
    digitalWrite(D2, LOW);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, HIGH);
    disp(tempd2);
    delay(1);

    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, LOW);
    digitalWrite(D4, HIGH);
    disp(11);
    delay(1);

    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, LOW);
    disp(10);
    delay(1);
  }
  displayoff();
  delay(1000);

}

void disp(int number) {

  switch (number) {
    case 0 : // display '0' on 7 segment
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);
      break;

    case 1 : // display '1' on 7 segment
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      break;

    case 2 : // display '2' on 7 segment
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, LOW);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, HIGH);
      break;

    case 3 : // display '3' on 7 segment
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, HIGH);
      break;

    case 4 : // display '4' on 7 segment
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      break;

    case 5 : // display '5' on 7 segment
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      break;

    case 6 : // display '6' on 7 segment
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      break;

    case 7 : // display '7' on 7 segment
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      break;

    case 8 : // display '8' on 7 segment
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      break;

    case 9 : // display '9' on 7 segment
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      break;

    case 10 :  // display 'C' on 7 segment
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, LOW);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);
      break;

    case 11 :  // display 'o' on 7 segment
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, LOW);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      break;
  }
}

void displayoff() {
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);
}
