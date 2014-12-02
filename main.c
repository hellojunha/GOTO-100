//
//  main.c
//  GOTO 100
//
//  Copyright (c) 2014 Alfred Woo. All rights reserved.
//

#include "goto100.h"

bool isExistDataAt[13][32][8] = {false};		//check if data exsist for the class
double scoreList[13][32][8] = {0};				//score for the class

//main function
int main(int argc, char *argv[]) {
	FILE *savedData = fopen("data.txt", "r+");
	if(savedData == NULL) {
		savedData = fopen("data.txt", "w");
	}

	readData(savedData);

	printf("Welcome to GOTO 100!\n");
	printf(">> Select Menu <<\n");

	int iSelectedMenu;
	while((iSelectedMenu = getMenu()) != 9) {
		clearInputBuffer();
		switch (iSelectedMenu) {
			case 1:
				validateDate(savedData);
				break;
			case 2:
				viewStatics(1);
				break;
			case 3:
				viewStatics(7);
				break;
			case 4:
				viewTemperature();
				break;
			default:
				printf("Wrong menu inputted.\n");
				break;
		}
	}

	fclose(savedData);
	printf("Bye\n");
	return 0;
}