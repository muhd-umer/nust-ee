#include <avr/io.h>
#include <EEPROM.h>

char SevenSegment(char number);

unsigned char output = 0;
int a;
int value;

void setup()
{
    DDRA = 0xFF; // Set port A as out
    DDRL = 0xFF; // Set port L as out
    DDRF = 0x00; // Set port F as in
    
    pinMode(4, OUTPUT);
    PORTA = 0x00;
    PORTL = 0x00;

    DDRC = 0xFF; // Set port C as out
    DDRB = 0x00; // Set port B as out

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
  delay(800);
  digitalWrite(4, LOW);
  delay(800);
  digitalWrite(4, HIGH);

  a = PINB;
  value = EEPROM.read(a);
  PORTC = value;
  
  output = PINF;
  PORTA = SevenSegment(output / 10);
  PORTL = SevenSegment(output % 10);
}

// ------- BCD - 7 Segment Decoder -------
char SevenSegment(char number)
{
    if (number == 0)        return 0x01;
    else if (number == 1)     return 0x4F;
    else if (number == 2)     return 0x12;
    else if (number == 3)     return 0x06;
    else if (number == 4)     return 0x4C;
    else if (number == 5)     return 0x24;
    else if (number == 6)     return 0x20;
    else if (number == 7)     return 0x0F;
    else if (number == 8)     return 0x00;
    else if (number == 9)     return 0x0C;
    else              return 0xFF;
}
