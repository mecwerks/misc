//================================================================================
// Copyright (C) 2013 Marcus E. Collins
//================================================================================
// compatibility.c
//
// this file makes it so we can compile the code on non-RobotC machines
//=================================================================================

#ifndef __COMPATIBILITY_H__
#define __COMPATIBILITY_H__

#ifdef NOT_ROBOTC
#include <stdio.h>
#include <unistd.h>

#define task    int
typedef enum {
        // motor ports
        port1, port2, port3,
        port4, port5, port6,
        // analog ports
        in1, in2, in3,
	in4, in5, in6,
        // digital ports
        dgtl1, dgtl2, dgtl3,
	dgtl4, dgtl5, dgtl6
} compatability_enum_t;

// these need to be zero so we don't get stuck in any while() loops!
int SensorValue[16] = {0, 0, 0, 0, 0, 0, 0, 0};
int motor[8];

void wait1Msec( unsigned int x ) {
	printf("wait1Msec: waiting %d milliseconds\n", x);
	sleep(x / 1000);
}
#else
#define ROBOTC
#define printf(x)
#endif

#endif
