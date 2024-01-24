#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/sfr_defs.h>

void objectAvoid();
void lineTracker();

int main()
{
  DDRA = 0b11111100;
  DDRC = 0x00;
  DDRD = 0xFF;

  while (1) {
    if (bit_is_set(PINA, 0))
    {
      objectAvoid();
    }
    if (bit_is_set(PINA, 1))
    {
      lineTracker();
    }
  }
}

void objectAvoid(){

  PORTD = PORTD & !(1<<0);
  _delay_us(2);

  PORTD = PORTD | (1<<0);
  _delay_us(10);
  PORTD = PORTD & !(1<<0);
  
}

void lineTracker(){
  //line detected by both
  if(bit_is_clear(PINC, 0) && bit_is_clear(PINC, 1)){
    //Forward
    PORTD = 0b00000000;
  }
  //line detected by left sensor
  else if(bit_is_clear(PINC, 0) && !bit_is_clear(PINC, 1)){
    //turn left
    PORTD = 0b00000010;
  }
  //line detected by right sensor
  else if(!bit_is_clear(PINC, 0) && bit_is_clear(PINC, 1)){
    //turn right
    PORTD = 0b00000100;
  }
  //line detected by none
  else if(!bit_is_clear(PINC, 0) && !bit_is_clear(PINC, 1)){
    //stop
    PORTD = 0b00000110;
  }
}
