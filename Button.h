/*The Button class interacts with the push button functionality of the KY-040 Rotary Encoders on the time drop controler. 
  The buttons are design to take in the parameters from different lines or pumps and then actuate them. 
  Created by: Jordan MacHardy 2019
 */
#ifndef Button_h
#define Button_h

#include "Arduino.h"

class Button 
{
  public:
  Button( int var_buttonState, int var_lineNum, int var_lineState[6], int var_pin[6], String var_debugString);
  void Update(int var_buttonState, int var_lineNum);
  //public atributes
  int buttonState;
  int lineNum;
  int lineState[6];
  int pins[6];
  String debugString;
  //private atributes
  private:
  int _prev_buttonState;
  
};

#endif
