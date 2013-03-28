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
void ArmTest( int portNum, int motorSpeed, float waitTime  );
void MotorTestMultiple( int startPort, int numMotors, int motorSpeed, float waitTime );
void SensorWait( int sensorNum );
void Motor( int portNum, int motorSpeed );
int CapOutput( int outPower );
int ValidatePort( int portNum );
int ValidateAnalog( int analogIn );
int ValidateDigital( int digitalIn );

//============================
// SenosorWait
//
// Wait for an input on sensorNum 
// then wait waitTime until exiting 
// function
//============================
void SensorWait( int sensorNum ) {
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
		if (portNum == 1) portNum = port1;
		else if (portNum == 2) portNum = port2;
		else if (portNum == 3) portNum = port3;
		else if (portNum == 4) portNum = port4;
		else if (portNum == 5) portNum = port5;
		else if (portNum == 6) portNum = port6;
		else {
			// default to motor port 1
                	printf("WARNING: Output port number %d is invalid! Defaulting to port1\n", portNum);
                	portNum = port1;
		}
	}
	return portNum; // returns a corrected port number
}

//============================
// ValidateAnalog
//
// Make sure analogIn is a valid
// analog input, if not return
// in1
//============================
int ValidateAnalog( int analogIn ) {
	if (analogIn != in1 && analogIn != in2 && analogIn != in3 && 
			analogIn != in4 && analogIn != in5 && analogIn != in6) {
		if (analogIn == 1) analogIn = in1;
		else if (analogIn == 2) analogIn = in2;
		else if (analogIn == 3) analogIn = in3;
		else if (analogIn == 4) analogIn = in4;
		else if (analogIn == 5) analogIn = in5;
		else if (analogIn == 6) analogIn = in6;
		else {
                        // default to analog input 1
                        printf("WARNING: Analog input number %d is invalid! Defaulting to in1\n", analogIn);
                        analogIn = in1;
                }
	}
	return analogIn; // returns a corrected analog number
}

//============================
// ValidateDigital
//
// Make sure digitalIn is a valid
// digital input, if not return
// dgtl1
//============================
int ValidateDigital( int digitalIn ) {
	if (digitalIn != dgtl1 && digitalIn != dgtl2 && digitalIn != dgtl3 &&      
                        digitalIn != dgtl4 && digitalIn != dgtl5 && digitalIn != dgtl6) {
		if (digitalIn == 1) digitalIn = dgtl1;
		else if (digitalIn == 2) digitalIn = dgtl2;
		else if (digitalIn == 3) digitalIn = dgtl3;
		else if (digitalIn == 4) digitalIn = dgtl4;
		else if (digitalIn == 5) digitalIn = dgtl5;
		else if (digitalIn == 6) digitalIn = dgtl6;
		else {
			// default to digital input 1
			printf("WARNING: Digital input number %d is invalid! Defaulting to dgtl1\n", digitalIn);
			digitalIn = dgtl1;
       		}
	}
	return digitalIn; // returns a corrected digital number
}
#endif // __COMMON_C__
