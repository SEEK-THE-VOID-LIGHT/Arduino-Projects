#include <Servo.h>
Servo serx;
Servo sery;
String data;
bool calibrated = false;

void setup(){
    serx.attach(7);
    sery.attach(8);
    Serial.begin(9600);
    //Serial.setTimeout(2);
}

void loop(){
    if(calibrated != true){
        serx.write(90);
        sery.write(90);
        calibrated = true;
    }
}

void serialEvent(){
    data = Serial.readString();
    data.remove(0,1);
    data.remove(data.end());
    serx.write(translateX(data));
    sery.write(translateY(data));
}

int translateX(String datainput){
    datainput.remove(datainput.indexOf("Y"));
    datainput.remove(datainput.indexOf("X"),1);
    return datainput.toInt();
}

int translateY(String datainput){
    datainput.remove(0,datainput.indexOf("Y") + 1);
    return datainput.toInt();
}