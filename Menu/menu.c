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



	for (int index = 0; index < MAX; index++) {
		if (Users[index].username[0] != '\0') {
			if (strcmp(Users[index].username, username) == 0) {
				gotoxy(30, 1);
				printf("WELCOME, %s, %s", Users[index].name, Users[index].last_name);
				gotoxy(28, 2);
				printf("..........................");
				gotoxy(55, 6);
				printf("==== YOUR ACCOUNT INFO ====");
				gotoxy(55, 8);
				printf("***************************");
				gotoxy(55, 10);
				printf("NAME..%s %s", Users[index].name, Users[index].last_name); // you can test here if its true or nor too
				gotoxy(55, 12);
				printf("DATE OF BIRTH.. %d-%d-%d", Users[index].year, Users[index].month, Users[index].day); // you can test here if its true or nor too
				gotoxy(55, 14);
				printf("YOU HAVE IN THE BLANCE: %f", Users[index].balance);
				// you can add more its not a proble

			}

		}
	}
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
	printf(" 4....Delete your User\n");
	gotoxy(0, 17);
	printf(" 5....EXIT\n");
	gotoxy(0, 19);

	printf("ENTER YOUR CHOISE:");
	scanf_s("%d", &choice, sizeof(choice));

	switch (choice) {
	case 1:
		//checkbalance(username); //later
		break;

	case 2:
		transfermoney(username);
		break;
	case 3:
		logout(); 
		break;
	case 4:
		DeleteUser(username);
		LoadToFile();
		exit(0);
		break;
	case 5:
		exit(0);
		break;
	}


}

