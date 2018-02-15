#include <SoftwareSerial.h>
/*
 * RX is digital pin 10 (connect to TX of other device)
 * TX is digital pin 11 (connect to RX of other device)
 * 
*/
#define RX 10
#define TX 11

SoftwareSerial mySerial(10, 11);

int incomingByte = 0;  // incoming data
int  LED = 5;      // LED pin

void setup() {
  Serial.begin(38400); //the serial communication through USB
  mySerial.begin(38400); // initialization
  pinMode(LED, OUTPUT);
  Serial.println("Press 1 to LED ON or 0 to LED OFF...");
}

void loop() {
//    digitalWrite(LED, HIGH);
//  delay(1000);
//  digitalWrite(LED, LOW);
//  delay(1000); 
//  Serial.println(mySerial.available());
//  delay(1000);
  if (mySerial.available() > 0) {  // if the data came
    incomingByte = mySerial.read(); // read byte
    Serial.print("incomingByte = ");
    Serial.println(incomingByte, DEC);
    if(incomingByte == 0) {
       digitalWrite(LED, LOW);  // if 1, switch LED Off
       Serial.println("LED OFF. Press 1 to LED ON!");  // print message
       delay(1000);
    }else if(incomingByte == 120) {
       digitalWrite(LED, HIGH); // if 0, switch LED on
       Serial.println("LED ON. Press 0 to LED OFF!");
       delay(1000);
    }
  } 
}


