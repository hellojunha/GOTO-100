//
//  input.c
//  GOTO 100
//
//  Copyright (c) 2014 Alfred Woo. All rights reserved.
//

#include "goto100.h"

extern bool isExistDataAt[13][32][8];
extern double scoreList[13][32][8];

//validate user's inputted date before inputting data
void validateDate(FILE *file) {
	printf(">> Add Data <<\n");

	int month, day;
	getDate(&month, &day);

	SET_DATE:;
	printf("Date is %d/%d.\n", month, day);
	printf("Is it correct? (Y if yes, any key for no) >> ");
	char reply;
	scanf("%c", &reply);
	if(reply == 'Y' || reply == 'y') {
		addData(file, month, day);
	} else {
		MANUAL_SET_DATE:;
		printf("Please input date.\n");
		printf("\tMonth >> "); scanf("%d", &month);
		printf("\t  Day >> "); scanf("%d", &day);
		clearInputBuffer();

		if(1 > month || 12 < month) {
			printf("Wrong month data inputted.\n");
			goto MANUAL_SET_DATE;
		}

		if(1 > day || 31 < day) {
			printf("Wrong day data inputted.\n");
			goto MANUAL_SET_DATE;
		} else {
			if(month == 2) {
				if(day > 29) {
					printf("Wrong day data inputted.\n");
					goto MANUAL_SET_DATE;
				}
			}
		}

		goto SET_DATE;
	}

}

//this adds data, and write to file
void addData(FILE *file, int month, int day) {
	printf(">> Adding data for %d/%d << \n", month, day);

	int classCount;
	SET_CLASS:;
	printf("What class will you input for? >> "); scanf("%d", &classCount);
	if(1 > classCount || 7 < classCount) {
		printf("Wrong class inputted.\n");
		goto SET_CLASS;
	}

	if(isExistDataAt[month][day][classCount]) {
		printf("Data already exists for %d/%d, %d%s class.\n", month, day, classCount, getOrdinalNumber(classCount));
		printf("Do you want to override it? (Y if yes, any key for no) >> ");
		clearInputBuffer();
		char reply;
		scanf("%c", &reply);
		if(!(reply == 'Y' || reply == 'y')) return;
	}
	GET_SCORE:;
	printf("Which point you got?\n");
	printf("1 for like, 0 for normal, -1 for dislike.\n");
	int score;
	printf(">> ");
	scanf("%d", &score);
	if(1 < score || -1 > score) {
		printf("Wrong point inputted.\n");
		goto GET_SCORE;
	}
	GET_NOSIT:;
	printf("How many students didn\'t sit down?\n");
	printf(">> ");
	int nosit;
	scanf("%d", &nosit);
	if(0 > nosit || 37 < nosit) {
		printf("Wrong didn\'t sit students count inputted.\n");
		goto GET_NOSIT;
	}

	double finalScore = score - (nosit * 0.5);
	printf("You\'ve got %.1lf degrees celcius at this time!\n", finalScore);
	fprintf(file, "%d %d %d %.1lf\n", month, day, classCount, finalScore);
	fflush(file);
	isExistDataAt[month][day][classCount] = true;
	scoreList[month][day][classCount] = finalScore;
}