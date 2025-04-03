#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

#include "Login.h"
#include "../Menu/menu.h" // do i need to do it? // menu.h
#include"../UserInfo.h" // its file with the struct UserInfo
#include "../Acounts/Acount.h" // we inclde Acount.h for the gotxoy function becuse we can only
                               // define her ont time at the project
#define Enter_key 13 


void login() {



	system("cls");

	char username[MAX];
	char password[MAX];
	int account_Found = 0;
	int i = 0;

	if (Users[0].username[0] == '\0') {
		printf("there isnt any user data loaded restart the program\n");
		return;
	}


	gotoxy(34, 2);
	printf("ACOUNT LOGIN");
	gotoxy(7, 5);
	printf("***********************************************"
		"********************************");


	gotoxy(35, 10);
	printf("==== LOG IN ====");




	gotoxy(35, 12);
	printf("Enter your username: ");
	scanf_s("%s", username, MAX);

	gotoxy(35, 14);
	printf("ENTER PASSWORD:");

	memset(password, 0, sizeof(password));




	while (i < 50) {
		char ch = _getch(); // every chartcher you print will be ch

		if (ch != Enter_key) { // the ascii code when you print enter is 13 so when its enter its stops nad i defined 13 as Enter_key
			password[i] = ch; // every time the ch changes and so the password[i]
			ch = '*'; // changes to print this instead of the regular char
			printf("%c", ch); // print * for every char
			i++;
		}

		else {
			password[i] = '\0';
			break;
		}
	}

	// the prbolem i have is hwen i read the file idk why but some grabrage is mixed

	for (int index = 0; index < MAX; index++) {
		
		if (Users[index].username[0] == '\0') {
			printf("there is problem in the for loop in login\n");
			break;
		}
		
		if (strcmp(username, Users[index].username) == 0) {
			if (strcmp(password, Users[index].password) == 0) {
				printf("login successfully!\n");
				loginsu(Users[index].username);
				break;
			}
		}
	}


	if (!account_Found) {
		printf("\nYour account doesn't exist or incorrect username/password.\n");
	}

	
	
}


void loginsu(char username[]) {

	struct UserInfo u;

	system("cls");
	printf("Fetching account details.....\n");

	gotoxy(30, 10);
	printf("LOGIN SUCCESSFUL...");

	Sleep(1500);

	getchar();

	display(username);
	MenuChose(username);

	return;
}
