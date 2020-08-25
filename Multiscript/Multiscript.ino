#include <Arduino.h>
#include <U8g2lib.h>
#define l_r 12
#define l_f 11
#define r_f 10
#define r_r 9
#define ledr 4
#define ledg 5
#define ledb 6
char btVal;
int selected = 3;
int maxPrograms = 3;
#ifdef U8X8_HAVE_HW_SPI
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void setup(void) {
  u8g2.begin();
  pinMode(ledr, OUTPUT);
  pinMode(ledg, OUTPUT);
  pinMode(ledb, OUTPUT);
  pinMode(r_f, OUTPUT);
  pinMode(r_r, OUTPUT);
  pinMode(l_f, OUTPUT);
  pinMode(l_r, OUTPUT);
  Serial.begin(9600);
  setColor(0);
  startScreen();
}

//MAIN LOOP
void loop(void) {
  
  setColor(4);

  if (Serial.available()) {
    btVal = Serial.read();
  }
  Serial.println(btVal);
  if (btVal == '3' && selected <= maxPrograms) {
    selected++;
    beep();
  }
  if (btVal == '4' && selected >= 1) {
    selected--;
    beep();
  }

  if (selected == 3) {
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_8x13_t_symbols);
    u8g2.drawStr(0, 10, ">> BT CONTROL");
    u8g2.drawStr(0, 25, "-- PLAY PROGRAM");
    u8g2.drawStr(0, 40, "-- SYSTEM CHECK");
    u8g2.sendBuffer();
  }
  else if (selected == 2) {
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_8x13_t_symbols);
    u8g2.drawStr(0, 10, "-- BT CONTROL");
    u8g2.drawStr(0, 25, ">> PLAY PROGRAM");
    u8g2.drawStr(0, 40, "-- SYSTEM CHECK");
    u8g2.sendBuffer();
  }
  else if (selected == 1) {
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_8x13_t_symbols);
    u8g2.drawStr(0, 10, "-- BT CONTROL");
    u8g2.drawStr(0, 25, "-- PLAY PROGRAM");
    u8g2.drawStr(0, 40, ">> SYSTEM CHECK");
    u8g2.sendBuffer();
  }
  if (btVal == '7') {
    switch (selected) {
      case 3: setColor(2); u8g2.clearBuffer(); u8g2.setFont(u8g2_font_8x13_t_symbols); u8g2.drawStr(0, 10, "BT CONTROL..."); u8g2.sendBuffer(); bt_control(); break;
      case 2: setColor(3); u8g2.clearBuffer(); u8g2.setFont(u8g2_font_8x13_t_symbols); u8g2.drawStr(0, 10, "RUNNING...."); u8g2.sendBuffer(); execute(); break;
      case 1: setColor(1); u8g2.clearBuffer(); u8g2.setFont(u8g2_font_8x13_t_symbols); u8g2.drawStr(0, 10, "TESTING..."); u8g2.sendBuffer(); nach_vorne(); nach_hinten(); drehe_rechts(); drehe_links(); u8g2.clearBuffer(); u8g2.setFont(u8g2_font_8x13_t_symbols); u8g2.drawStr(0, 20, "FULL SYSTEM"); u8g2.drawStr(0, 40, "CHECK COMPLETE"); u8g2.sendBuffer(); delay(2000); break;
    }
  }
}

/*u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.drawStr(0,10,"-- BT CONTROL");
  u8g2.drawStr(0,25,">> PLAY PROGRAM");
  u8g2.drawStr(0,40,"-- COMING SOON");
  u8g2.sendBuffer();*/


void startScreen() {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_8x13_t_symbols);
  u8g2.drawStr(0,35,"FELIX BOT");
  u8g2.drawStr(0,10,"-----------------------");
  u8g2.drawStr(0,60,"-----------------------");
  u8g2.sendBuffer();
  tone(6,500);
  delay(3000);
  noTone(6);
}

void bt_control() {
  while (true) {
    if (Serial.available()) {
      btVal = Serial.read();
    }
    Serial.println(btVal);
    if (btVal == '3') {
      digitalWrite(r_f, HIGH);
      digitalWrite(l_f, HIGH);
    }
    if (btVal == '4') {
      digitalWrite(r_r, HIGH);
      digitalWrite(l_r, HIGH);
    }
    if (btVal == '1') {
      digitalWrite(r_f, HIGH);
    }
    if (btVal == '2') {
      digitalWrite(l_f, HIGH);
    }
    if (btVal == '0') {
      digitalWrite(r_f, LOW);
      digitalWrite(l_f, LOW);
      digitalWrite(r_r, LOW);
      digitalWrite(l_r, LOW);
    }
    if(btVal == '7'){break; selected = 2;}
  }
}

//DECLARATION OF PREMADE MOVESETS
void nach_vorne() {
  digitalWrite(r_f, HIGH);
  digitalWrite(l_f, HIGH);
  delay(500);
  digitalWrite(r_f, LOW);
  digitalWrite(l_f, LOW);
  delay(1000);
}

void nach_hinten() {
  digitalWrite(r_r, HIGH);
  digitalWrite(l_r, HIGH);
  delay(500);
  digitalWrite(r_r, LOW);
  digitalWrite(l_r, LOW);
  delay(1000);
}

void drehe_links() {
  digitalWrite(r_f, HIGH);
  digitalWrite(l_r, HIGH);
  delay(110);
  digitalWrite(r_f, LOW);
  digitalWrite(l_r, LOW);
  delay(1000);
}

void drehe_rechts() {
  digitalWrite(r_r, HIGH);
  digitalWrite(l_f, HIGH);
  delay(110);
  digitalWrite(r_r, LOW);
  digitalWrite(l_f, LOW);
  delay(1000);
}

void setColor(int c){
  switch(c){
    case 0: digitalWrite(ledr,LOW); digitalWrite(ledg,LOW); digitalWrite(ledb,LOW);
    case 1: digitalWrite(ledr,HIGH); digitalWrite(ledg,LOW); digitalWrite(ledb,LOW);
    case 2: digitalWrite(ledr,LOW); digitalWrite(ledg,HIGH); digitalWrite(ledb,LOW);
    case 3: digitalWrite(ledr,LOW); digitalWrite(ledg,LOW); digitalWrite(ledb,HIGH);
    case 4: digitalWrite(ledr,HIGH); digitalWrite(ledg,HIGH); digitalWrite(ledb,HIGH);
  }
}

void beep(){
  tone(6, 300);
  delay(300);
  noTone(6);
}

void execute() {
  drehe_rechts();
  nach_vorne();
  drehe_links();
  nach_hinten();
  u8g2.clearBuffer(); u8g2.setFont(u8g2_font_8x13_t_symbols); u8g2.drawStr(0, 10, "DONE."); u8g2.sendBuffer(); delay(1000);
}
