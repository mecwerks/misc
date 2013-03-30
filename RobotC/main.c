//================================================================================
// Copyright (C) 2013 Marcus E. Collins
//================================================================================
// main.c
//
// Main Control 
//=================================================================================

#ifdef ROBOTC // if compiling with RobotC

#include "common.c"
#include "tests.c"

task main () {
	FUNC_BEGIN("Main");
	SensorWait( 73 );
	MotorTest(port6, 100, 2);
	MotorTestMultiple(port1, 5, 127, 2);
	FUNC_END("Main");
}

#else // if compiling with any other compiler

#include "non-RobotC.c"

task main () {
        int selection = 0;
        
	printf("\n"
		"RobotC testing for non-RobotC compilers.\n"
       		"Copyright (C) 2013 Marcus E. Collins\n"
	       	"\n");

	while(1) {
	        printf("Enter a number...\n"
	                "(1) MotorTest();\n"
	                "(2) MotorTestMultiple();\n"
	                "(3) SensorWait();\n"
	                "(4) Motor();\n"
	                "(5) CapOutput();\n"
	                "(6) ValidatePort();\n"
	                "(7) ValidateInput();\n"
	                "(8) wait();\n"
	                "(9) wait1Msec();\n"
	                "(10) FUNC_BEGIN();\n"
	                "(11) FUNC_END();\n"
	                "(12) List Variables.\n"
	                "(13) Quit.\n");

	        while (1) {
	                scanf("%d", &selection);
	
        	        if ( selection < 1 || selection > 13)
        	                printf("INVALID SELECTION\n");
        	        else
        	                break;
        	}
        
        	if (selection == 1) _MotorTest();
        	else if (selection == 2) _MotorTestMultiple();
        	else if (selection == 3) _SensorWait();
        	else if (selection == 4) _Motor();
        	else if (selection == 5) _CapOutput();
        	else if (selection == 6) _ValidatePort();
        	else if (selection == 7) _ValidateInput();
        	else if (selection == 8) _wait();
        	else if (selection == 9) _wait1Msec();
        	else if (selection == 10) _FUNC_BEGIN();
        	else if (selection == 11) _FUNC_END();
        	else if (selection == 12) ListVariables();
        	else if (selection == 13) return 0;

		sleep(5);
		printf("\n");
	}
}

#endif
