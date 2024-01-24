// include the library code:
#include <LiquidCrystal.h>


// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  Serial.begin(9600);
  //For the b-15 vlaues
  pinMode(10, INPUT);
  pinMode(9, INPUT);
  pinMode(8, INPUT);
  pinMode(7, INPUT);
  pinMode(6, INPUT);

  // for the l1-5 values
  pinMode(14, INPUT);
  pinMode(15, INPUT);
  pinMode(16, INPUT);
  pinMode(17, INPUT);
  pinMode(18, INPUT);
  // for the p1-5 values
  pinMode(20, INPUT);
  pinMode(21, INPUT);
  pinMode(22, INPUT);
  pinMode(23, INPUT);
  pinMode(24, INPUT);
  lcd.print("HANGMAN GAME");
  lcd.setCursor(0,1);  
}


int finalVar;
int b1;
int b2;
int b3;
int b4;
int b5;
int l1;
int l2;
int l3;
int l4;
int l5;
int p1;
int p2;
int p3;
int p4;
int p5;
char word1 = '_';
char word2 = '_';
char word3 = '_';
char word4 = '_';
char word5 = '_';


void loop() {
  //Reading Bs
  b1 = digitalRead(10);
  b2 = digitalRead(9);
  b3 = digitalRead(8);
  b4 = digitalRead(7);
  b5 = digitalRead(6);

  //Reading Ls
  l1 = digitalRead(18);
  l2 = digitalRead(17);
  l3 = digitalRead(16);
  l4 = digitalRead(15);
  l5 = digitalRead(14);

  //Reaeding Ps
  p1 = digitalRead(24);
  p2 = digitalRead(23);
  p3 = digitalRead(22);
  p4 = digitalRead(21);
  p5 = digitalRead(20);

  
     pos1(b1,b2,b3,b4,b5, l1, p1);
      pos2(b1,b2,b3,b4,b5, l2, p2);
      pos3(b1,b2,b3,b4,b5, l3, p3);
      pos4(b1,b2,b3,b4,b5, l4, p4);
      pos5(b1,b2,b3,b4,b5, l5, p5);

}

void pos1(int b1, int b2, int b3, int b4,int b5,int  l1,int p1){
if((b1 == 0) && (b2 == 0) && (b3 == 0) && (b4 == 0) && (b5 == 0)){
  lcd.setCursor(0,1);
  lcd.print(word1);
}
  if ((l1 == 0 && p1 == 1) && ((b1 == 1) || (b2 == 1) || (b3 == 1) || (b4 == 1) || (b5 == 1))){
    lcd.setCursor(0,1);
    finalVar = (b1 << 4)|(b2 << 3)|(b3 << 2)|(b4 << 1)|(b5);
    char wordy = 64 + finalVar;
    lcd.print(wordy);
    word1 = wordy;
 }

  else{
    lcd.setCursor(0,1);
    lcd.print(word1);
  }
 }

  
void pos2(int b1,int b2,int b3,int b4,int b5,int l2,int p2){
if((b1 == 0) && (b2 == 0) && (b3 == 0) && (b4 == 0) && (b5 == 0)){
  lcd.setCursor(1,1);
  lcd.print(word2);
}

  if ((l2 == 0 && p2 == 1) && ((b1 == 1) || (b2 == 1) || (b3 == 1) || (b4 == 1) || (b5 == 1))){
    lcd.setCursor(1,1);
    finalVar = (b1 << 4)|(b2 << 3)|(b3 << 2)|(b4 << 1)|(b5);
    char wordy = 64 + finalVar;
    lcd.print(wordy);
    word2 = wordy;
  }

  else{
    lcd.setCursor(1,1);
    lcd.print(word2);
  }
}

void pos3(int b1,int b2,int b3,int b4,int b5,int l3,int p3){
if((b1 == 0) && (b2 == 0) && (b3 == 0) && (b4 == 0) && (b5 == 0)){
  lcd.setCursor(2,1);
  lcd.print(word3);
}
  if ((l3 == 0 && p3 == 1) && ((b1 == 1) || (b2 == 1) || (b3 == 1) || (b4 == 1) || (b5 == 1))){
    lcd.setCursor(2,1);
    finalVar = (b1 << 4)|(b2 << 3)|(b3 << 2)|(b4 << 1)|(b5);
    char wordy = 64 + finalVar;
    lcd.print(wordy);
    word3 = wordy;
  }

  else{
    lcd.setCursor(2,1);
    lcd.print(word3);
  }
}

void pos4(int b1,int b2,int b3,int b4,int b5,int l4,int p4){
if((b1 == 0) && (b2 == 0) && (b3 == 0) && (b4 == 0) && (b5 == 0)){
  lcd.setCursor(3,1);
  lcd.print(word4);
}
  //puts A at position 4 if b1b2b3b4b5 = 00001 and l4 = 0 and p4 =1
  // otherwise print @ at pos4}
  if ((l4 == 0 && p4 == 1) && ((b1 == 1) || (b2 == 1) || (b3 == 1) || (b4 == 1) || (b5 == 1))){
    lcd.setCursor(3,1);
    finalVar = (b1 << 4)|(b2 << 3)|(b3 << 2)|(b4 << 1)|(b5);
    char wordy = 64 + finalVar;
    lcd.print(wordy);
    word4 = wordy;
  }

  else{
    lcd.setCursor(3,1);
    lcd.print(word4);
  }
}

void pos5(int b1,int b2,int b3,int b4,int b5,int l5,int p5){
  //puts A at position 5 if b1b2b3b4b5 = 00001 and l5 = 0 and p5 =1
  // otherwise print @ at pos5}
if((b1 == 0) && (b2 == 0) && (b3 == 0) && (b4 == 0) && (b5 == 0)){
  lcd.setCursor(4,1);
  lcd.print(word5);
}
  if ((l5 == 0 && p5 == 1)&& ((b1 == 1) || (b2 == 1) || (b3 == 1) || (b4 == 1) || (b5 == 1))){
    lcd.setCursor(4,1);
    finalVar = (b1 << 4)|(b2 << 3)|(b3 << 2)|(b4 << 1)|(b5);
    char wordy = 64 + finalVar;
    lcd.print(wordy);
    word5 = wordy;
  }
  else{
    lcd.setCursor(4,1);
    lcd.print(word5);
  }
  }
  
