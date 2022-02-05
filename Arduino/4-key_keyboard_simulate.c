#include "Keyboard.h"

// button keybind 
#define BIND_1    'd'
#define BIND_2    'f'
#define BIND_3    'j'
#define BIND_4    'k'

//
// Button Pinout
#define BT_1  2
#define BT_2  3
#define BT_3  4
#define BT_4  5

void setup() {
  // put your setup code here, to run once:
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  pinMode(4,INPUT_PULLUP);
    Serial.begin(9600);                               // begin serial comms for debugging
}

void loop() {
  // put your main code here, to run repeatedly:
  Keyboard.begin();      

// Read button
 if(digitalRead(BT_1) == LOW) {
    Keyboard.press(BIND_1);
    //delay(30);
  } else if (digitalRead(BT_1) == HIGH)
  {
    Keyboard.release(BIND_1);
  }

  if(digitalRead(BT_2) == LOW) {
    Keyboard.press(BIND_2);
    //delay(30);
  } else if (digitalRead(BT_2) == HIGH)
  {
    Keyboard.release(BIND_2);
  }

  if(digitalRead(BT_3) == LOW) {
    Keyboard.press(BIND_3);
    //delay(30);
  } else if (digitalRead(BT_3) == HIGH)
  {
    Keyboard.release(BIND_3);
  }

  if(digitalRead(BT_4) == LOW) {
    Keyboard.press(BIND_4);
    //delay(30);
  } else if (digitalRead(BT_4) == HIGH)
  {
    Keyboard.release(BIND_4);
  }
  Keyboard.end();   
}
