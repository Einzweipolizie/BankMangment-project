#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>// need to do this file after transfer money file
#include <string.h>
#include <time.h>

#include "MoenyOperation.h"
#include "../Menu/Menu.h" // its fot the function that are getting called for 

#include"../UserInfo.h" // Its file with the struct UserInfo

void checkbalance(char username[]) {

	system("cls");

	float currentBalance = 0.0f;
	int userfound = -1;

	trim_whitespace(username);

	printf("Searching for: '%s'\n", username);

	printf("Loaded users (%d):\n", userDB.num_users);
	for (int i = 0; i < userDB.num_users; i++) {
		printf("- %s\n", userDB.users[i].username);
	}

	//for (int index = 0; index < userDB.num_users; index++) {
	//	if (strcmp(userDB.users[index].username, username) == 0) {
	//		currentBalance = userDB.users[index].balance;
	//		userfound = index;
	//		break;
	//	}

	//	


	//}


	for (int index = 0; index < MAX; index++) {

		if (strcmp(username, Users[index].username) == 0) {
			currentBalance = userDB.users[index].balance;
			userfound = index;
			break;
			
		}
	}


	if (userfound == -1) {
		printf("\nERROR: User not found!\n");
		printf("Loaded users (%d):\n", userDB.num_users);
		for (int i = 0; i < userDB.num_users; i++) {
			printf("- '%s'\n", userDB.users[i].username);
		}
		printf("Press Enter to continue...");
		getchar();
		return;
	}


	gotoxy(30, 1);
	printf("=== FINANCIAL SUMMARY FOR %s ===", username);
	gotoxy(30, 3);
	printf("Current Balance: %.2f", currentBalance);


	gotoxy(0, 5);
	printf("TRANSACTION HISTORY:");
	printf("\n=============================================\n");

	float TotalSent = 0.0f;
	float TotalRecived = 0.0f;
	float transactionCount = 0.0f;

	for (int i = 0; i < transDB.num_transactions; i++) {
		struct Transaction t = transDB.transactions[i];

		if (strcmp(t.receiver, username) == 0 || strcmp(t.sender, username) == 0) {
			char timebuf[20];
				struct tm* timeinfo = localtime(&t.timestamp);
				strftime(timebuf, sizeof(timebuf), "%Y-%m-%d %H:%M", timeinfo);

				if (strcmp(t.sender, username) == 0) {
					printf("[%s] Sent %.2f to %s\n", timebuf, t.amount, t.receiver);
					TotalSent += t.amount;
				}
				else {
					printf("[%s] Received %.2f from %s\n", timebuf, t.amount, t.sender);
					TotalRecived += t.amount;
				}
				transactionCount++;
		}
	}

	if (transactionCount == 0) {
		printf("\nNo transactions found.\n");
	}
	else {
		printf("\n=============================================\n");
		printf("Total Sent:     %.2f\n", TotalSent);
		printf("Total Received: %.2f\n", TotalRecived);
		printf("Net Change:     %.2f\n", (TotalRecived - TotalSent));
	}

	printf("\nPress Enter to return to menu...");
	getchar(); // Clear input buffer
	getchar(); // Wait for Enter key
	display(username);
	MenuChose(username);
}



void trim_whitespace(char* str) {
	if (!str) return;

	char* end;
	// Trim leading spaces
	while (isspace((unsigned char)*str)) str++;

	if (*str == 0) return;  // String was all spaces

	// Trim trailing spaces
	end = str + strlen(str) - 1;
	while (end > str && isspace((unsigned char)*end)) end--;

	// Null-terminate
	*(end + 1) = '\0';
}