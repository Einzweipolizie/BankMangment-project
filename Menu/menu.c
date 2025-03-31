#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

#include "menu.h"
#include "../login/Login.h"
#include "../MoneyOperations/MoenyOperation.h" // need to chek

#include"../UserInfo.h" // Its file with the struct UserInfo

#include "../Acounts/Acount.h"; // we inclde Acount.h for the gotxoy function becuse we can only
                                   // define her ont time at the project


void display(char username[]) {

	system("cls");

	FILE* file;
	errno_t err = fopen_s(&file, "username.txt", "rb");
	struct UserInfo u;

	if (err != 0) {
		printf("Error opening username.txt in display() with error code %d\n", err); // here the problem two

		return;
	}


	while (fread(&u, sizeof(u), 1, file)) {

		

		if (strcmp(username, u.username) == 0) {
			gotoxy(30, 1);
			printf("WELCOME, %s, %s", u.name, u.last_name);
			gotoxy(28, 2);
			printf("..........................");
			gotoxy(55, 6);
			printf("==== YOUR ACCOUNT INFO ====");
			gotoxy(55, 8);
			printf("***************************");
			gotoxy(55, 10);
			printf("NAME..%s %s", u.name, u.last_name); // you can test here if its true or nor too
			gotoxy(55, 12);
			printf("DATE OF BIRTH.. %d-%d-%d", u.year, u.month, u.day); // you can test here if its true or nor too
			gotoxy(55, 14);
			printf("YOU HAVE IN THE BLANCE: %f", u.balance);

			// you can add more its not a problem
		}

	}

	fclose(file);

}

void MenuChose(char username[]) {
	int choice;

	struct UserInfo u;

	gotoxy(0, 6);



	printf(" HOME ");
	gotoxy(0, 7);
	printf("******");
	gotoxy(0, 9);
	printf(" 1....CHECK BALANCE");
	gotoxy(0, 11);
	printf(" 2....TRANSFER MONEY");
	gotoxy(0, 13);
	printf(" 3....LOG OUT\n\n");
	gotoxy(0, 15);
	printf(" 4....EXIT\n\n");


	printf("ENTER YOUR CHOISE:");
	scanf_s("%d", &choice, sizeof(choice));

	switch (choice) {
	case 1:
		//checkbalance(username); //later
		break;

	case 2:
		transfermoney(); 
		break;
	case 3:
		logout(); 
		break;
	case 4:
		exit(0);
		break;
	}


}

