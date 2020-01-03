/* Knob Class interacts with KY-040 Rotary Encoders on the Time Drop Controller. 
 * Created by: Jordan MacHardy 2019 
 */

#ifndef Knob_h
#define Knob_h

#include "Arduino.h"

class Knob
{
  public:
  Knob( int ClkPin, int DtPin,  int EncoderMin, int EncoderMax, int ServoSelect, int initCounter[6], int minAngles[6],int maxAngles[6], int initAngles[6] );
  void printAngle();
  void Update(int servoSelect);
  // Public Atributes
  int presentState;
  int previousState;
  int counters[6];
  int angles[6];
  int initCounter[6];
  int servoSelect;
  int servoIndex;
  // user parameters
  int encoderMax;
  int encoderMin;
  int minAngles[6];
  int maxAngles[6];
  int printAngleOn;
  // hardware parameters
  int clkPin;
  int dtPin;
  
    
};


#endif
