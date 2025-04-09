
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

#include "Acount.h"
#include "../login/Login.h"
#include"../UserInfo.h" // Its file with the structs defentions

struct UserDatabase userDB = { .num_users = 0 };
struct TransactionDatabase transDB = { .num_transactions = 0 };

void LoadToArray() {
	FILE* file;

	
	errno_t err = fopen_s(&file, "username.txt", "rb");

	if (err != 0) {
		printf("there is an eror in opening the file in Acount tranfer File in LoadToArray function in arr1\n");
		return;
	}

	size_t ReadCount = fread(Users, sizeof(struct UserInfo), MAX, file); // Users is struckt of arrays // i changed MAX with num_users

	num.num_users = ReadCount;

	if (ReadCount == 0) {
		printf("No users read from the file\n");
	}
	else {
		printf("%zu users loaded from the file\n", ReadCount);
	}

	fclose(file);
	FILE* MoneyOpertions;

	errno_t err2 = fopen_s(&MoneyOpertions, "mon.txt", "rb");

	if (err2 != 0) {
		printf("there is an eror in opening the file in Acount tranfer File in LoadToArray function in arr2\n");
		return;
	}

	// ask nir if i can use 2 ReadCount in ont program

	size_t ReadCount_mon = fread(Mon, sizeof(struct Money), MAX, MoneyOpertions);

	if (ReadCount_mon == 0) {
		printf("no info of money in the file\n");
	}
	else {
		printf("%zu data of users transactions was loaded\n", ReadCount_mon);
	}

	Sleep(700);

	fclose(MoneyOpertions);

}


void LoadToFile() {
	FILE* file;



	errno_t err = fopen_s(&file, "username.txt", "wb");

	if (err != 0) { // changed to != from ==
		printf("there is an eror in opening the file in Acount tranfer File in LoadToFile function\n");
		return;
	}

	size_t written = (fwrite(Users, sizeof(struct UserInfo), num.num_users, file)); // i changed MAX with num_users

	if (written != num.num_users) {
		printf("Error: Only %zu out of %d users written.\n", written, num.num_users);
	}
	else {

		printf("All %d users saved successfully.\n", num.num_users);
	}


	fclose(file);
	printf("Users successfully written to file.\n");
	Sleep(2000);

	FILE* MoneyOpertions;

	errno_t err2 = fopen_s(&MoneyOpertions, "mon.txt", "wb");

	if (err2 != 0) {
		printf("there is an eror in opening the file in Acount tranfer File in LoadToFile function in arr2\n");
		return;
	}

	size_t written_mon = (fwrite(Mon, sizeof(struct Money), num.num_users, MoneyOpertions) );
	if (written_mon != num.num_users) {
		printf("Error: Only %zu out of %d users written.\n", written_mon, num.num_users);
	}
	else {
		printf("All %d users saved successfully.\n", num.num_users);
	}

	fclose(MoneyOpertions);
	printf("Users successfully written to file.\n");

}




void DeleteUser(char username[]) {

	int UserIndex = -1;
	for (int i = 0; i < userDB.num_users; i++) {
		if (strcmp(userDB.users[i].username, username) == 0) {
			printf("User found at index %d\n", i);
			Sleep(5000);
			UserIndex = i;
			break;

		}
	}
	char usernmae[MAX];

	//printf("GIVE ME USERNMAE YOU WANT TO DELETE");
	//scanf_s("%s", usernmae, sizeof(usernmae));
	for (int index = 0; index < MAX; index++) {
		if (strcmp(username, Users[index].username) == 0);
		UserIndex = index;
	}



	if (UserIndex == -1) {
		printf("the user wasnt find );\n");
		return;
	}


	for (int i = UserIndex; i < userDB.num_users - 1; i++) { // shift all users that there higher in the index onle left
		userDB.users[i] = userDB.users[i + 1]; // was 6 now 5

	}

	userDB.num_users--;

	int i = 0;

	while (i < transDB.num_transactions) {
		if (strcmp(transDB.transactions[i].his_username, username) == 0 ||
			(strcmp(transDB.transactions[i].your_username, username) == 0)) {

			for (int j = i; j < transDB.num_transactions - 1; j++) {
				transDB.transactions[j] = transDB.transactions[j + 1];
			}
			transDB.num_transactions--;
		}
		else {
			i++;
		}

	}

	printf("user '%s' and all related transaction deleted.\n", username);


}