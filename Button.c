/*Work on:
 - Leonardo
 - Due
 - Pro Micro
*/

//My arduino: https://icdayroi.com/arduino-pro-micro

#include <Keyboard.h>                               // built-in library, no need to install

void setup() {
  // put your setup code here, to run once:
  pinMode(3,INPUT_PULLUP);                          // sets pin 3 to input and pull it high with internal resistor
  Serial.begin(9600);                               // begin serial comms for debugging
}

void loop() {
  // put your main code here, to run repeatedly:
  Keyboard.begin();                                 // begin keyboard
  if(digitalRead(3) == LOW) {                       // if button is pushed
    Keyboard.press('z');                            // simulate "z" on keyboard
    digitalWrite(4, HIGH);                          // light up the button (for LED Illuminated Push buttons)
    delay(30);                                      // The button is very sensitive, you press once and you release, it may count as 2 time press because of "holding"
                                                    // To prevent that, we need to set the delay to pass that "holding" time
                                                    
  } else {                                          // if button is not pushed or is released
    Keyboard.release('z');                          // stop simulate "z" on keyboard
    digitalWrite(4, LOW);                           // stop lighting up the button
  }
  Keyboard.end();                                   // stops keyboard
}
