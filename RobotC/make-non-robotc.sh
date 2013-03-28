#!/bin/sh

BUILD_DIR=build

if [ ! -d "$BUILD_DIR" ];
then
	mkdir -p $BUILD_DIR/non-robotc;
fi

gcc -DNOT_ROBOTC main.c -o $BUILD_DIR/non-robotc/NRobotC
