#include "SevSeg.h"
SevSeg sevseg;
#define buzzer 2
#define taster 4
#define led 3
boolean allowed = false;
int tasterstatus = 0;

void setup(){
    byte numDigits = 1;
    byte digitPins[] = {};
    byte segmentPins[] = {7,8,11,10,9,6,5,12};
    bool resistorsOnSegments = true;
    pinMode(taster, INPUT);
    byte hardwareConfig = COMMON_CATHODE;
    pinMode(led, OUTPUT); 
    sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
    sevseg.setBrightness(90);


}

void loop(){
    digitalWrite(led, LOW);
    sevseg.setBrightness(90);
    sevseg.setNumber(8,0);
    sevseg.refreshDisplay();

    tasterstatus = digitalRead(taster);
    if(tasterstatus == HIGH){allowed = true;}

    if(allowed == true){
    for(int i=10; i>-1; i--){
        sevseg.setNumber(i);
        sevseg.refreshDisplay();
        tone(buzzer, 500);
        delay(200);
        noTone(buzzer);
        delay(800);
        /*if(i==0){
            allowed = false;
            tone(buzzer, 1000);
            sevseg.setNumber(8,0);
            sevseg.refreshDisplay();
        }*/
        }
        while(true){
        allowed = false;
        tone(buzzer, 1000);
        sevseg.setNumber(0);
        sevseg.refreshDisplay();
        digitalWrite(led, HIGH);
        }
    }
}
