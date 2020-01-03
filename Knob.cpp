#include "Arduino.h"
#include "Knob.h"


// Constructor 
Knob::Knob( int ClkPin, int DtPin,  int EncoderMin, int EncoderMax, int ServoSelect, int initCounter[6], int initMinAngles[6], int initMaxAngles[6], int initAngles[6] )
{
     
  // Initializes atributes from input variables
  for (int i = 0; i <= 5; i ++)
  {
    counters[i] = initCounter[i];
    minAngles[i] = initMinAngles[i];
    angles[i] = initAngles[i];
    maxAngles[i] = initMaxAngles[i];
  }
  
    encoderMax = EncoderMax;
    encoderMin = EncoderMin;

    // Public parameters used by other methods
    servoSelect = ServoSelect;
    servoIndex = ServoSelect - 1;
    clkPin = ClkPin;
    dtPin = DtPin;
    printAngleOn = 0;
    presentState = 0;
    previousState = 0;

    // Sets pinmodes of pins for knob object
    pinMode (clkPin, INPUT_PULLUP);
    pinMode (dtPin, INPUT_PULLUP);
}


// Print angle prints angle on the next call of update method.
void Knob::printAngle() 
{
  printAngleOn = 1;
}


// Update method takes in "servoSelect" Parameter and then updates an array of "angles" specific to the knob object. 
// The angles are integer values an cand be used as counters to increment other knob objects 
void Knob::Update(int servoSelect)
{
  servoIndex = servoSelect - 1; // Makes code clearer
  presentState = digitalRead(clkPin); // updates state from knob pin (ib order to se if knob has been moved
 

  // Check to see if there is a change in the knob state.
  if (presentState != previousState)
  {

     if (digitalRead(dtPin) != presentState) // checks if the physical knob has been turned CW or CCW
    {

        if (counters[servoIndex] < encoderMax) // Checks if counder is beyond encoder max
        {
           counters[servoIndex] = counters[servoIndex] + 1; // increments apropriate counter
        }

    }

        else if(counters[servoIndex] > encoderMin) // Checks if counder is beyond encoder min
        {
           counters[servoIndex] = counters[servoIndex] - 1; // decrements counter
        }

    // maps counters to angles 
    angles[servoIndex] = map(counters[servoIndex], encoderMin, encoderMax, minAngles[servoIndex], maxAngles[servoIndex]); 


    // Prints to serial monitor
    if (printAngleOn == 1) 
    {

    Serial.print("Servo ");
    Serial.print(servoSelect);
    Serial.print("  angle  ");
    Serial.println(angles[servoIndex]);


    printAngleOn = 1; // if printAngleOn is set to 1 here, it is always on. Used for debugging. 
    }

    previousState = presentState; // updates state for next iteration
      
  }

}
