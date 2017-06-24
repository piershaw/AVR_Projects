/*
 * LCDProject.c
 *
 * Created: 6/7/2017 7:11:11 PM
 * Author : piers
 */ 

 /************************************************************************/
 /*

  ATTINY85
 C:\WinAVR-20100110\bin\avrdude.exe
 -c usbtiny -p ATtiny85 -v -v -v -U flash:w:$(TargetDir)$(TargetName).hex:i
 $(BinDir)

 ATmega328P
 C:\WinAVR-20100110\bin\avrdude.exe
 -c usbtiny -p ATmega328P -v -v -v -U flash:w:$(TargetDir)$(TargetName).hex:i
 $(BinDir)
              
			  I took -v -v -v out and it still works                                                        */
 /************************************************************************/


#include <avr/io.h>
#include "LCD.h"
#include "ClockSpeed.h"

/************************************************************************/
/*main*/
/************************************************************************/
int main(void)
{
	LCD("pier shaw was here",1);
    while (1) 
    {
		loop();
    }
}



