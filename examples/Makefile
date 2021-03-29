#!/bin/bash

all: demoEpoch demoDate demoError
clean:
	rm demoEpoch demoDate

demoEpoch: consoleDemo.cpp
	g++ -o demoEpoch -DTIMESTAMP_EPOCH consoleDemo.cpp 

demoDate: consoleDemo.cpp
	g++ -o demoDate -DTIMESTAMP_DATE consoleDemo.cpp

demoError: consoleDemo.cpp
	g++ -o demoError consoleDemo.cpp
