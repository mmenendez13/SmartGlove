                                           /*
 * How to configure and pair two HC-05 Bluetooth Modules
 * by Dejan Nedelkovski, www.HowToMechatronics.com
 * 
 *                 == SLAVE CODE ==
 */
//#define button 8 
const int FLEX1 = A0; // Pin connected to voltage divider output
const int FLEX2 = A1;

// Measure the voltage at 5V and the actual resistance of your
// 47k resistor, and enter them below:
const float VCC = 4.98; // Measured voltage of Ardunio 5V line
const float R_DIV = 47500.0; // Measured resistance of 3.3k resistor

// Upload the code, then try to adjust these values to more
// accurately calculate bend degree.
const float STRAIGHT_RESISTANCE = 37300.0; // resistance when straight
const float BEND_RESISTANCE = 90000.0; // resistance at 90 deg



int state = 20;
//int buttonState = 0;
void setup() {
  //pinMode(button, INPUT);
  pinMode(FLEX1, INPUT);
  pinMode(FLEX2, INPUT);
 
  Serial.begin(38400); // Default communication rate of the Bluetooth module
}
void loop() {


 if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    state = Serial.read(); // Reads the data from the serial port
  }
   int flexADC = analogRead(FLEX1);
   int flex2ADC = analogRead(FLEX2);
  
   float flexV = flexADC * VCC / 1023.0;
   float flexV2 = flex2ADC * VCC / 1023.0;
   float flexR = R_DIV * (VCC / flexV - 1.0);
   float flexR2 = R_DIV * (VCC / flexV2 - 1.0); 
   float angle = map(flexR, STRAIGHT_RESISTANCE, BEND_RESISTANCE,
                     0, 90.0);
   // Reading the button
   //buttonState = digitalRead(button);
   if (flexR > 40000 && flexR2 < 40000) {
     Serial.write('1'); // Sends '1' to the master to turn on LED
   }
   else {
     Serial.write('0');
   } 
  
   if (flexR2 > 40000 && flexR < 40000){
    Serial.write('2');     //Output for second LED
   }
   else {
    Serial.write('3');
    }
    if (flexR2 > 40000 && flexR > 40000){
      Serial.write('4');
    }
    else {
      Serial.write('5');
    }
   

  
 
  
}
