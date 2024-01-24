#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/sfr_defs.h>

void objectAvoid();
void lineTracker();

int main()
{
  DDRA = 0b11111100;
  DDRB = 0xFF;
  DDRC = 0x00;
  DDRD = 0xFF;

  while (1) {
    if ((PINA & (0b00000001))) //  && !(PINA & (0b00000010))
    {
      objectAvoid();
    }
    if ((PINA & (0b00000010))) // && !(PINA & (0b00000001))
    {
      lineTracker();
    }
  }
}

void objectAvoid(){

  PORTD = 0b00000000;
  _delay_us(2);

  PORTD = 0b00000001;
  _delay_us(10);
  PORTD = 0b00000000;
  
}

void lineTracker(){
  //line detected by both
  if(!(PINC & (0b00000001)) && !(PINC & (0b00000010))){
    PORTD = 0b00000000;
    PORTB = 0b00000001;
  }
  //line detected by left sensor
  else if(!(PINC & (0b00000001)) && (PINC & (0b00000010))){
    //turn left
    PORTD = 0b00000010;
  }
  //line detected by right sensor
  else if((PINC & (0b00000001)) && !(PINC & (0b00000010))){
    //turn right
    PORTD = 0b00000100;
  }
  //line detected by none
  else if((PINC & (0b00000001)) && (PINC & (0b00000010))){
    PORTD = 0b00000110;
  }
}
