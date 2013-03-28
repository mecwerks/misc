//================================================================================
// Copyright (C) 2013 Marcus E. Collins
//================================================================================
// common.c
//
// functions and definitions used in multiple projects/source files; reduces need
// of duplication
//=================================================================================

#ifndef __COMMON_C__	// these two lines keep everything from
#define __COMMON_C__	// being defined twice

#ifdef NOT_ROBOTC		// this needs to be set to true when compiling with a non-robotc compiler
#include <stdio.h>

#define task	int
#define wait1Msec(x)

typedef enum {
	// motor ports
	port1,
	port2,
	port3,
	port4,
	port5,
	port6,
	// analog ports
	in1,
	// digitsl ports
	dgtl1,
	dgtl2
} compatability_enum_t;

int SensorValue[32];
int motor[32];
#else
#define printf(x)
#endif

#define MOTOR_OFF		0		// motor speed 0 (off)
#define ARM_SPEED		25		// motor speed 25; for use in ArmTest
#define MOTOR_FULL		127		// motor speed 127 (max)
#define MOTOR_FULL_REVERSE	-127		// motor speed -127 (max reverse)
#define NUM_MOTORS		5		// number of motors to test in MotorTest (starts with port1)
#define ARM_PORT		port6		// port number to do ArmTest on
#define wait(x)		wait1Msec(x * 1000)	// wait x * 1000 milliseconds
                          			//      (converts seconds to milliseconds)
//==========================================================
// Normally, when calling a function, the function
// needs to be declared before using it done like this...
//
// int foo( int bar ) {
//      return (bar * 10);
// }
//
// task main () {
//      foo( 5 );
// }
//
// Functions can be put into any order if you declare
// them like this at the top of common.c (without /'s )
//
// void MotorTest( void );
// void ArmTest( void );
//==========================================================
void ArmTest( void );
void MotorTest( void );
void SensorWait( int sensorNum, float waitTime );

//============================
// SenosrWait
//
// Wait for an input on sensorNum 
// then wait waitTime until exiting 
// function
//============================
void SensorWait( int sensorNum, float waitTime ) {
	while ( SensorValue[sensorNum] ) {}
	wait ( waitTime );
}

#endif // __COMMON_C__
