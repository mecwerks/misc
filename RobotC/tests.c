//================================================================================
// Copyright (C) 2013 Marcus E. Collins
//================================================================================
// tests.c
//
// MotorTests - tests all connected motors (number defined by MAX_MOTORS)
// ArmTest - tests a connected arm at a specific port number (defined by ARM_PORT)
//=================================================================================

//=========================================================
// This includes a file called local.c
//
// (Should be in the same directory as this file)
//
// in local.c are definitions and functions used in multiple 
// examples to reduce duplication.
//
// If something is used in this file but not declared here, 
// then it is in common.c or is a RobotC variable/function.
//==========================================================
#include "common.c"

//============================
// MotorTest
//
// Test every motor connected on 
// port1 to (port1 + NUM_MOTORS - 1)
//============================
void MotorTest( void ) {
	int i;

	printf("MotorTest Start\n");

	SensorWait( in1, 1 );

	for (i = 0; i < NUM_MOTORS; i++)
		motor[port1 + i] = MOTOR_FULL;

	SensorWait( in1, 1 );

	for (i = 0; i < NUM_MOTORS; i++)
		motor[port1 + i] = MOTOR_FULL_REVERSE;

	SensorWait( in1, 1 );

	for (i = 0; i < NUM_MOTORS; i++)
		motor[port1 + i] = MOTOR_OFF;

	printf("MotorTest End\n");
}

//=============================
// ArmTest
//
// Turn an arm connected to port 
// ARM_PORT 90 degrees, then turn 
// back 180 degrees, then return 
// to original position.
//=============================
void ArmTest( void ) {
	printf("ArmTest Start\n");

	motor[ARM_PORT] = ARM_SPEED;
	SensorWait( dgtl1, 0.5 );

	motor[ARM_PORT] = MOTOR_OFF;
	wait( 1 );

	motor[ARM_PORT] = -ARM_SPEED;
	SensorWait( dgtl2, 0.5 );

	motor[ARM_PORT] = MOTOR_OFF;
	wait( 1 );

	motor[ARM_PORT] = ARM_SPEED;
	wait1Msec( 700 );
	motor[ARM_PORT] = MOTOR_OFF;

	printf("ArmTest End\n");
}
