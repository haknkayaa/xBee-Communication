#include <Arduino.h>

//Constants
//#define LED_BUILTIN 13; //Led to Arduino pin 3 (PWM)

//Variables
String data;

void setup() {

    //Start the serial communication
    Serial1.begin(9600); //Baud rate must be the same as is on xBee module
    Serial.begin(9600);

    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {

    while (Serial1.available() > 0) {
        //Read the incoming byte
         data = Serial1.readString();
         data.trim();

         Serial.println(data);

        if(data == "LED AC") {
            digitalWrite(LED_BUILTIN, HIGH);
            Serial.println("LED Açildi");
        } else if (data == "LED KAPA") {
            digitalWrite(LED_BUILTIN, LOW);
            Serial.println("LED Kapandi");
        }
    }
}





