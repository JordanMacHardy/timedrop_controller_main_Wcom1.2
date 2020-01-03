/* This file initializes all global variables for the Time Drop Controler
 * Created by: Jordan MacHardy Aug 2019
 */

#include "Arduino.h"

  extern int minAngles[6][6] =       {{8, 8,10,10,10,10}, // Each value represents a minimum angle for a particular servo.
                                      {7,20,7,13,13,10},
                                      {10,10,10,10,10,10}, 
                                      {10,10,10,10,10,10},
                                      {10,10,10,10,10,10},
                                      {10,10,10,10,10,10}};

  extern int maxAngles[6][6] =        {{75,75,75,75,75,75}, // Each value represents a maximum angle for a particular servo.
                                       {75,75,80,75,75,75},
                                       {75,75,75,75,75,75},
                                       {75,75,75,75,75,75},
                                       {75,75,75,75,75,75},
                                       {75,75,75,75,75,75} };


extern  int initServoAngles[6][6] =   {{8, 8,75,10,13, 7 }, // Each value represents a initial angle for a particular servo.
                                       {10,20,80,13,13,75},
                                       {10, 5, 5,10,10,75},
                                       {10,10,10,10,10,75},
                                       {10,10,10,10,10,75},
                                       {10,10,10,10,10,10} };
        
        
extern  int initCounterServos[6] =     {1,1,49,1,1,1};     // Initializes the counters. Each knob object utilizes a counter as well as 
                                                          //angles so ranges can be scaled to a range that make the knobs easy to use
        
        
extern  int reternValveminAngles[6][6]={{10,10,10,10,10,10},  // Sets minimum angles for the return valves at the end of each line. There are more angles than return valves because 
                                       {10,5,10,10,10,10},    // The knob object is designed to be used in a variety of situations. The first line is the only important one. 
                                       {10,10,10,10,10,10},
                                       {10,10,10,10,10,10},
                                       {10,10,10,10,10,10},
                                       {7,10,10,10,10,10} };
        
        
        
extern  int reternValveMaxAngles[6] =   {75,75,75,75,75,75}; // sets the minimum angle of servos
extern  int initCounterreternValve[6] =  {1,49,49,49,49,49}; // initial ball valve B angles
extern  int minAnglesSelcectKnobs[6] =  {1,1,1,1,1,1}; // sets the line select and servo select to min values ( the first position is all that maters)
extern  int maxAnglesSelcectKnobs[6] =  {6,6,6,6,6,6}; // sets the line select and servo select to min values ( the first position is all that maters)
extern  int initCounterAngles[6] =      {1,1,1,1,1,1}; // for counters used for selectiong serveos or lines  the "angles" are the count, and should all start at 
extern  int initCounterSelectKnobs[6] = {1,1,1,1,1,1}; // all counters start at 
extern  int encoderMin =0; // encoder global min
extern  int encoderMax =50; // encoder global max
extern  int maxreternValveAngles[6] =    {75,75,75,75,75,75};
extern  int maxCounterAngles[6] =       {6,6,6,6,6,6};
extern  int initreternValveAngles[6] =   {75,1,1,1,1,1}; // initial ball valve b angles, the only one that maters is the first position

extern  int servoNum= 1; 
extern  int prevServo=0;
extern  int lineNum=1;
extern  int prevLine=0;
  
extern  int initServolineState[6] = {0,0,0,0,0,0}; 
  
extern  int initPump_a_state[6] = {0,0,0,0,0,0}; // note ER (eagle right eye is pump_a_state[5]
extern  int initPump_b_state[6] = {0,0,0,0,0,0};  // // note EL (eagle left eye is pump_b_state[5]
extern  int pump_a_pins[6] = {pump_a_power_Pin1, pump_a_power_Pin2, pump_a_power_Pin3, pump_a_power_Pin4, pump_a_power_Pin5, pump_a_power_PinEr};
extern  int pump_b_pins[6] = {pump_b_power_Pin1, pump_b_power_Pin2, defraculationPin , pump_b_power_Pin4, pump_b_power_Pin5, pump_b_power_PinEl};
extern  int servo_power_pins[6] = {servoPowerPin1, servoPowerPin2, servoPowerPin3, servoPowerPin4, servoPowerPin5, servoPowerPin5};
extern  int pump_a_power_button_state=0;
extern  int prev_pump_a_power_button_state=0;
extern  int servo_power_button_state=0;
extern  int prev_servo_power_button_state=0;
extern  int pump_b_power_button_state=0;
extern  int prev_pump_b_power_button_state=0;
extern  int abState=0;
extern  int initBallValve =80;
  
// for turning on and off the analoge pins for the leds.
extern  int anOn =1023;
extern  int anOff =0;

// Comunication variables
extern const byte Slave_1_Id = 1;
extern const byte Slave_2_Id = 2;
extern int sendArray[8] =     {0,0,0,0,0,0,0,0};
extern int prevSendArray[8] = {0,0,0,0,0,0,0,0};
extern int sendArrayDifferent = 0;
