
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

	userDB.num_users = ReadCount;



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

	size_t ReadCount_trans = fread(transDB.transactions, sizeof(struct Transaction), MAX, MoneyOpertions);

	transDB.num_transactions = ReadCount_trans;
	fclose(MoneyOpertions);

	if (ReadCount_trans > 0) {
		printf("Successfully loaded %zu transactions:\n", ReadCount_trans);
		for (size_t i = 0; i < ReadCount_trans; i++) {
			printf("- %s -> %s: %.2f\n",
				transDB.transactions[i].sender,
				transDB.transactions[i].receiver,
				transDB.transactions[i].amount);
		}
	}
	else {
		printf("Transaction file exists but contains no valid data\n");

	}

	Sleep(800);

	fclose(MoneyOpertions);

}


void LoadToFile() {
	FILE* file;



	errno_t err = fopen_s(&file, "username.txt", "wb");

	if (err != 0) { // changed to != from ==
		printf("there is an eror in opening the file in Acount tranfer File in LoadToFile function\n");
		return;
	}

	size_t written = (fwrite(Users, sizeof(struct UserInfo), userDB.num_users, file)); // i changed MAX with num_users

	if (written != userDB.num_users) {
		printf("Error: Only %zu out of %d users written.\n", written, userDB.num_users);
	}
	else {

		printf("All %d users saved successfully.\n", userDB.num_users);
	}


	fclose(file);
	printf("Users successfully written to file.\n");
	Sleep(300);

	FILE* MoneyOpertions;

	errno_t err2 = fopen_s(&MoneyOpertions, "mon.txt", "wb");

	if (err2 != 0) {
		printf("there is an eror in opening the file in Acount tranfer File in LoadToFile function in arr2\n");
		return;
	}

	if (fwrite(transDB.transactions, sizeof(Transaction), transDB.num_transactions, MoneyOpertions) == 0) {
		printf("Users transactions successfully written to file.\n");
	}




	fclose(MoneyOpertions);
	printf("Users transactions successfully written to file.\n");

}




void DeleteUser(char username[]) {

	int UserIndex = -1;
	char usernmae[MAX];


	for (int index = 0; index < userDB.num_users; index++) {
		if (strcmp(username, Users[index].username) == 0) { //userDB.users[index].username doesnt work idk why
			UserIndex = index;
			printf("User found at index %d\n", index);
			break;
		}

	}



	if (UserIndex == -1) {
		printf("the user wasnt find );\n");
		return;
	}


	for (int i = UserIndex; i < userDB.num_users - 1; i++) { // shift all users that there higher in the index onle left
		Users[i] = Users[i + 1]; // was 6 now 5

	}

	userDB.num_users--;

	int i = 0;

	while (i < transDB.num_transactions) {
		if (strcmp(transDB.transactions[i].receiver, username) == 0 || // Reciver instead of his_username
			(strcmp(transDB.transactions[i].sender, username) == 0)) { //Sender instead of your_username

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