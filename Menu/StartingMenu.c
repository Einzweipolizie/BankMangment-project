#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

#include "menu.h"
#include "../login/Login.h"


int starter_menu() { // we can add here option for log out!!!




	system("cls");

	int choice;

	printf("WELCOME TO BANK ACCOUNT SYSTEM\n\n");
	gotoxy(18, 5);

	printf("**********************************");
	gotoxy(25, 7);

	printf("DEVELOPER - David kan");


	gotoxy(20, 10);
	printf("1.... CREATE A BANK ACCOUNT");

	gotoxy(20, 12);
	printf("2.... ALREADY A USER? SIGN IN");
	gotoxy(20, 14);
	printf("3.... EXIT\n\n");

	printf("\n\nENTER YOUR CHOICE..");

	scanf_s("%d", &choice, sizeof(choice));


	switch (choice) {
	case 1:
		acount();
		break;
		getchar();
	case 2:
		login();
		break;
		getchar();

	case 3:
		exit(0);
		break;
		getchar();

	}
}