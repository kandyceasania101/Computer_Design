Lab 1:
Use the onboard LED on pin 13, a red led on a second digital pin of your choice and a green led on a third digital pin of your choice. 
Have these cycle so only one LED is on at any given point in time.  So your onboard LED should turn on, then it should turn off and your red LED should turn on, then it should turn off and your green LED should turn on, then onboard, then red, then green, etc . . .
The digital pins should be labeled 0-13 on your board.
Each off-board LED should be connected to a 220 Ohm resistor.
Note that this will mean you have two connect two separate LEDs
----------------------------------------------------------------------------------------------------------------------------------
Lab 2:
Use two switches and three LEDs for this circuit. One switch will increment a 3-bit count, and the other switch should decrement the 3-bit count. 
The 3-bit count will be displayed on the three LEDs in binary (a 1 is LED on).  
You should write code to keep track of the number of button presses and algorithmically convert that number to a binary output.  Your code should NOT just be implementing a giant lookup table to translate to binary, and solutions which do so will not receive credit.
Your lights should increment (or decrement) by one each time the switch is pressed. If we continually depress the switch, the lights should not run up (or down) to 7 (or 0) (i.e. it should only change the value once per button press).
Also document what happens when you reach 7 and/or 0.
----------------------------------------------------------------------------------------------------------------------------------
Lab 3:
Display your name and your favorite quote appear on the 16x2 display, name on first line and quote on the second line. The quote should not all fit on the screen and so should scroll across the screen. Your name should not scroll across the screen, only the quote should scroll.  
----------------------------------------------------------------------------------------------------------------------------------
Lab 4:
Create a circuit and program that will use a photoresistor and the 16x2 display. The display should state the relative amount of light in the room (dark, partially dark, medium, partially light, fully lit.) in the room, or fully lit, or somewhere in between should be displayed based on the value read from the photocell. This involves you determining the range of values the photoresistor provides and then making reasonable ranges for the values being considered.
----------------------------------------------------------------------------------------------------------------------------------
Lab 5:
This lab we will be experimenting with multiple inputs and outputs.  There will be two parts:
1) You will be using 4 LEDS and a photoresistor.  Put all 4 LEDs next to each (preferably the same color).  As the amount of light seen by the photoresistor decreases, increase the number of LEDs that are lit.  For example, if your circuit receives no light then all of the LEDs should light up.  As you continue to increase the amount of light, the number of LEDs that light up will decrease.  So when the photoresistor receives the half the amount of light, 2 LEDS should be lit up, and when there is no light, all 4 LEDs should be lit up.
2) In parallel with part 1, you will be using the the passive buzzer and the potentiometer.  Use the potentiometer as an analog input and have the output come from another analog pin.  Control the volume or tone of the buzzer by adjusting the potentiometer.  Make sure to have code to control the output of the buzzer based on the potentiometer.
----------------------------------------------------------------------------------------------------------------------------------
Lab 6:
Have your arduino get the date(mm/dd/yyyy) & time(hh/mm/ss) from the user via the serial monitor in the arduino software. 
Date includes day, month and year
Time includes hour, minutes and seconds
You circuit/program should:
print a prompt on the serial monitor,
get input of date and time from user  
display date  and time on the 16x2 display 
keep accurate time on 16x2 display 
include error checking for input that doesn't make sense (hours  not in range of 0 to 23, minutes not in range 0 to 59, month not range of 1 to 12, etc).
