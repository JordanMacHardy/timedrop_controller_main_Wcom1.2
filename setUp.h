/*  this is the set up file for the Time Drop Controler. It configures all pins and initilizes all hardware
 * Created by: Jordan MacHardy Aug 2019
 */

#ifndef setUp // protects against multiple inclusions of library
#define setUp // protects against multiple inclusions of library

#include <Arduino.h>



pinMode(lineLED1, OUTPUT);
pinMode(lineLED2, OUTPUT);
pinMode(lineLED3, OUTPUT);
pinMode(lineLED4, OUTPUT);
pinMode(lineLED5, OUTPUT);
pinMode(lineLED6, OUTPUT);

pinMode(pump_a_power_Pin1, OUTPUT);
pinMode(pump_a_power_Pin2, OUTPUT);
pinMode(pump_a_power_Pin3, OUTPUT);
pinMode(pump_a_power_Pin4, OUTPUT);
pinMode(pump_a_power_Pin5, OUTPUT);

pinMode(pump_b_power_Pin1, OUTPUT);
pinMode(pump_b_power_Pin2, OUTPUT);
pinMode(pump_b_power_Pin4, OUTPUT);
pinMode(pump_b_power_Pin5, OUTPUT);
pinMode(pump_b_power_PinEl, OUTPUT);
pinMode(pump_a_power_PinEr, OUTPUT);


digitalWrite(pump_a_power_Pin1, HIGH);
digitalWrite(pump_a_power_Pin2, HIGH);
digitalWrite(pump_a_power_Pin3, HIGH);
digitalWrite(pump_a_power_Pin4, HIGH);
digitalWrite(pump_a_power_Pin5, HIGH);

digitalWrite(pump_b_power_Pin1, HIGH);
digitalWrite(pump_b_power_Pin2, HIGH);
digitalWrite(pump_b_power_Pin4, HIGH);
digitalWrite(pump_b_power_Pin5, HIGH);
digitalWrite(pump_b_power_PinEl, HIGH);
digitalWrite(pump_a_power_PinEr, HIGH);

pinMode(servoPowerPin1, OUTPUT);
pinMode(servoPowerPin2, OUTPUT);
pinMode(servoPowerPin3, OUTPUT);
pinMode(servoPowerPin4, OUTPUT);
pinMode(servoPowerPin5, OUTPUT);

digitalWrite(servoPowerPin1, HIGH);
digitalWrite(servoPowerPin2, HIGH);
digitalWrite(servoPowerPin3, HIGH);
digitalWrite(servoPowerPin4, HIGH);
digitalWrite(servoPowerPin5, HIGH);



pinMode(lineOnButton, INPUT);
pinMode(pump_a_OnButton, INPUT);
pinMode(pump_b_OnButton, INPUT);


pinMode(servoSelectLED1, OUTPUT);
pinMode(servoSelectLED2, OUTPUT);
pinMode(servoSelectLED3, OUTPUT);
pinMode(servoSelectLED4, OUTPUT);
pinMode(servoSelectLED5, OUTPUT);
pinMode(servoSelectLED6, OUTPUT);
pinMode(abLED, OUTPUT);


servo1.attach(servo1Pin); servo2.attach(servo2Pin); servo3.attach(servo3Pin); servo4.attach(servo4Pin); servo5.attach(servo5Pin); servo6.attach(servo6Pin);
servo1.write(controlKnob1.angles[0]); servo2.write(controlKnob1.angles[1]); servo3.write(controlKnob1.angles[3]); servo4.write(controlKnob1.angles[4]); servo5.write(controlKnob1.angles[2]); servo6.write(returnValveKnob6.angles[0]);
delay(15);

servo2_1.attach(servo2_1Pin); servo2_2.attach(servo2_2Pin); servo2_3.attach(servo2_3Pin); servo2_4.attach(servo2_4Pin); servo2_5.attach(servo2_5Pin); servo2_6.attach(servo2_6Pin);
  servo2_1.write(controlKnob2.angles[0]); servo2_2.write(controlKnob2.angles[1]); servo2_3.write(controlKnob2.angles[2]); servo2_4.write(controlKnob2.angles[3]); servo2_5.write(controlKnob2.angles[4]); servo2_6.write(returnValveKnob2.angles[0]);
delay(15);

Wire.begin(); // join i2c bus 
Serial.begin (9600);

#endif // protects against multiple inclusions of library
