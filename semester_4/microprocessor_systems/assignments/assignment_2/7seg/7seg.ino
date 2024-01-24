/*
 * AS1.cpp
 *
 * Created: 14/03/2022 8:13:34 pm
 */

#include <avr/io.h>
char SevenSegment(char number);
unsigned char counter = 0;
int pulse;

void setup()
{
    DDRA = 0xFF; // Set port A as out
    DDRC = 0xFF; // Set port B as out
    DDRF = 0x00; // Set port C as in
    
    pinMode(0, OUTPUT);
    PORTA = 0x00;
    PORTC = 0x00;
}

void loop()
{
  digitalWrite(0, LOW);
  delay(250);
  digitalWrite(0, HIGH);
  
  counter = PINF;
  PORTA = SevenSegment(counter / 10);
  PORTC = SevenSegment(counter % 10);
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
