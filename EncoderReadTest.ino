//// encoder declarations
//#define ENCODER_SENSOR 2
//
//void setup() {
//  Serial.begin(115200);
//  attachInterrupt(0, change_encoder_sensor, CHANGE);
//  Serial.print("Started encoder test\n");
//}
//
//void loop() {
//  // put your main code here, to run repeatedly:
//
//}
//
//void change_encoder_sensor(){
//  //encoder variables
//  byte sensorStatusB = 0;
//  sensorStatusB = digitalRead(ENCODER_SENSOR);
//  if (sensorStatusB == LOW)
//    Serial.print("B is low\n");
//
//  if (sensorStatusB == HIGH)
//    Serial.print("B is high\n");
//
//    //Serial.println(sensorStatusB);
//}


/*
-Arduino Position Encoder
-Using a generic photo-interrupter
-Basic Test Sketch 1 / June 2014
-Tested at TechNode Protolabz
-www.electroschematics.com/
*/
const int encoderIn = 8; // input pin for the interrupter 
const int statusLED = 13; // Output pin for Status indicator
const int pulseOutput = 12; // Pulse output pin for external interfacing
int detectState=0; // Variable for reading the encoder status
void setup()
{
   pinMode(encoderIn, INPUT); //Set pin 8 as input
   pinMode(statusLED, OUTPUT); //Set pin 13 as output
   pinMode(pulseOutput, OUTPUT); // Set Pin 12 as output
}
void loop() {
   detectState=digitalRead(encoderIn);
   if (detectState == HIGH) { //If encoder output is high
      digitalWrite(statusLED, HIGH); //Turn on the status LED
      digitalWrite(pulseOutput,HIGH); // Give a logic-High level output
   }
   else {
      digitalWrite(statusLED, LOW); //Turn off the status LED
      digitalWrite(pulseOutput,LOW); // Give a logic-Low level output
   }
}
