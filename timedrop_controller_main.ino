/* This is the main script for the Time warp controler
    Created by: Jordan MacHardy
*/

// Include Libraries and classes
#include <Servo.h>
#include <Wire.h>
#include "Knob.h"
#include "Button.h"
#include "pin_definitions.h"
#include "globalVariables.h"


///Instantiate Objects ///

//The knob class is designed to interact with the controlers rotary encoder knbos. controlKnobs 1-6 interact with the banks of servos that adjust the preasure for individual droplets on a line. Each line has upto 6 droplets.
Knob controlKnob1(  servoControlPinA, servoControlPinB, encoderMin, encoderMax, 1, initCounterServos, minAngles[0], maxAngles[0], initServoAngles[0]);
Knob controlKnob2( servoControlPinA, servoControlPinB, encoderMin, encoderMax, 1, initCounterServos, minAngles[1], maxAngles[1], initServoAngles[1]);
Knob controlKnob3( servoControlPinA, servoControlPinB, encoderMin, encoderMax, 1, initCounterServos, minAngles[2], maxAngles[2], initServoAngles[2]);
Knob controlKnob4( servoControlPinA, servoControlPinB, encoderMin, encoderMax, 1, initCounterServos, minAngles[3], maxAngles[3], initServoAngles[3]);
Knob controlKnob5( servoControlPinA, servoControlPinB, encoderMin, encoderMax, 1, initCounterServos, minAngles[4], maxAngles[4], initServoAngles[4]);
Knob controlKnob6( servoControlPinA, servoControlPinB, encoderMin, encoderMax, 1, initCounterServos, minAngles[5], maxAngles[5], initServoAngles[5]);

// The retern valves controle how much of flow from each line gets re-routed back to the source. 
Knob returnValveKnob1( returnValveKnobPinA, returnValveKnobPinB, encoderMin, encoderMax, 1, initCounterreternValve, reternValveminAngles[0],  reternValveMaxAngles, initreternValveAngles);
Knob returnValveKnob2( returnValveKnobPinA, returnValveKnobPinB, encoderMin, encoderMax, 1, initCounterreternValve, reternValveminAngles[1],  reternValveMaxAngles, initreternValveAngles);
Knob returnValveKnob3( returnValveKnobPinA, returnValveKnobPinB, encoderMin, encoderMax, 1, initCounterreternValve, reternValveminAngles[2],  reternValveMaxAngles, initreternValveAngles);
Knob returnValveKnob4( returnValveKnobPinA, returnValveKnobPinB, encoderMin, encoderMax, 1, initCounterreternValve, reternValveminAngles[3],  reternValveMaxAngles, initreternValveAngles);
Knob returnValveKnob5( returnValveKnobPinA, returnValveKnobPinB, encoderMin, encoderMax, 1, initCounterreternValve, reternValveminAngles[4],  reternValveMaxAngles, initreternValveAngles);
Knob returnValveKnob6( returnValveKnobPinA, returnValveKnobPinB, encoderMin, encoderMax, 1, initCounterreternValve, reternValveminAngles[5],  reternValveMaxAngles, initreternValveAngles);

// The servo select knob selects a specific servo on a given line.
Knob servoSelectKnob( servoSelectPinA, servoSelectPinB, 1, 12, 1, initCounterSelectKnobs, minAnglesSelcectKnobs, maxAnglesSelcectKnobs, initCounterAngles);
// The line select knob selects the lines...
Knob lineSelectKnob( lineSelectKnobPinA, lineSelectKnobPinB, 1, 12, 1, initCounterSelectKnobs, minAnglesSelcectKnobs, maxAnglesSelcectKnobs, initCounterAngles);


//The Button class is designed to interact with the push buttons on the controler. It takes in the state of a button (read from a pin), actuates relay outputpins, and stores "state" values. 
Button servoPowerButton( servo_power_button_state, lineNum, initServolineState, servo_power_pins, "servo_line_" ); // turns the power to a line of servos on or off. 
Button pump_a_PowerButton(pump_a_power_button_state, lineNum, initPump_a_state, pump_a_pins, "pump_a_"); // turns the power for the first pump on a line on or off. 
Button pump_b_PowerButton(pump_b_power_button_state, lineNum, initPump_b_state, pump_b_pins, "pump_b_"); // turns the power for the second pump on a line on or off. 

// Instantiate servo Objects
Servo servo1; Servo servo2; Servo servo3; Servo servo4; Servo servo5; Servo servo6;
Servo servo2_1; Servo servo2_2; Servo servo2_3; Servo servo2_4; Servo servo2_5; Servo servo2_6;


/// SetUp///
void setup() 
{

//See setUp.h 
#include "setUp.h"

}

/// Main Loop ///
void loop() 
{


  
  servoNum = servoSelectKnob.angles[0]; // this updates the servo selector number.
  lineNum = lineSelectKnob.angles[0]; // Updates the line select number
  servo_power_button_state = digitalRead(lineOnButton); // Second button from right. Turns on an off servo power for a given line. 
  pump_a_power_button_state = digitalRead(pump_a_OnButton); // Right most button on controler. Turns on the first pump for given line
  pump_b_power_button_state = digitalRead(pump_b_OnButton); // Left most button on controler. Turns on the second pump for given line
  
  
  
  // Turn on and off servo power. Actuated by the push button of fourth knob
  servoPowerButton.Update(servo_power_button_state, lineNum);
  //Turns on and off pumps in pump box 1. Actuated by button on rightmost knob
  pump_a_PowerButton.Update(pump_a_power_button_state, lineNum);
  //Turns on and off pumps in pump box 2. Actuated by button on leftmost knob
  pump_b_PowerButton.Update(pump_b_power_button_state, lineNum);

// Used for debuging
//    if (lineNum != prevLine){
//    Serial.println(lineNum);
//    prevLine=lineNum;
//  }
//
//  
//  if (servoNum != prevServo){
//    Serial.println(servoNum);
//    prevServo=servoNum;
//    
//  }

  
   
  
  
  // Write to line LED's
  switch (lineNum)
  {
    case 1:
      analogWrite(A0, anOn); analogWrite(A1, anOff); analogWrite(A2, anOff); analogWrite(A3, anOff); analogWrite(A4, anOff); analogWrite(A5, anOff);
      break;
    case 2:
      analogWrite(A0, anOff); analogWrite(A1, anOn); analogWrite(A2, anOff); analogWrite(A3, anOff); analogWrite(A4, anOff); analogWrite(A5, anOff);
      break;
    case 3:
      analogWrite(A0, anOff); analogWrite(A1, anOff); analogWrite(A2, anOn); analogWrite(A3, anOff); analogWrite(A4, anOff); analogWrite(A5, anOff);
      break;
    case 4:
      analogWrite(A0, anOff); analogWrite(A1, anOff); analogWrite(A2, anOff); analogWrite(A3, anOn); analogWrite(A4, anOff); analogWrite(A5, anOff);
      break;
    case 5:
      analogWrite(A0, anOff); analogWrite(A1, anOff); analogWrite(A2, anOff); analogWrite(A3, anOff); analogWrite(A4, anOn); analogWrite(A5, anOff);
      break;
    case 6:
      analogWrite(A0, anOff); analogWrite(A1, anOff); analogWrite(A2, anOff); analogWrite(A3, anOff); analogWrite(A4, anOff); analogWrite(A5, anOn);
      break;
    default:
      break;
  
  }
    
    
  // Writes to Servo LED's
  switch (servoNum)
  {
    case 1:
      digitalWrite(servoSelectLED1, HIGH); digitalWrite(servoSelectLED2, LOW); digitalWrite(servoSelectLED3, LOW); digitalWrite(servoSelectLED4, LOW); digitalWrite(servoSelectLED5, LOW); digitalWrite(servoSelectLED6, LOW);
      break;
    case 2:
      digitalWrite(servoSelectLED1, LOW); digitalWrite(servoSelectLED2, HIGH); digitalWrite(servoSelectLED3, LOW); digitalWrite(servoSelectLED4, LOW); digitalWrite(servoSelectLED5, LOW); digitalWrite(servoSelectLED6, LOW);
      break;
    case 3:
      digitalWrite(servoSelectLED1, LOW); digitalWrite(servoSelectLED2, LOW); digitalWrite(servoSelectLED3, HIGH); digitalWrite(servoSelectLED4, LOW); digitalWrite(servoSelectLED5, LOW); digitalWrite(servoSelectLED6, LOW);
      break;
    case 4:
      digitalWrite(servoSelectLED1, LOW); digitalWrite(servoSelectLED2, LOW); digitalWrite(servoSelectLED3, LOW); digitalWrite(servoSelectLED4, HIGH); digitalWrite(servoSelectLED5, LOW); digitalWrite(servoSelectLED6, LOW);
      break;
    case 5:
      digitalWrite(servoSelectLED1, LOW); digitalWrite(servoSelectLED2, LOW); digitalWrite(servoSelectLED3, LOW); digitalWrite(servoSelectLED4, LOW); digitalWrite(servoSelectLED5, HIGH); digitalWrite(servoSelectLED6, LOW);
      break;
    case 6:
      digitalWrite(servoSelectLED1, LOW); digitalWrite(servoSelectLED2, LOW); digitalWrite(servoSelectLED3, LOW); digitalWrite(servoSelectLED4, LOW); digitalWrite(servoSelectLED5, LOW); digitalWrite(servoSelectLED6, HIGH);
      break;
    
    default:
      break;
  }
  
  
    // Updates knob obects if the physical knobs are used ///
    switch (lineNum)
  {
      case 1:
        controlKnob1.Update(servoNum);
        controlKnob1.printAngle(); // prints curant "angle" to serial
        returnValveKnob1.Update(1);        
        break;
  
      case 2:
        controlKnob2.Update(servoNum);
        controlKnob2.printAngle();
        returnValveKnob2.Update(1);
        break;
  
      case 3:
        controlKnob3.Update(servoNum);
        controlKnob3.printAngle();
        returnValveKnob3.Update(1);

        for( int i = 0; i < 6; i++)
        {
         sendArray[i+2] = controlKnob3.angles[i];
        }
        break;
  
      case 4:
        controlKnob4.Update(servoNum);
        controlKnob4.printAngle();
        returnValveKnob4.Update(1);
        break;
  
      case 5:
        controlKnob5.Update(servoNum);
        controlKnob5.printAngle();
        returnValveKnob5.Update(1);
        break;
  
      case 6:
        controlKnob6.Update(servoNum);
        controlKnob6.printAngle();
        returnValveKnob6.Update(1);
        break;
  
      default:
        break;
  }


  if (lineNum != prevLine){
    Serial.println(lineNum);
    sendArray[0] = lineNum;
    prevLine=lineNum;
  }

  
  if (servoNum != prevServo){
    Serial.println(servoNum);
    sendArray[1] = servoNum;
    prevServo=servoNum;
    
  }
 
 
 // Comunicating with other Arduinos


  for( int i = 0; i < 8; i++)
    {
    
          if(sendArray[i] != prevSendArray[i])
          { 
           sendArrayDifferent = 1;
         Serial.println("made it to diif cond");
           
          }
          
    }

  
  if(sendArrayDifferent == 1)
  {

    Wire.beginTransmission(Slave_1_Id);
    Wire.write((uint8_t*)&sendArray, sizeof(sendArray));
    Wire.endTransmission();
    Serial.println("sending");
  
    for( int j = 0; j < 8; j++)
    {
      prevSendArray[j] = sendArray[j];
      
     
    }

   sendArrayDifferent = 0;
 
  }
  

  // Updates State of selector knobs
  servoSelectKnob.Update(1);
  lineSelectKnob.Update(1);

  // Sends angles via pwm to servos
  servo1.write(controlKnob1.angles[0]); servo2.write(controlKnob1.angles[1]); servo3.write(controlKnob1.angles[3]); servo4.write(controlKnob1.angles[4]); servo5.write(controlKnob1.angles[2]); servo6.write(returnValveKnob6.angles[0]);
  servo2_1.write(controlKnob2.angles[0]); servo2_2.write(controlKnob2.angles[1]); servo2_3.write(controlKnob2.angles[2]); servo2_4.write(controlKnob2.angles[3]); servo2_5.write(controlKnob2.angles[4]); servo2_6.write(returnValveKnob2.angles[0]);


} // End loop
