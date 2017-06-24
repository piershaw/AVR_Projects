/*
 * ClockSpeed.h
 *
 * Created: 6/22/2017 8:36:26 PM
 *  Author: piers
 */ 
#define TRUE 1
#define FALSE 0
#define External_Clock FALSE


#ifndef CLOCKSPEED_H_
#define CLOCKSPEED_H_


#ifndef F_CPU
#define F_CPU 1000000UL // I have this at 1Mhz Internal Clock
#endif

//#ifndef F_CPU
//#define F_CPU 8000000UL // I have this at 8Mhz Internal Clock
//#endif

//#ifndef F_CPU
//#define F_CPU 20000000UL // I have this at 8Mhz External Clock
//#endif

#endif /* CLOCKSPEED_H_ */