// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  Serial.begin(9600);
  
  //For the b 1 - 5 vlaues
  pinMode(14, INPUT);
  pinMode(15, INPUT);
  pinMode(16, INPUT);
  pinMode(17, INPUT);
  pinMode(18, INPUT);

  //For the l 1 - 8 vlaues
  pinMode(22, INPUT);
  pinMode(23, INPUT);
  pinMode(24, INPUT);
  pinMode(25, INPUT);
  pinMode(26, INPUT);
  pinMode(27, INPUT);
  pinMode(28, INPUT);
  pinMode(29, INPUT);
  
  //For the p 1 - 8 vlaues
  pinMode(31, INPUT);
  pinMode(32, INPUT);
  pinMode(33, INPUT);
  pinMode(34, INPUT);
  pinMode(35, INPUT);
  pinMode(36, INPUT);
  pinMode(37, INPUT);
  pinMode(38, INPUT);

  //For guess mode
  pinMode(30, INPUT);
  pinMode(39, INPUT);
  pinMode(40, OUTPUT);
  pinMode(41, INPUT);

  lcd.setCursor(4,0);
  lcd.print("HANGMAN");
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
int l6;
int l7;
int l8;

int p1;
int p2;
int p3;
int p4;
int p5;
int p6;
int p7;
int p8;

int r1;
int r2;
int r3;

char word1 = '_';
char word2 = '_';
char word3 = '_';
char word4 = '_';
char word5 = '_';
char word6 = '_';
char word7 = '_';
char word8 = '_';


void loop() {
  //Reading Bs
  b1 = digitalRead(14);
  b2 = digitalRead(15);
  b3 = digitalRead(16);
  b4 = digitalRead(17);
  b5 = digitalRead(18);

  //Reading Ls
  l1 = digitalRead(29);
  l2 = digitalRead(28);
  l3 = digitalRead(27);
  l4 = digitalRead(26);
  l5 = digitalRead(25);
  l6 = digitalRead(24);
  l7 = digitalRead(23);
  l8 = digitalRead(22);

  //Reading Ps
  p1 = digitalRead(31);
  p2 = digitalRead(32);
  p3 = digitalRead(33);
  p4 = digitalRead(34);
  p5 = digitalRead(35);
  p6 = digitalRead(36);
  p7 = digitalRead(37);
  p8 = digitalRead(38);

  //Reading modes
  r1 = digitalRead(30);
  r2 = digitalRead(39);
  r3 = digitalRead(41);

  if (r1 == 1) {
    counter(b1, b2, b3, b4, b5);
    pos1(b1, b2, b3, b4, b5, l1, p1);
    pos2(b1, b2, b3, b4, b5, l2, p2);
    pos3(b1, b2, b3, b4, b5, l3, p3);
    pos4(b1, b2, b3, b4, b5, l4, p4);
    pos5(b1, b2, b3, b4, b5, l5, p5);
    pos6(b1, b2, b3, b4, b5, l6, p6);
    pos7(b1, b2, b3, b4, b5, l7, p7);
    pos8(b1, b2, b3, b4, b5, l8, p8);
  }
  
  if (r1 == 0){
      lcd.setCursor(0,1);
      lcd.print("STORAGE!");
      lcd.setCursor(0,1);
  }
  if ((r3 == 0) && ((word1 == '_') || (word2 == '_') || (word3 == '_') || (word4 == '_') || (word5 == '_') || (word6 == '_') || (word7 == '_') || (word8 == '_'))){
      while (1){
        lcd.clear();
        lcd.setCursor(0,1);
        lcd.print("TRY AGAIN!");
        delay(1000);
      }
  }
  if ((isAlpha(word1)) && (isAlpha(word2)) && (isAlpha(word3)) && (isAlpha(word4)) && (isAlpha(word5)) && (isAlpha(word6)) && (isAlpha(word7)) && (isAlpha(word8))){
      while (1){
        lcd.clear();
        lcd.setCursor(0,1);
        lcd.print("YOU WON!");
        delay(1000);
      }
  }
}

void counter(int b1, int b2, int b3, int b4, int b5){
    if (((b1 == 1) || (b2 == 1) || (b3 == 1) || (b4 == 1) || (b5 == 1))) {
          digitalWrite(40, HIGH);
          delay(50);
    }
    if ((b1 == 0) && (b2 == 0) && (b3 == 0) && (b4 == 0) && (b5 == 0)) {
          digitalWrite(40, LOW);
          delay(50);
    }
}

void pos1(int b1, int b2, int b3, int b4, int b5, int l1, int p1)
{
    if ((b1 == 0) && (b2 == 0) && (b3 == 0) && (b4 == 0) && (b5 == 0)) {
        lcd.setCursor(0, 1);
        lcd.print(word1);
    }
    if ((l1 == 0 && p1 == 1) && ((b1 == 1) || (b2 == 1) || (b3 == 1) || (b4 == 1) || (b5 == 1))) {
        lcd.setCursor(0, 1);
        finalVar = (b1 << 4) | (b2 << 3) | (b3 << 2) | (b4 << 1) | (b5);
        char wordy = 64 + finalVar;
        lcd.print(wordy);
        word1 = wordy;
    }
    else {
        lcd.setCursor(0, 1);
        lcd.print(word1);
    }
}

  
void pos2(int b1, int b2, int b3, int b4, int b5, int l2, int p2)
{
    if ((b1 == 0) && (b2 == 0) && (b3 == 0) && (b4 == 0) && (b5 == 0)) {
        lcd.setCursor(1, 1);
        lcd.print(word2);
    }
    if ((l2 == 0 && p2 == 1) && ((b1 == 1) || (b2 == 1) || (b3 == 1) || (b4 == 1) || (b5 == 1))) {
        lcd.setCursor(1, 1);
        finalVar = (b1 << 4) | (b2 << 3) | (b3 << 2) | (b4 << 1) | (b5);
        char wordy = 64 + finalVar;
        lcd.print(wordy);
        word2 = wordy;
    }

    else {
        lcd.setCursor(1, 1);
        lcd.print(word2);
    }
}

void pos3(int b1, int b2, int b3, int b4, int b5, int l3, int p3)
{
    if ((b1 == 0) && (b2 == 0) && (b3 == 0) && (b4 == 0) && (b5 == 0)) {
        lcd.setCursor(2, 1);
        lcd.print(word3);
    }
    if ((l3 == 0 && p3 == 1) && ((b1 == 1) || (b2 == 1) || (b3 == 1) || (b4 == 1) || (b5 == 1))) {
        lcd.setCursor(2, 1);
        finalVar = (b1 << 4) | (b2 << 3) | (b3 << 2) | (b4 << 1) | (b5);
        char wordy = 64 + finalVar;
        lcd.print(wordy);
        word3 = wordy;
    }

    else {
        lcd.setCursor(2, 1);
        lcd.print(word3);
    }
}

void pos4(int b1, int b2, int b3, int b4, int b5, int l4, int p4)
{
    if ((b1 == 0) && (b2 == 0) && (b3 == 0) && (b4 == 0) && (b5 == 0)) {
        lcd.setCursor(3, 1);
        lcd.print(word4);
    }
    if ((l4 == 0 && p4 == 1) && ((b1 == 1) || (b2 == 1) || (b3 == 1) || (b4 == 1) || (b5 == 1))) {
        lcd.setCursor(3, 1);
        finalVar = (b1 << 4) | (b2 << 3) | (b3 << 2) | (b4 << 1) | (b5);
        char wordy = 64 + finalVar;
        lcd.print(wordy);
        word4 = wordy;
    }

    else {
        lcd.setCursor(3, 1);
        lcd.print(word4);
    }
}

void pos5(int b1, int b2, int b3, int b4, int b5, int l5, int p5)
{
    if ((b1 == 0) && (b2 == 0) && (b3 == 0) && (b4 == 0) && (b5 == 0)) {
        lcd.setCursor(4, 1);
        lcd.print(word5);
    }
    if ((l5 == 0 && p5 == 1) && ((b1 == 1) || (b2 == 1) || (b3 == 1) || (b4 == 1) || (b5 == 1))) {
        lcd.setCursor(4, 1);
        finalVar = (b1 << 4) | (b2 << 3) | (b3 << 2) | (b4 << 1) | (b5);
        char wordy = 64 + finalVar;
        lcd.print(wordy);
        word5 = wordy;
    }

    else {
        lcd.setCursor(4, 1);
        lcd.print(word5);
    }
}

void pos6(int b1, int b2, int b3, int b4, int b5, int l6, int p6)
{
    if ((b1 == 0) && (b2 == 0) && (b3 == 0) && (b4 == 0) && (b5 == 0)) {
        lcd.setCursor(5, 1);
        lcd.print(word6);
    }
    if ((l6 == 0 && p6 == 1) && ((b1 == 1) || (b2 == 1) || (b3 == 1) || (b4 == 1) || (b5 == 1))) {
        lcd.setCursor(5, 1);
        finalVar = (b1 << 4) | (b2 << 3) | (b3 << 2) | (b4 << 1) | (b5);
        char wordy = 64 + finalVar;
        lcd.print(wordy);
        word6 = wordy;
    }

    else {
        lcd.setCursor(5, 1);
        lcd.print(word6);
    }
}

void pos7(int b1, int b2, int b3, int b4, int b5, int l7, int p7)
{
    if ((b1 == 0) && (b2 == 0) && (b3 == 0) && (b4 == 0) && (b5 == 0)) {
        lcd.setCursor(6, 1);
        lcd.print(word7);
    }
    if ((l7 == 0 && p7 == 1) && ((b1 == 1) || (b2 == 1) || (b3 == 1) || (b4 == 1) || (b5 == 1))) {
        lcd.setCursor(6, 1);
        finalVar = (b1 << 4) | (b2 << 3) | (b3 << 2) | (b4 << 1) | (b5);
        char wordy = 64 + finalVar;
        lcd.print(wordy);
        word7 = wordy;
    }

    else {
        lcd.setCursor(6, 1);
        lcd.print(word7);
    }
}

void pos8(int b1, int b2, int b3, int b4, int b5, int l8, int p8)
{
    if ((b1 == 0) && (b2 == 0) && (b3 == 0) && (b4 == 0) && (b5 == 0)) {
        lcd.setCursor(7, 1);
        lcd.print(word8);
    }
    if ((l8 == 0 && p8 == 1) && ((b1 == 1) || (b2 == 1) || (b3 == 1) || (b4 == 1) || (b5 == 1))) {
        lcd.setCursor(7, 1);
        finalVar = (b1 << 4) | (b2 << 3) | (b3 << 2) | (b4 << 1) | (b5);
        char wordy = 64 + finalVar;
        lcd.print(wordy);
        word8 = wordy;
    }

    else {
        lcd.setCursor(7, 1);
        lcd.print(word8);
    }
}
