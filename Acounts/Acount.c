
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

#include "Acount.h"
#include "../login/Login.h"
#include"../UserInfo.h" // Its file with the struct UserInfo

#define _CRT_SECURE_NO_WARNINGS



void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void acount() { //  do tests tomorow
	FILE* file;
	errno_t err = fopen_s(&file, "username.txt", "ab"); // ab and w for deleting

	struct UserInfo u = {0};


	if (err != 0) {
		printf("Error opening file: %d\n", err);
		return;
	}

	system("cls");

	printf("!!!CREATE ACOUNT!!!\n");

	int c;
	while ((c = getchar()) != '\n' && c != EOF) {}

	while (_kbhit()) {
		getchar();
	}

	takeInput("your first name? ", u.name, "string"); // do a function takeInput(string InputMsg, varibaleToWrite, ....) 
	takeInput("last_name please: ", u.last_name, "string");
	takeInput("insert your username: ", u.username, "string");
	takeInput("what year were you born: ", &u.year, "%d");
	takeInput("what month were you born: ", &u.month, "%d");
	takeInput("what day were you born: ", &u.day, "%d");
	takeInput("Please enter your initial balance: ", &u.balance, "%f");
	takeInput("password please: ", u.password, "string");


	u.username[sizeof(u.username) - 1] = '\0';
	u.password[sizeof(u.password) - 1] = '\0';

	
	if (fwrite(&u, sizeof(struct UserInfo), 1, file) != 1) {
		printf("Error writing to file\n");
		fclose(file);
		return;
	}

	for (int i = 0; i < MAX; i++) { // its adding to the struct array 
		if (strlen(Users[i].username) == 0) {
			Users[i] = u;
			break;
		}

	}

	//printf("Struct size in acount.c: %zu\n", sizeof(struct UserInfo));
	//Sleep(3000); // can be used to see if any of the the things we wrote is no getting it


	fclose(file);



	
	TestFileWrite();
	acount_created();

}

void takeInput(char *InputMsg, void *var, char *format) { // ask nir why its need to be pointer
	printf("%s", InputMsg);

	if (strcmp(format, "string") == 0) {
		fgets((char*)var, MAX, stdin); // here why nned pointer with ()
		((char*)var)[strcspn((char*) var, "\n")] = '\0'; // and here
	}
	else {

		scanf_s(format, var);

		int c;
		while ((c = getchar()) != '\n' && c != EOF) {}
	}
}

void acount_created() {

	system("cls");
	printf("PLEASE WAIT....\n\nYOUR DATA IS PROCESSING....");
	Sleep(3000);

	gotoxy(33, 10);

	printf("ACCOUNT CREATED SUCCESSFULLY....");

	printf("press enter to login:");

	getchar();

	login(); //later need to do login function

}