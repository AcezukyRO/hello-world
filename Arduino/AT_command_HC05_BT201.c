/*at
Name: HC05_change_name_n_pass.ino
Created: 9/8/2018 4:07:51 PM
Author: homan-mobile\Homan Huang
*/
// Source: https://forum.arduino.cc/t/hc-05-is-in-at-mode-but-not-responding-to-any-command/275186/14
// Remove TX, RX wires from arduino first before uploading this code
// After upload code, open Serial Monitor, set "Both LN & CR" and "9600 baud". For BT-201, test with these commands: "AT+CE", "AT+CF", if return "OK" mean it's working
// AT commands for BT-201: https://nettips.ru/book/BT201%20Module%20_KT1025A_B_User%20Manual%20_V2.3.pdf
// AT commands for HC-05: http://www.linotux.ch/arduino/HC-0305_serial_module_AT_commamd_set_201104_revised.pdf
// HC-05 another youtube explain: https://www.youtube.com/watch?v=A0uFtI_hX6Q
// Define User Types below here or use a .h file
//
#include <SoftwareSerial.h>

//set ports
// state pin
#define rx 10 // => HC-05/BT-201: tx
#define tx 11 // => HC-05/BT-201: rx
// HC-05/BT-201 GND pin: GND
// HC-05/BT-201 VCC pin: 5V pin
#define cmd 8 //EN pin (for HC-05 only)

SoftwareSerial BTserial(rx, tx); // RX | TX of Arduino

char reading = ' ';

// BTconnected will = false when not connected and true when connected
boolean BTconnected = false;

// The setup() function runs once each time the micro-controller starts
void setup()
{
// start serial communication with the serial monitor on the host computer

// set input through EN pin
pinMode(cmd, OUTPUT);
digitalWrite(cmd, HIGH);

//Serial turns on in 1 second
delay(1000);

// wait until the HC-05 has made a connection
while (!BTconnected)
{
if (digitalRead(cmd) == HIGH) { BTconnected = true; };
}

Serial.begin(9600);
Serial.println("HC-05 is now connected");
Serial.println("");

// Start serial communication with the bluetooth module
// HC-05 default serial speed for communication mode is 9600 but can be different
Serial.println("Enter AT commands:");

BTserial.begin(115200); // HC-05 default speed in AT command mode: 38400 , for BT-201, set this to 115200
}

void loop()
{
// Keep reading from HC-05 and send to Arduino Serial Monitor
if (BTserial.available())
{
reading = BTserial.read();
Serial.write(reading);
}

// Keep reading from Arduino Serial Monitor and send to HC-05
if (Serial.available())
{
reading = Serial.read();
BTserial.write(reading);
}
}
