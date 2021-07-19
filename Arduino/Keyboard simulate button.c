/*Work on:
 - Leonardo
 - Due
 - Pro Micro
*/

// Schematic: https://imgur.com/kZykQ5G
// My arduino: https://icdayroi.com/arduino-pro-micro

#include <Keyboard.h>                               // built-in library, no need to install

void setup() {
  // put your setup code here, to run once:
  pinMode(3,INPUT_PULLUP);                          // sets pin 3 to input and pull it high with internal resistor
  Serial.begin(9600);                               // begin serial comms for debugging
}

void loop() {
  // put your main code here, to run repeatedly:
  Keyboard.begin();                                 // begin keyboard
  if(digitalRead(3) == LOW) {                       // if button is pushed ; Because pin 3 has been set pull high with internal resistor, so we need to check reversely, LOW instead HIGH
    Keyboard.press('z');                            // simulate "z" on keyboard
    digitalWrite(4, HIGH);                          // light up the button (for LED Illuminated Push buttons) 
                                                    // Because - pin is connected to GND and + pin is connected to pin 4 in arduino, if pin 4 is HIGH, it will create a complete circuit and make LED shine
    delay(30);                                      // The button is very sensitive, you press once and you release, it may count as 2 time press because of "holding"
                                                    // To prevent that, we need to set the delay to pass that "holding" time
                                                    
  } else {                                          // if button is not pushed or is released
    Keyboard.release('z');                          // stop simulate "z" on keyboard
    digitalWrite(4, LOW);                           // stop lighting up the button
  }
  Keyboard.end();                                   // stops keyboard
}
