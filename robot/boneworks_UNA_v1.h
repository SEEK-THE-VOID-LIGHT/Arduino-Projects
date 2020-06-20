//setup motor IO outputs
#define l_r 12
#define l_f 11
#define r_f 10
#define r_r 9
#define led1 5
#define led2 6
int allowed = 1;

void setup(){
  pinMode(r_f, OUTPUT);
  pinMode(r_r, OUTPUT);
  pinMode(l_f, OUTPUT);
  pinMode(l_r, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void test(int mode){
  if(mode==1){
    for(int i = 0; i<256 ; i++){
      analogWrite(r_f, i);
      analogWrite(l_f, i);
      delay(10);
    }
  }
  else if(mode==2){
    for(int i = 0; i<256; i++){
      analogWrite(led1, i);
      analogWrite(led2, i);
      delay(10);
    }
    for(int j = 255; j>0; j--){
      analogWrite(led1, j);
      analogWrite(led2, j);
      delay(10);
    }
  }
}

//definition moves <==>
void nach_vorne(){
    digitalWrite(r_f, HIGH);
    digitalWrite(l_f, HIGH);
    delay(500);
    digitalWrite(r_f, LOW);
    digitalWrite(l_f, LOW);
    delay(1000);
}

void nach_hinten(){
    digitalWrite(r_r, HIGH);
    digitalWrite(l_r, HIGH);
    delay(500);
    digitalWrite(r_r, LOW);
    digitalWrite(l_r, LOW);
    delay(1000);
}

void drehe_links(){
    digitalWrite(r_f, HIGH);
    digitalWrite(l_r, HIGH);
    delay(110);
    digitalWrite(r_f, LOW);
    digitalWrite(l_r, LOW);
    delay(1000);
}

void drehe_rechts(){
	digitalWrite(r_r, HIGH);
	digitalWrite(l_f, HIGH);
	delay(110);
	digitalWrite(r_r, LOW);
	digitalWrite(l_f, LOW);
	delay(1000);
}