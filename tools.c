//
//  tools.h
//  GOTO 100
//
//  Copyright (c) 2014 Alfred Woo. All rights reserved.
//

#include "goto100.h"

extern bool isExistDataAt[13][32][8];
extern double scoreList[13][32][8];

//read and analyize data from data file
void readData(FILE *file) {
	while(!feof(file)) {
		int month, day, theClass;
		double score;
		fscanf(file, "%d %d %d %lf\n", &month, &day, &theClass, &score);
		if(month * day * theClass == 0) break;
		isExistDataAt[month][day][theClass] = true;
		scoreList[month][day][theClass] = score;
	}
}

//print and get menu selection
int getMenu() {
	printf("\t1. Add Data\n");
	printf("\t2. View Statics for 1 day\n");
	printf("\t3. View Statics for 1 week\n");
	printf("\t4. View Temperature\n");
	printf("\t9. Quit\n");
	printf("\t>> ");

	int iSelectedMenu;
	scanf("%d", &iSelectedMenu);
	return iSelectedMenu;
}

//literally, clear input buffer
void clearInputBuffer() {
	while(getchar() != '\n');
}

//get today's date
void getDate(int *month, int *day) {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	*month = tm.tm_mon + 1;
	*day = tm.tm_mday;
}

//print ordinal number (1st, 2nd, 3rd, 4th ...)
char *getOrdinalNumber(int i) {
	switch (i) {
		case 1:
			return "st";
		case 2:
			return "nd";
		case 3:
			return "rd";
		default:
			return "th";
	}
}