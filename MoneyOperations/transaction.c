#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

#include "MoenyOperation.h"
#include "../Menu/menu.h"

#include"../UserInfo.h" // Its file with the struct UserInfo, money

#include "../Acounts/Acount.h"; //for gotxoy function

void transfermoney(char SenderUsername[]) { //you can do test whne writin detalies into money struct

	system("cls");

	


	char his_username[MAX];
	int index;
	float sender_balance = 0.0f;
	int sender_found = 0;
	int TheAmountYouWantToSend;



	gotoxy(33, 4);
	printf("---- TRANSFER MONEY ----");
	gotoxy(33, 5);
	printf("========================");


	gotoxy(33, 13);
	printf("TO (username of the user you want to sent it to)");
	scanf_s("%s", his_username, sizeof(his_username));



	//for(index = 0; index < MAX; index++) { // need to differnt function here // i am changin and already gining the username
	//	if (Users[index].username[0] != '\0') { // so it may not bee needed
	//		if (strcmp(Users[index].username, SenderUsername) ){
	//			//your_username == Mon[index].your_username;  ITS FOR LATER FOR TRANSACTIONS
	//			//his_username == Mon[index].his_username;   ITS FOR LATER FOR TRANSACTIONS
	//			sender_balance = Users[index].balance;
	//			sender_found = 1;
	//			break;
	//		}
	//	}
	//}


	gotoxy(33, 16);

	printf("PRINT THE AMOUNT YOU WISH TO SENT: ");
	scanf_s("%d", &TheAmountYouWantToSend, sizeof(TheAmountYouWantToSend));
	//scanf_s("%d", &m.HowMuchSent, sizeof(m.HowMuchSent)); ITS FOR LATER FOR TRANSACTIONS
	getchar();



	int SenderIndex = -1;
	int WhoToSentIndex = -1;

	for (int i = 0; i < MAX; i++) {
		if (strcmp(Users[i].username, SenderUsername) == 0) {
			SenderIndex = i;
		}
		if (strcmp(Users[i].username, his_username) == 0) {
			WhoToSentIndex = i;
		}
	}


	if (SenderIndex == -1 || WhoToSentIndex == -1) {
		printf("Invalid sender/recipient.\n");
		return;
	}

	if (Users[SenderIndex].balance < TheAmountYouWantToSend) {
		gotoxy(0, 26);
		printf("there is infunient funds in your acount ): (poor)\n");
		printf("press Enter if you want to continue");
		getchar();
		display(SenderUsername);
		MenuChose(SenderUsername);
		return;
	}

	if (Users[SenderIndex].balance >= TheAmountYouWantToSend) {
		Users[SenderIndex].balance -= TheAmountYouWantToSend;
		Users[WhoToSentIndex].balance += TheAmountYouWantToSend;
		printf("The transfer was completed successfuly");
	}

	


	gotoxy(0, 26);
	printf(
		"--------------------------------------------------"
		"--------------------------------------------");

	gotoxy(0, 28);
	printf(
		"--------------------------------------------------"
		"--------------------------------------------");

	gotoxy(0, 29);
	printf("transferring amount, Please wait..");


	for (int i = 0; i < 5; i++) {
		printf("\n");
		for (int z = 0; z < 10; z++) {
			printf("*");
			Sleep(30);
		}
	}

	gotoxy(33, 40);
	printf("AMOUNT SUCCESSFULLY TRANSFERRED....\n");
	printf("Your balance now is: %f\n", Users[SenderIndex].balance); // will it work becuse index is in for loop?
	printf("press Enter if you want to continue");
	getchar();


	LoadToFile();
	
	display(SenderUsername); 
	MenuChose(SenderUsername);

}

