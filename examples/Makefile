#!/bin/bash

all: demoEpoch demoDate demoError
clean:
	rm demoEpoch demoDate

demoEpoch: consoleDemo.cpp
	g++ -o demoEpoch -DTIMESTAMP_EPOCH -I../ consoleDemo.cpp 

demoDate: consoleDemo.cpp
	g++ -o demoDate -DTIMESTAMP_DATE -I../ consoleDemo.cpp

demoError: consoleDemo.cpp
	g++ -o demoError -I../ consoleDemo.cpp
