/*
 * USBController.c
 *
 * Created: 1/22/2017 9:54:48 AM
 * Author : piers
 */ 

//start of the test for my Virtual LCD app 

#define F_CPU 1000000UL // later i need a ext crystal

#define UART_TXD_PORT    PORTD
#define UART_TXD_DIR     DDRD
#define UART_TXD_PIN     PIND
#define UART_TXD_BIT     1
#define UART_RXD_PORT    PORTD
#define UART_RXD_DIR     DDRD
#define UART_RXD_PIN     PIND
#define UART_RXD_BIT     0

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>

txSend(char* pBuffer, unsigned int uiSize);
rxReceive(char* pBuffer, unsigned int uiSize);
IsTxReady(void);
IsRxReady(void);

char* pTxBuffer;
char* pRxBuffer;
unsigned int uiTxCounter;
unsigned int uiTxSize;
unsigned int uiRxCounter;
unsigned int uiRxSize;

int main(void)
{

	DDRB = 1 << PCINT0; // Enable PCINT0 ahh might work
	DDRB = 1 << PORTB;
	TCCR0B  |= (1 << ISC00) |(1 << ISC01); // timer control register // might not need it
	EICRA  |= (1 << ISC00) |(1 << ISC01);     // set INT0 to trigger on ANY logic change
	EIMSK |= (1 << INT0);       // Turns on INT0
	
	// when pin 14 is low to ground ISR(PCINT0_vect) will run

    sei(); //Enable Global Interrupt
    while (1) 
    {
	
	_delay_ms(500);
	// stuff
    }
}

//Interrupt Service Routine analog to digital
ISR(ADC_vect){
//
}
//Interrupt Service Routine INT0
ISR(PCINT0_vect){
	printf("triggered");
}

// unexpected interrupt occurs 
ISR(BADISR_vect){

}

txSend(char* pBuffer, unsigned int uiSize){

}

rxReceive(char* pBuffer, unsigned int uiSize){

}


