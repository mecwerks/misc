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
// MotorTestMultiple
//
// Test every motor connected on 
// startPort to (startPort + numMotors - 1)
//============================
void MotorTestMultiple( int startPort, int numMotors, int motorSpeed, float waitTime ) {
	int i;

	FUNC_BEGIN("MotorTestMultiple");

	if (waitTime < 1)
		printf("WARNING: waitTime is lower than 1 second: %f\n", waitTime);

	for (i = 0; i < numMotors; i++)
		Motor(startPort + i, motorSpeed);

	wait( waitTime );

	for (i = 0; i < numMotors; i++)
		Motor(startPort + i,  MOTOR_OFF);

	FUNC_END("MotorTestMultiple");
}

//=============================
// MotorTest
//
// Turn a motor connected to port 
// armPort at a speed of armSpeed
// for waitTime seconds
//=============================
void MotorTest( int portNum, int motorSpeed, float waitTime ) {
	FUNC_BEGIN("MotorTest");

	if (waitTime < 1)
                printf("WARNING: waitTime is lower than 1 second: %f\n", waitTime);
	
	Motor(portNum, motorSpeed);

	wait( waitTime );

	Motor(portNum, MOTOR_OFF);
	
	FUNC_END("MotorTest");
}
