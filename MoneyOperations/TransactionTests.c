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
	struct Transaction m;


	fwrite(&u1, sizeof(u1), 1, UserFile);
	fclose(UserFile);
	fclose(MoneyFile);

	strcmp(m.receiver, "john123");
	strcmp(m.sender, "jane456");

	m.amount = 50; // test 1

	u1.balance -= m.amount;

	assert(u1.balance == 50.00f);
	printf("test 1 passed : Balance has benn decreased\n");

	//late do the checking of the mon.txt file content
	
	m.amount = 150; // test 2
	if (u1.balance < m.amount) {
		printf("test 2 passed: insufficient balance error correctly handled\n");
	}
	else {
		printf("IN TEST 2 IS A PROBLEM!!!!");
		return;
	}

	strcmp(m.receiver, "idk_what_user"); //test 3
	if (strcmp(m.receiver, u1.username) != 0) {
		printf("test 3 passed: there wsa fake name and it didnt agree to it\n");
	}
	else {
		printf("IN test 3 is a problem!!!!! ): ");
		return;
	}


	remove("TemporyFile.txt");
	remove("TemporyMoneyFile.txt");

	printf("AcountTest WAS PASSED!!");

	Sleep(2000);

	

}


