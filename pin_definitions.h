/* This labrary includes all hardware pin asignments
 *  Created by: Jordan MacHardy Jordan MacHardy 2019
 */

#ifndef pin_definitions // protects against multiple inclusions of library
#define pin_definitions // protects against multiple inclusions of library

#include <Arduino.h>

////////////////////Start Definition /////////////////////////////////////

#define returnValveKnobPinA 25 // CLK Pin Return Valve Rotary Encoder
#define returnValveKnobPinB 23 // DT Pin Return Valve Rotary Encoder
#define lineSelectKnobPinA 29 // CLK pin of Rotary Enocoder
#define lineSelectKnobPinB 27 // DT pin of Rotary Enocoder
#define servoSelectPinA 33 // CLK pin of Rotary Enocoder
#define servoSelectPinB 31// DT pin of Rotary Enocoder
#define servoControlPinA 37 // CLK pin of Rotary Enocoder
#define servoControlPinB 35// DT pin of Rotary Enocoder


// pumps and servo power on/off ///
#define pump_b_OnButton     50 // switches between first and second half each line, this is because there are two pumps per line
#define lineOnButton 53 // turns the line's servo power on
#define pump_a_OnButton 52 // used to turn the line's pump on

// For pump relays //
#define pump_a_power_Pin1  22
#define pump_b_power_Pin1 28  
#define pump_a_power_Pin2  24
#define pump_b_power_Pin2 30  
#define pump_a_power_Pin3  26


#define pump_a_power_Pin4  A11 
#define pump_b_power_Pin4 A10
#define pump_a_power_Pin5  A9
#define pump_b_power_Pin5 A8
#define pump_b_power_PinEl A13
#define pump_a_power_PinEr A12


// Servo Power relay pins //
#define servoPowerPin1 34
#define servoPowerPin2 36
#define servoPowerPin3 38
#define servoPowerPin4 40
#define servoPowerPin5 42
#define servoPowerPin6 A15
#define defraculationPin A14

// LED indicator pins //
#define lineLED1 A0
#define lineLED2 A1
#define lineLED3 A2
#define lineLED4 A3
#define lineLED5 A4
#define lineLED6 A5
#define abLED    A6

#define servoSelectLED1 51
#define servoSelectLED2 49
#define servoSelectLED3 47
#define servoSelectLED4 45
#define servoSelectLED5 43
#define servoSelectLED6 41

// servo pins //
#define servo1Pin 2
#define servo2Pin 3
#define servo3Pin 4
#define servo4Pin 5
#define servo5Pin 6
#define servo6Pin 7

#define servo2_1Pin 8
#define servo2_2Pin 9
#define servo2_3Pin 10
#define servo2_4Pin 11
#define servo2_5Pin 12
#define servo2_6Pin 13


#endif                // protects against multiple inclusions of library
