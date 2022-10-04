#include <avr/io.h>
#include <avr/delay.h>

#define DELAY  250
typedef enum
{
	ZERO=0x3F,
	ONE=0x06,
	TWO=0x5B,
	THREE=0x4F,
	FOUR=0x66,
	FIVE=0x6B,
	SIX=0x7B,
	SEVEN=0x07,
	EIGHT=0x7F,
	NINE=0x6F
}EN_SevenSegmentNum_t;

int main()
{

	DDRA =0xFF;
	PORTA =0xF0;
	DDRC =0xFF;
	PORTC|=~(1<<8);


	while(1){

	/*	PORTC=ZERO;
		_delay_ms(DELAY);

		PORTC=ONE;
		_delay_ms(DELAY);

		PORTC=TWO;
		_delay_ms(DELAY);

		PORTC=THREE;
		_delay_ms(DELAY);

		PORTC=FOUR;
		_delay_ms(DELAY);
*/
		PORTC=FIVE;
		_delay_ms(DELAY);

		PORTC=SIX;
		_delay_ms(DELAY);

		PORTC=SEVEN;
		_delay_ms(DELAY);

		PORTC=EIGHT;
		_delay_ms(DELAY);

		PORTC=NINE;
		_delay_ms(DELAY);
	}

}


