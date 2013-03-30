//================================================================================
// Copyright (C) 2013 Marcus E. Collins
//================================================================================
// non-RobotC.c
//
// Function testing
//=================================================================================

#include "common.c"
#include "tests.c"

void _MotorTest( void ) {
	int portNum, motorSpeed, waitTime = 0;

	printf("Enter a port number to test on (1 -> 6).\n");
	scanf("%d", &portNum);

	printf("Enter an output strength (-127 -> 127).\n");
        scanf("%d", &motorSpeed);

	printf("Enter how long to spin motor (in seconds).\n");
        scanf("%d", &waitTime);

	portNum = NumtoIO( portNum, OUTPUT );

	printf("Spining motor on port %d at a speed of %d for %d seconds.\n", portNum, motorSpeed, waitTime);
	MotorTest( portNum, motorSpeed, waitTime );
}

void _MotorTestMultiple( void ) {
        int startPort, numMotors, motorSpeed, waitTime = 0;

        printf("Enter the first port to start with (1 -> 6).\n");
        scanf("%d", &startPort);

	printf("Enter how many motors to test (1 -> 6).\n");
        scanf("%d", &numMotors);

        printf("Enter an output strength (-127 -> 127).\n");
        scanf("%d", &motorSpeed);

        printf("Enter how long to spin motor (in seconds).\n");
        scanf("%d", &waitTime);

        startPort = NumtoIO( startPort, OUTPUT );

	printf("Spining motors on port %d to port %d at a speed of %d for %d seconds.\n", 
			startPort, startPort + numMotors - 1, motorSpeed, waitTime);
        MotorTestMultiple( startPort, numMotors, motorSpeed, waitTime );
}

void _SensorWait( void ) {
	int sensorNum = 0;
	
	printf("Enter a sensor number:\n"
		"(1 -> 6) = (in1 -> in6)\n"
		"(7 -> 12) = (dgtl1 -> dgtl6)\n");
	scanf("%d", &sensorNum);

	sensorNum = NumtoIO( sensorNum, INPUT );

	printf("Waiting for input on sensor number %d\n", sensorNum);
	SensorWait( sensorNum );
}

void _Motor( void ) {
	int motorNum, motorSpeed = 0;

	printf("Enter a motor number (1 -> 6).\n");
	scanf("%d", &motorNum);

	printf("Enter the output strength (-127 -> 127).\n");
	scanf("%d", &motorSpeed);

	motorNum = NumtoIO( motorNum, OUTPUT );

	printf("Setting output strength on port %d to %d.\n", motorNum, motorSpeed);
	Motor( motorNum, motorSpeed );
}

void _CapOutput( void ) {
	int outPower = 0;

	printf("Enter an output number to limit.\n");
	scanf("%d", &outPower);

	printf("Limitiing output %d.", outPower);
	CapOutput( outPower );
}

void _ValidatePort( void ) {
	int portNum = 0;

	printf("Enter an output port number (1 -> 6).\n");
	scanf("%d", &portNum);

	portNum = NumtoIO( portNum, OUTPUT );

	printf("Validating port number %d.\n", portNum);
	ValidatePort( portNum );
}

void _ValidateInput( void ) {
	int inputNum = 0;

	printf("Enter an input number:\n"
                "(1 -> 6) = (in1 -> in6)\n"
                "(7 -> 12) = (dgtl1 -> dgtl6)\n");
	scanf("%d", &inputNum);

	inputNum = NumtoIO( inputNum, INPUT );

	printf("Validating input number %d.\n", inputNum);
	ValidateInput( inputNum );
}

void _wait( void ) {
	unsigned long waitTime = 0;

	printf("Enter an amount of time to wait (in seconds).\n");
	scanf("%lu", &waitTime);

	printf("Waiting for %lu seconds.\n", waitTime);
	wait( waitTime );
}

void _wait1Msec( void ) {
	unsigned long waitTime = 0;

        printf("Enter an amount of time to wait (in milliseconds).\n");
        scanf("%lu", &waitTime);

        printf("Waiting for %d milliseconds.\n", (int)waitTime);
        wait1Msec( waitTime );
}

void _FUNC_BEGIN( void ) {
	printf("FUNC_BEGIN:\n"
		"Usage: FUNC_BEGIN(\"FunctionName\");"
		"Used for printing the begining of a function.\n");
	FUNC_BEGIN("_FUNC_BEGIN");
}

void _FUNC_END( void ) {
	printf("FUNC_END:\n"
                "Usage: FUNC_END(\"FunctionName\");"
                "Used for printing the ending of a function.\n");
	FUNC_END("_FUNC_END");
}

void ListVariables( void ) {
	printf("Variables:\n"
		"MOTOR_OFF - motor speed %d (off)\n"
		"MOTOR_FULL - motor speed %d (max)\n"
		"MOTOR_FULL_REVERSE - motor speed %d (max reverse)\n"
		"DEFAULT_SPEED - default motor speed %d\n"
		"MAX_DIGITAL - max digital input dgtl6\n"
		"MAX_ANALOG - max analog input in6\n"
		"INPUT - input flag (%d)\n"
		"OUTPUT - output flag (%d)\n",
		MOTOR_OFF, MOTOR_FULL, MOTOR_FULL_REVERSE, DEFAULT_SPEED, 
		INPUT, OUTPUT);
}

