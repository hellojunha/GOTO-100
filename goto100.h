//
//  goto100.h
//  GOTO 100
//
//  Copyright (c) 2014 Alfred Woo. All rights reserved.
//

#ifndef __GOTO100_H__
	#define __GOTO100_H__

    #include <stdio.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <time.h>

	//descriptions for each function are in front of the function openings.
	void readData(FILE *);				//tools.c
	int getMenu();						//tools.c
	void validateDate(FILE *);			//input.c
	void addData(FILE *, int, int);		//input.c
	void viewStatics(int);				//statics.c
	void viewTemperature();				//statics.c
	void clearInputBuffer();			//tools.c
	void getDate(int *, int *);			//tools.c
	char *getOrdinalNumber(int);		//tools.c
#endif