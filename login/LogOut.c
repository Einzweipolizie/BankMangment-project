#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>


#include "Login.h"

#include "../Menu/Menu.h" // its fot the function that are getting called for 



void logout() { //its for display 


	system("cls");
	printf("please wait loging out");


	for (int i = 0; i < 3; i++) {
		printf("\n");
		for (int z = 0; z < 80; z++) {
			printf("*");
			Sleep(1);
		}
	}
	gotoxy(30, 10);
	printf("Sign out successfully..\n");

	gotoxy(0, 20);
	printf("press any key to continue..");

	getchar();

	starter_menu();
}
