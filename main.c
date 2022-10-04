#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "utils/std_types.h"
#include "MCAL/TIMER/timer.h"
#include "EHAL/7-Segment/seven_segment.h"
#include "APP/stopwatch.h"


int main()
{
	sevenSegmentInit();
	TIMER_Init();
	sei();

	while(1){

		stopWatchStart();

		/*for(int i=0 ; i<=9 ; i++){
			sevenSegmenDisplay(i);
			_delay_ms(150);
		}
*/
		/*sevenSegmentMilliSecondsDisplay();
		sevenSegmentSecondsDisplay();

*/		/*sevenSegmentMinutsDisplay();
		sevenSegmentHoursDisplay();*/
	}


}


