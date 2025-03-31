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

	FILE* file;

	char username[MAX];
	char password[MAX];

	int i = 0;
	int account_Found = 0;

	struct UserInfo u;

	printf("Struct size in login.c: %zu\n", sizeof(struct UserInfo));

	errno_t err = fopen_s(&file, "username.txt", "rb");



	if (file == NULL) {
		printf("there is a problem with a file try later");
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

	rewind(file);

	memset(&u, 0, sizeof(struct UserInfo));


	while (fread(&u, sizeof(struct UserInfo), 1, file)) {


		printf("\nStored username : %s\n", u.username);
		printf("Stored password: %s\n", u.password);
		printf("Entered username: %s\n", username);
		printf("Entered password: %s\n", password);

		if (strcmp(username, u.username) == 0) { // compres from file and what you write
			if (strcmp(password, u.password) == 0) {
				printf("the password was found successfuly!!\n");
				account_Found = 1;
				fclose(file);
				loginsu(u.username);
				break;
			}
		}
	}


	if (!account_Found) {
		printf("\nYour account doesn't exist or incorrect username/password.\n");
	}

	fclose(file);
	
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
