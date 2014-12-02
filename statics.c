//
//  statics.c
//  GOTO 100
//
//  Copyright (c) 2014 Alfred Woo. All rights reserved.
//

#include "goto100.h"

extern bool isExistDataAt[13][32][8];
extern double scoreList[13][32][8];

//view statics for 'count' days
void viewStatics(int count) {
	printf(">> View Statics for %d days <<\n", count);
	int month, day;
    int i, j;
	getDate(&month, &day);
    
    i = day - count;
    if(i < 1) {
        i = 1;
    }
    
	for(i = i; i <= day; i++) {
		for(j = 1; j < 8; j++) {
			if(isExistDataAt[month][i][j]) printf("%d/%d, %d%s class: %.1lf point(s)\n", month, i, j, getOrdinalNumber(j), scoreList[month][i][j]);
		}
	}
	printf("\n");
}

//view temperature
void viewTemperature() {
	int i, j, k;
	double temp = 0;
	for(i = 1; i < 13; i++) {
		for(j = 1; j < 32; j++) {
			for(k = 1; k < 8; k++) {
				if(isExistDataAt[i][j][k]) temp += scoreList[i][j][k];
			}
		}
	}
	printf(">> Temperature is %.1lf °C <<\n", temp);
	printf("\n");
}