/*
 * LCD.c
 *
 * Created: 6/20/2017 6:27:19 PM
 *  Author: piers
 */ 
 //reading input

#ifndef F_CPU
#define F_CPU 8000000UL // I have this at 8Mhz
#endif

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LCD.h"




void LCD(char *message,int scrollText){
 scroll = scrollText;
 // sets all DDRC data direction ports to output bit[1]
 DataDirControl |= 1 << LCDEnable | 1 << LCDReadWrite | 1 << LCDRegistorSelect | 1 << LedGreen;
 _delay_ms(15);
 /* Replace with your application code */
 sendCommand(CLEARSCREEN);
 _delay_ms(2);
 sendCommand(BITMODE8BIT);
 _delay_ms(50);
 sendCommand(LCDOFF);
 _delay_ms(50);

 messageString = message;
 move = sizeof(messageString);
 rows = 16+move;
  //sendCommand(0x10);
 
 }
 
 void checkStatus(){
	 DataDirMain = 0x00;
	 LCDControl |= 1 << LCDReadWrite;
	 LCDControl &= ~(1 << LCDRegistorSelect);
	 while (LCDMain >= BUZZY)
	 {
		 enable();
	 }
	 DataDirMain = 0xFF;
 }

 // debug
 void loop(){
	 _delay_ms(100);
	 PINC |= (1<<LedGreen);

	 if(scroll==1){
		 for(int i = 0; i < rows; i++){
			 sendCommand(0x80 + i+1);
			 sendString(messageString);
			 if(i>rows){
				 i = 0;
			 }
			 
			 //itoa(i,stringPos,10);
			 sendCommand(0x80 + i);
			 sendString(" ");
			 _delay_ms(50);
		 }
	}else{
		sendString(messageString);
	}
	  
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
	 LCDMain = 0x00;
 }
 //output
 void sendCharacter(unsigned char c){
	 checkStatus();
	 LCDMain = c;
	 LCDControl &= ~(1 << LCDReadWrite);
	 LCDControl |= 1 << LCDRegistorSelect;
	 enable();
	 LCDMain = 0x00;
 }
 //output
 void sendString(char *stringOfChars){
	 checkStatus();
	 while(*stringOfChars > 0){
		 printf_P("");
		 sendCharacter(*stringOfChars++);
	 }
 }
