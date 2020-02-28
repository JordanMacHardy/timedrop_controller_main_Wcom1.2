# timedrop_mechatronics_controller

This program is designed to control the mechanical functions of the Time Drop interactive art experience. 
It runs on elegoo mega 2560 Boards, with four Cylewet KY-040 Rotary Encoders/Buttons.

The four rotary encoders (knobs) are used for selecting or incrementing different parameters and the buttons are used to turn various things on and off. Starting from left to right are knobs 1-4 and buttons 1-4.

Knob1: Actuates the angle of water pressure adjustment servos.
Knob2: Selects servos on the current line.
Knob3: Selects lines.
Knob4: Actuates return flow valve at the end of each line.

Button1: Turns on/off a line's 2nd set of pumps, as well as the pump to the left eagle eye when line #7 is selected.
Button2: No Function
Button3: Turns on/off power to lines of servos.
Button4: Turns on/off first set of pumps, as well as the left eagle eye when line 7 is selected.

Pinouts:

Board 1: 
Line LEDs:            A0-A6
Servo Select LEDs:    41,43,45,47,49,51
Servo Line 1:         2-7
Servo Line 2:         8-13
Servo Power:          34,36,38,40,A14,A15
First Pumps (A):      22,24,26,A11,A9,A12
Second Pumps (B):     28,30,A8,A10,A13

knob1 clk, dt:        37,25
knob2 clk, dt:        31,33
knob3 clk, dt:        27,29
knob4 clk, dt:        23,25
SDA, SCL:             20,21



