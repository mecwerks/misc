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

#include "compatibility.h"			// check file for info

#define MOTOR_OFF		0		// motor speed 0 (off)
#define MOTOR_FULL		127		// motor speed 127 (max)
#define MOTOR_FULL_REVERSE	-127		// motor speed -127 (max reverse)
#define DEFAULT_SPEED           60              // default motor speed
#define MAX_DIGITAL		dgtl6		// max digital input
#define MAX_ANALOG		in6		// max analog input
#define INPUT			0x01		// input flag
#define OUTPUT			0x02		// output flag
#define wait(x)		wait1Msec(x * 1000)	// wait x * 1000 milliseconds
                          			//      (converts seconds to milliseconds)
#define FUNC_BEGIN(x)		printf("%s Start\n", x);
#define FUNC_END(x)		printf("%s End\n", x);
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
// them like this ...
//==========================================================
void MotorTest( int portNum, int motorSpeed, float waitTime  );
void MotorTestMultiple( int startPort, int numMotors, int motorSpeed, float waitTime );
void SensorWait( int sensorNum );
void Motor( int portNum, int motorSpeed );
int CapOutput( int outPower );
int ValidatePort( int portNum );
int ValidateInput( int inputNum );
int NumtoIO( int ioNum, int IO );

//============================
// SenosorWait
//
// Wait for an input on sensorNum 
// then wait waitTime until exiting 
// function
//============================
void SensorWait( int sensorNum ) {
	ValidateInput( sensorNum );
#ifdef NOT_ROBOTC
	printf("SensorWait: sensorNum %d\n", sensorNum);
	sleep( 2 );
	printf("SensorWait: got a signal on %d!\n", sensorNum);
#else
	while ( SensorValue[sensorNum] ) {}
#endif
}

//============================
// Motor
//
// Function of motor[] variable
//============================
void Motor( int portNum, int motorSpeed ) {
	portNum = ValidatePort(portNum);
	motorSpeed = CapOutput(motorSpeed);
	motor[portNum] = motorSpeed;
	printf("Motor: port %d set to %d speed\n", portNum, motorSpeed);
}

//============================
// CapOutput
//
// Checks that
// -128 < outPower < 128
//============================
int CapOutput( int outPower ) {
	if (outPower > 127) {
		printf("WARNING: outPower was more than 127: %d\n", outPower);
		outPower = DEFAULT_SPEED;
	} else if (outPower < -127) {
		printf("WARNING: outPower was less than -127: %d\n", outPower);
		outPower = -DEFAULT_SPEED;
	}
	return outPower;
}

//============================
// ValidatePort
//
// Make sure portNum is a valid
// port number, if not return
// port1
//============================
int ValidatePort( int portNum ) {
	if (portNum != port1 && portNum != port2 && portNum != port3 && 
			portNum != port4 && portNum != port5 && portNum != port6) {
		// default to motor port 1
		printf("WARNING: Output port number %d is invalid! Defaulting to port1\n", portNum);
		return port1;
	}
	return portNum; // returns a corrected port number
}

//============================
// ValidateInput
//
// Make sure inputNum is a valid
// input, if not return in1
//============================
int ValidateInput( int inputNum ) {
	int	i;

	for (i = 0; i <= MAX_DIGITAL; i++)
		if (inputNum == (dgtl1 + i))
			return inputNum;

	for (i = 0; i <= MAX_ANALOG; i++)
		if (inputNum == (in1 + i))
			return inputNum;

	// if inputNum isn't valid, return in1.
	printf("WARNING: %d is not a valid input number, defaulting inputNum to in1\n", inputNum);
	return in1;
}

//============================
// NumtoIO
//
// Convert ioNum to an output
// of (port1 -> port6) if IO
// is OUTPUT, or convert ioNum
// to (in1 -> dgtl6) if IO is
// INPUT
//============================
int NumtoIO ( int ioNum, int IO ) {
	if ( IO == OUTPUT ) {
		if (ioNum == 1) return port1;
		else if (ioNum == 2) return port2;
		else if (ioNum == 3) return port3;
		else if (ioNum == 4) return port4;
		else if (ioNum == 5) return port5;
		else if (ioNum == 6) return port6;
		else {
			printf("WARNING: NumtoIO: Output port number %d is invalid! Defaulting to port1\n", ioNum);
                	return port1;
		}
	} else if ( IO == INPUT ) {
		if (ioNum == 1) return in1;
		else if (ioNum == 2) return in2;
		else if (ioNum == 3) return in3;
		else if (ioNum == 4) return in4;
		else if (ioNum == 5) return in5;
		else if (ioNum == 6) return in6;
		else if (ioNum == 7) return dgtl1;
		else if (ioNum == 8) return dgtl2;
		else if (ioNum == 9) return dgtl3;
		else if (ioNum == 10) return dgtl4;
		else if (ioNum == 11) return dgtl5;
		else if (ioNum == 12) return dgtl6;
		else {
			printf("WARNING: NumtoIO: Input number %d is invalid! Defaulting to in1\n", ioNum);
                        return in1;
		}
	} else {
		printf("ERROR: NumtoIO: IO number %d is invalid!\n", IO);
	}
}
#endif // __COMMON_C__
