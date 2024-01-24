#define F_CPU 1000000UL  // 1 MHz
#include <avr/io.h>
#include <EEPROM.h>
char SevenSegment(char number);

unsigned char output = 0;
int a;
int value;

void setup() {
  delay(300);
  DDRD = 0x00; // Set port D as in
  DDRC = 0xFF; // Set port C as out
  DDRK = 0xFF;  // K as OUT
  PORTC = 0x00;
  
  pinMode(4, OUTPUT); // Add or Subtract
  pinMode(29, OUTPUT); // Add or Subtract

  EEPROM.write(0, 0x08);
  EEPROM.write(1, 0x19);
  EEPROM.write(2, 0x20);
  EEPROM.write(3, 0x10);
  EEPROM.write(4, 0x70);
  EEPROM.write(5, 0x00);
  EEPROM.write(6, 0x14);
  EEPROM.write(7, 0x04);
  EEPROM.write(8, 0xB2);

}

void loop() 
{

  delay(350);
  digitalWrite(4, LOW);
  delay(350);
  digitalWrite(4, HIGH);

  digitalWrite(29, HIGH);
  a = PIND;
  value = EEPROM.read(a);
  PORTK = value;
  PORTC = value;
  
  if( a == 8 ){
    digitalWrite(29, LOW);
  }
}
