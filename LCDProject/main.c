/*
 * LCDProject.c
 *
 * Created: 6/7/2017 7:11:11 PM
 * Author : piers
 *
 *
 *
 *
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

#ifndef F_CPU
#define F_CPU 8000000UL // I have this at 8Mhz
#endif

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h> // this is for printf

#define LCDMain               PORTD
#define DataDirMain           DDRD

#define LCDControl            PORTC
#define DataDirControl		  DDRC

#define LedGreen              PINC3
#define LCDEnable             PINC2
#define LCDReadWrite		  PINC1
#define LCDRegistorSelect     PINC0





//Commands
#define CLEARSCREEN		0x01
#define BUZZY			0x80
#define BITMODE8BIT		0x38

#define LCDOFF 0b00001100
#define LCDON 0b00001110
#define LCDONBlink 0b00001111

//Prototypes put in header file later
void enable(void);
void sendCommand(unsigned char);
void sendCharacter(unsigned char);
void checkStatus(void);
void sendString(char *stringOfChars);
void powerON();

/************************************************************************/
/*main*/
/************************************************************************/
int main(void)
{
	printf("Running!");
	// sets all DDRC data direction ports to output bit[1] 
	DataDirControl |= 1 << LCDEnable | 1 << LCDReadWrite | 1 << LCDRegistorSelect | 1 << LedGreen;
	_delay_ms(15);
    /* Replace with your application code */
	sendCommand(CLEARSCREEN);
	_delay_ms(2);
	sendCommand(BITMODE8BIT);
	_delay_ms(50);
	sendCommand(LCDONBlink);
	_delay_ms(50);
	sendString("piershaw");
	
    while (1) 
    {
		powerON();
    }
}
//reading input
void checkStatus(){	
	DataDirMain = 0; //set to input ? change to the right way later
	LCDControl |= 1 << LCDReadWrite;
	LCDControl &= ~(1 << LCDRegistorSelect);
	  while (LCDMain >= BUZZY)
	  {
		enable();
	  }
	DataDirMain = 0xFF; // set all I/O pins to OUTPUT 0b11111111
}

// debug
void powerON(){
	_delay_ms(100);
	PINC |= (1<<LedGreen);
}

//Enable
void enable(){
	// switch it on and off 
	//to receive a command
	LCDControl |= (1 << LCDEnable);
	asm volatile("nop");
	asm volatile("nop");
	LCDControl &= ~(1 << LCDEnable);
	//to do a command
}
//output
void sendCommand(unsigned char cmd){
	checkStatus();
	LCDMain = cmd; 
	LCDControl &= ~((1 << LCDReadWrite) | (1 << LCDRegistorSelect));
	enable();
	LCDMain = 0;
}
//output
void sendCharacter(unsigned char c){
	checkStatus();
	LCDMain = c;
	LCDControl &= ~(1 << LCDReadWrite);
	LCDControl |= 1 << LCDRegistorSelect;
	enable();
	LCDMain = 0;
}
//output
void sendString(char *stringOfChars){
	checkStatus();
	while(*stringOfChars > 0){
		sendCharacter(*stringOfChars++);
	}
}


