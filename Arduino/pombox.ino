/*   Pomodoro Timer Module
     Project Written by Cameron Trumpy

     Intended use: Increase focus and productivity while studying

     How to use:
      If phone is present and a distraction, place phone in module. Press cycle start button to start your timer.

      If phone is removed, timer pauses. for longer than 20 seconds, beeps and intensity of beeps increases the longer phone is removed.

      count of succesful cycles in session is recorded in the bottom right corner.
*/
#include <Wire.h>
#include <SerLCD.h>
//GPIO vars

//GPIO notes good ones - 13,12,14 out,

int upButton = 10, confirmButton = 0, cancelButton = 13, trigger = 12;
int alarm = 14;
/*
   wacky display state machine section + GLOBAL TIMER VARS
*/
enum pageOptions {MAIN_PAGE, COUNTDOWN, SETTINGS};
enum pageOptions page;

int workTime = (25 * 60);
String workString;
int breakTime = (5 * 60);

boolean working = true;
boolean phoneMode = false;
boolean timerPaused = false;
boolean flipToggle = false;

int initTime;
int currTime;

int cycles = 0;
String cycleString;

/*
   end of display state machine section
*/

void setup() {
  //assign button addresses
  pinMode(alarm, OUTPUT);
  pinMode(upButton, INPUT_PULLUP);
  pinMode(confirmButton, INPUT_PULLUP);
  pinMode(cancelButton, INPUT_PULLUP);
  pinMode(trigger, INPUT_PULLUP);

  Serial.begin(9600); //Start serial communication at 9600 for debug statements
  delay(500);
  initDisp();
  delay(500);
}

boolean upPressed, confirmPressed, cancelPressed, triggerPressed;

void readInputs() {
  delay(100);
  upPressed = (digitalRead(upButton) == LOW);
  confirmPressed = (digitalRead(confirmButton) == LOW); // DO NOT PRESS DOWN WHILE BOOTING
  cancelPressed = (digitalRead(cancelButton) == LOW);
  triggerPressed = (digitalRead(trigger) == LOW);

}

void loop() {
  readInputs();
  loopDisp();
  alarmMonitor();
}
