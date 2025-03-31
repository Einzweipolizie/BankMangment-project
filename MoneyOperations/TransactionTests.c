#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <assert.h>

#include "MoenyOperation.h"

//#define _CRT_SECURE_NO_WARNINGS

#include"../UserInfo.h" // Its file with the struct UserInfo

void AcountTest() {

	printf("\nStarting AcountTest...\n"); // there is a problem in tranfermoeny function two when opening file
	
	FILE* UserFile;
	FILE* MoneyFile;

	errno_t err = fopen_s(&UserFile, "TemporyFile.txt", "wb"); // maybe w+b
	errno_t err2 = fopen_s(&MoneyFile, "TemporyMoneyFile.txt", "wb");

	if (UserFile == NULL) {
		printf("Error opening UserFile in AcountTest with %d error code \n", err);

		return;
	}

	if (MoneyFile == NULL) {
		printf("Error opening MoneyFile in AcountTest with error code \n");
		return;
	}

	struct UserInfo u1 = { "John", "Doe", "john123", 1995, 5, 15, 100.00f, "password" };
	struct UserInfo u2 = { "Jane", "Doe", "jane456", 1990, 3, 10, 0, "password123" };
	struct money m;


	fwrite(&u1, sizeof(u1), 1, UserFile);
	fclose(UserFile);
	fclose(MoneyFile);

	strcmp(m.your_username, "john123");
	strcmp(m.his_username, "jane456");

	m.HowMuchSent = 50; // test 1

	u1.balance -= m.HowMuchSent;

	assert(u1.balance == 50.00f);
	printf("test 1 passed : Balance has benn decreased\n");

	//late do the checking of the mon.txt file content
	
	m.HowMuchSent = 150; // test 2
	if (u1.balance < m.HowMuchSent) {
		printf("test 2 passed: insufficient balance error correctly handled\n");
	}
	else {
		printf("IN TEST 2 IS A PROBLEM!!!!");
	}

	strcmp(m.your_username, "idk_what_user"); //test 3
	if (strcmp(m.your_username, u1.username) != 0) {
		printf("test 3 passed: there wsa fake name and it didnt agree to it");
	}
	else {
		printf("IN test 3 is a problem!!!!! ): ");
	}


	remove("TemporyFile.txt");
	remove("TemporyMoneyFile.txt");

	Sleep(2000);

	

}


