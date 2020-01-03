/*The Button class interacts with the push button functionality of the KY-040 Rotary Encoders on the time drop controler. 
  The buttons are design to take in the parameters from different lines or pumps and then actuate them. 
  Created by: Jordan MacHardy 2019
 */

#include "Button.h"
#include "Arduino.h"


Button::Button( int var_buttonState, int var_lineNum, int var_lineState[], int var_pins[], String var_debugString)
{
  buttonState=var_buttonState;
  lineNum=var_lineNum;
  lineState[6] = var_lineState;
  pins[6]=var_pins;
  debugString=var_debugString;
  _prev_buttonState=0;
}

// Update method takes in the button state and line/pump to be actuated. 
void Button::Update(int var_buttonState,int var_lineNum)
{
    // Checks if button has been pushed
     if (var_buttonState != _prev_buttonState) 
    {

    // Updates apropriate parameter
      if (var_buttonState == 0) 
      {
          switch (lineState[ var_lineNum - 1])
          {
            case 0:
              lineState[ var_lineNum - 1] = 1;
              break;
    
            case 1:
              lineState[ var_lineNum - 1] = 0;
              break;
    
            default:
              break;
          }
      
      // Prints debug value
          if (lineState[ var_lineNum - 1] != 0) 
          {
            digitalWrite(pins[ var_lineNum-1], LOW);
            Serial.print(debugString);
            Serial.print( var_lineNum);
            Serial.println("  state low");
          }
          
          else
          {
            digitalWrite(pins[ var_lineNum-1], HIGH);
            Serial.print(debugString);
            Serial.print( var_lineNum);
            Serial.println("  state high");
          }
  
      }
    _prev_buttonState = var_buttonState; 
  }
}
    



  
