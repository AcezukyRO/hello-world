/* Source: 
https://www.element14.com/community/community/arduino/blog/2017/07/16/bluetooth-data-file-image-transfer-and-control-using-arduino
https://create.arduino.cc/projecthub/electropeak/sd-card-module-with-arduino-how-to-read-write-data-37f390
https://www.arduino.cc/en/Tutorial/LibraryExamples/DumpFile

I write this for a clearer instruction on how to use the tera term to transfer file. Using the source is actually enough.
All the codes were taken from a comment in the first source.

Hardware prepare: 
- Arduino UNO R3 SMD (any UNO works): https://icdayroi.com/arduino-uno-r3-smd 
- Module Micro SD Card: https://icdayroi.com/micro-sd-card-module-tf-spi
Wiring: https://hackster.imgix.net/uploads/attachments/930853/ds3231-sd-card-module-circuit_1rirM4OoVj.jpg?auto=compress%2Cformat&w=680&h=510&fit=max

1. Install Tera Term: https://osdn.net/projects/ttssh2/releases/
2. Make new arduino sketch and copy these code to your sketch
3. Can only send one file per code. Depend on type of file, rename the file extension at createStr()
4. Upload the code to Arduino
5. Open TeraTerm (run ttermpro.exe), Choose Serial COM
6. Be quick. Going to File -> Send File.... Choose the file with the extension same with the code, REMEMBER to enable Binary option (checkbox below the select file)
7. Send file. It will take some time to transfer file due to low baudrate. 
*/

#include <SoftwareSerial.h>
SoftwareSerial sigmaSS(8,9); // Rx,Tx
#include <SPI.h>
#include <SD.h>

File myFile;
unsigned long last = 0;
long count = 0;
bool read = 0;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  sigmaSS.begin(9600);
  Serial.print("Initializing SD card...");
  if (!SD.begin(10)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
}

void loop() {
  if(Serial.available()){
    createStr();
  }
}

void createStr(){
  if (!read) {
    myFile = SD.open("rock.zip", O_CREAT | O_WRITE);  
    while (millis() - last < 1000 ||  count== 0){    // Delay time, try to change if doesn't work
      while (Serial.available() > 0){
        myFile.write(Serial.read());
        last = millis();
        count++;
     }
    }
    myFile.close();
    read = 1;
    Serial.print ("File written to SD card");
  }
}
