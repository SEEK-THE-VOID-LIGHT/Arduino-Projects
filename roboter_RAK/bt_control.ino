//BT_Control test
#define l_r 12
#define l_f 11
#define r_f 10
#define r_r 9
#define led1 5
char btVal;

void setup(){
  pinMode(r_f, OUTPUT);
  pinMode(r_r, OUTPUT);
  pinMode(l_f, OUTPUT);
  pinMode(l_r, OUTPUT);
  pinMode(led1, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  if(Serial.available()){
    btVal = Serial.read();
  }
  Serial.println(btVal);
  /*if(btVal == '3'){
    analogWrite(r_f, 150);
    analogWrite(l_f, 150);
    analogWrite(led1, 150);
  }
  if(btVal == '4'){
    analogWrite(r_r, 150);
    analogWrite(l_r, 150);
    analogWrite(led1, 150);
  }
  if(btVal == '1'){
    analogWrite(r_f, 150);
    analogWrite(led1, 150);
  }
  if(btVal == '2'){
    analogWrite(l_f, 150);
    analogWrite(led1, 150);
  }
  if(btVal == '0'){
    digitalWrite(r_f, 150);
    digitalWrite(l_f, 150);
    digitalWrite(r_r, 150);
    digitalWrite(l_r, 150);
    digitalWrite(led1, 150);
  }*/
  if(btVal == '3'){
    digitalWrite(r_f, HIGH);
    digitalWrite(l_f, HIGH);
    digitalWrite(led1, HIGH);
  }
  if(btVal == '4'){
    digitalWrite(r_r, HIGH);
    digitalWrite(l_r, HIGH);
    digitalWrite(led1, HIGH);
  }
  if(btVal == '1'){
    digitalWrite(r_f, HIGH);
    digitalWrite(led1, HIGH);
  }
  if(btVal == '2'){
    digitalWrite(l_f, HIGH);
    digitalWrite(led1, HIGH);
  }
  if(btVal == '0'){
    digitalWrite(r_f, LOW);
    digitalWrite(l_f, LOW);
    digitalWrite(r_r, LOW);
    digitalWrite(l_r, LOW);
    digitalWrite(led1, LOW);
  }
}