//================================================================================
// Copyright (C) 2013 Marcus E. Collins
//================================================================================
// main.c
//
// Main Control 
//=================================================================================

#include "common.c"
#include "tests.c"

task main () {
	FUNC_BEGIN("Main");
	SensorWait( 73 );
	MotorTest(port6, 100, 2);
	MotorTestMultiple(port1, 5, 127, 2);
	FUNC_END("Main");
}
