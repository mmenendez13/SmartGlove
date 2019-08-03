/*
 * How to configure and pair two HC-05 Bluetooth Modules
 * by Dejan Nedelkovski, www.HowToMechatronics.com
 * 
 *                 == MASTER CODE ==
 */
#define ledPin 6
#define led2Pin 7
#define led3Pin 8
int MotorPin = 9;
int state = 0;
int potValue = 0;
void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  pinMode (led2Pin, OUTPUT);
  digitalWrite(led2Pin, LOW);
  pinMode (led3Pin, OUTPUT);
  digitalWrite(led3Pin, LOW);
  //pinMode (MotorPin, OUTPUT);
  //digitalWrite(MotorPin, HIGH);
  Serial.begin(38400); // Default communication rate of the Bluetooth module
}
void loop() {
 if(Serial.available()){ // Checks whether data is comming from the serial port
    state = Serial.read(); // Reads the data from the serial port
 }
 // Controlling the LED
 if (state == '1') {
  digitalWrite(ledPin, HIGH); // LED ON
  state = 0;
 }
 else if (state == '0') {
  digitalWrite(ledPin, LOW); // LED ON
  state = 0;
 }
 else if (state == '2'){
  digitalWrite(led2Pin, HIGH);
  }
 else if (state == '3') {
  digitalWrite(led2Pin, LOW);
 }
 else if (state == '4'){
  analogWrite (MotorPin, 255);
  //digitalWrite (led3Pin, HIGH);
  //digitalWrite (led2Pin, LOW);
  //digitalWrite (ledPin, LOW);
   }
  else if (state == '5'){
    //digitalWrite (led3Pin, LOW);
    analogWrite (MotorPin, 0);
  }

}
