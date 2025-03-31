#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "Login.h"

struct UserInfo
{
	char name[20];
	char last_name[20];
	char username[20];

	int year;
	int month;
	int day;

	float balance;

	char password[20]; // it can be int and char

};



void TestLogin() { // maybe try to do it with unity

	printf("Starting the login test...\n");

	FILE* file;

	struct UserInfo test = { "Jhon", "doe", "Eins", "1990", "5", "15", 1000.0f, "1234" };
		
	errno_t err = fopen_s(&file, "username.txt", "r+b"); 

	if (file == NULL || err != 0) { // the problem is with the file
		printf("there is a problem with a file try later");
		file = fopen_s(&file, "username.txt", "w+b\n");

		if (file == NULL) {
			printf("Unable to create the file.\n");
			return;
		}

		printf("File created successfully.\n");
	}


	fwrite(&test, sizeof(struct UserInfo), 1, file);
	printf("user was written to file succesfuly. \n");

	
	rewind(file);

	char usernameToVerify[] = "Eins";
	struct UserInfo u;
	int AcountFound = 0;

	while (fread(&u, sizeof(struct UserInfo), 1, file)) {
		if (strcmp(u.username, usernameToVerify) == 0) {
			printf("the user was found (:\n");
			AcountFound = 1;
			break;
		}
	}

	if (!AcountFound) {
		printf("the user %s not found automatically. \n", usernameToVerify);
	}

	FILE* TemporyFile;

	err = fopen_s(&TemporyFile, "TemporyFile.txt", "wb");

	if (TemporyFile == NULL || err != 0) {
		printf("there is a problem with a TemporyFile try later");
		return;
		fclose(file);
		return;
	}

	rewind(file);
	int userDeleted = 0; // i need this for Moenyopertions test
	while (fread(&u, sizeof(struct UserInfo), 1, file)) {
		if (strcmp(u.username, "Eins") != 0) {
			fwrite(&u, sizeof(struct UserInfo), 1, TemporyFile);

		}
		else {
			userDeleted = 1;
		}
	}

	if (userDeleted == 1) {
		printf("User 'Eins' deleted succefuly\n");
	}
	else {
		printf("User 'Eins' wasnt found ):\n");
	}

	fclose(file);
	fclose(TemporyFile);

	remove(TemporyFile);
	rename("TemporyFile", "username.txt");

	printf("Test Login completed\n");

	Sleep(2000);
}
