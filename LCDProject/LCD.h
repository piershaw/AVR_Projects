/*
 * LCD.h
 *
 * Created: 6/20/2017 6:40:46 PM
 *  Author: piers
 */ 

#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef LCD_H_
#define LCD_H_

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


int rows;
int move;
int scroll;
char stringPos[4];
char * messageString;

void LCD(char *message,int scrollText);
void enable(void);
void sendCommand(unsigned char);
void sendCharacter(unsigned char);
void checkStatus(void);
void sendString(char *stringOfChars);
void loop();
void findRowsinLCD(void);

#endif /* LCD_H_ */