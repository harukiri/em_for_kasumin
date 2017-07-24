// 測距センサで読み取った値を音に変換
// 8音（C4~C5）出せるようにする

#include "pitches.h"

int rangePin = 0;
int buzzPin = 13;

void setup() {
  Serial.begin(9600);
  pinMode(buzzPin, OUTPUT);
}

void loop() {
  int val;
  int cm;
  
  val = IDSread(rangePin);
  
  // シリアルモニタに読み取った値とだいたいの距離を表示する
  Serial.print(val);
  Serial.print(" ");
  cm = AnaToCm(val);
  Serial.print(cm);
  Serial.println("cm");
  
  // 距離に応じて音程を変える
  if(cm == 10) {
    tone(buzzPin, NOTE_C4);
  } else if(cm == 15) {
    tone(buzzPin, NOTE_D4);
  } else if(cm == 20) {
    tone(buzzPin, NOTE_E4);
  } else if(cm == 25) {
    tone(buzzPin, NOTE_F4);
  } else if(cm == 30) {
    tone(buzzPin, NOTE_G4);
  } else if(cm == 35) {
    tone(buzzPin, NOTE_A4);
  } else if(cm == 40) {
    tone(buzzPin, NOTE_B4);
  } else if(cm == 45) {
    tone(buzzPin, NOTE_C5);
  } else {
//    digitalWrite(buzzPin, LOW);
    noTone(buzzPin);
  }
  
  delay(200);
}

// 読み取った値の平均値を返す
int IDSread(int PinNo) {
  long ans;
  int i;
  
  ans = 0;
  for(i=0;i<100;i++) {
    ans = ans + analogRead(PinNo);
  }
  return ans/100;
}

// 読み取った値をだいたいの距離(cm)に変換する
int AnaToCm(int analogValue) {
  if(analogValue < 120 || analogValue > 520) return(0); // 65cmくらいより離れてる
  if(analogValue >= 390) return(10); // c4
  if(analogValue >= 290) return(15); // d4
  if(analogValue >= 235) return(20); // e4
  if(analogValue >= 200) return(25); // f4
  if(analogValue >= 170) return(30); // g4
  if(analogValue >= 150) return(35); // a4
  if(analogValue >= 135) return(40); // b4
  if(analogValue >= 115) return(45); // c5
  return(-1);
}
