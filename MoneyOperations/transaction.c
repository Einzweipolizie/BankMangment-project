#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

#include "MoenyOperation.h"
#include "../Menu/menu.h"

#include"../UserInfo.h" // Its file with the struct UserInfo, money

#include "../Acounts/Acount.h"; //for gotxoy function

void transfermoney() { //you can do test whne writin detalies into money struct

	system("cls");

	
	//FILE* file;
	//FILE* MoneyOpertions;

	//struct UserInfo u;
	//struct Money m;


	char his_username[MAX];
	char your_username[MAX];
	int index;
	float sender_balance = 0.0f;
	int sender_found = 0;
	int TheAmountYouWantToSend;

	//errno_t err = fopen_s(&file, "username.txt", "rb+"); // i dont fuking know

	
	//errno_t err2 = fopen_s(&MoneyOpertions, "mon.txt", "ab");                                        // need to ask nir

	//if (err != 0) {
	//	printf("Error opening username.txt in transfermoney() with error code %d\n", err); // here the problem two
	//	
	//	return;
	//}

	//if (err2 != 0) {
	//	printf("Error opening mon.txt in transfermoney() with error code %d\n", err2);
	//	return;
	//}


	gotoxy(33, 4);
	printf("---- TRANSFER MONEY ----");
	gotoxy(33, 5);
	printf("========================");

	gotoxy(33, 11);
	printf("FROM (your username)");
	scanf_s("%s", your_username, sizeof(your_username));

	gotoxy(33, 13);
	printf("TO (username of the user you want to sent it to)");
	scanf_s("%s", his_username, sizeof(his_username));

	//rewind(file);

	//while (fread(&u, sizeof(u), 1, file)) {

	//	if (strcmp(your_username, u.username) == 0) {
	//		strcpy_s(m.your_username, sizeof(m.your_username), your_username);
	//		strcpy_s(m.his_username, sizeof(m.his_username), his_username);
	//		sender_balance = u.balance;
	//		sender_found = 1;
	//		break;
	//	}

	//}

	for(index = 0; index < MAX; index++) { // need to differnt function here
		if (Users[index].username[0] != '\0') {
			if (strcmp(Users[index].username, your_username)){
				//your_username == Mon[index].your_username;  ITS FOR LATER FOR TRANSACTIONS
				//his_username == Mon[index].his_username;   ITS FOR LATER FOR TRANSACTIONS
				sender_balance = Users[index].balance;
				sender_found = 1;
				break;
			}
		}
	}


	gotoxy(33, 16);

	if (!sender_found) {
		printf("sender not found");
		return;
	}

	printf("PRINT THE AMOUNT YOU WISH TO SENT: ");
	scanf_s("%d", &TheAmountYouWantToSend, sizeof(TheAmountYouWantToSend));
	//scanf_s("%d", &m.HowMuchSent, sizeof(m.HowMuchSent)); ITS FOR LATER FOR TRANSACTIONS
	getchar();


	if (sender_balance < TheAmountYouWantToSend) {
		printf("You don't have enough balance to transfer that amount.\n"); // i dont know why its showing that i dont have neogh money
		printf("This is the amount you have: %f", sender_balance);
		//fclose(file);
		//fclose(MoneyOpertions);
		return;
	}


	int UserFoundUpdate = 0;
	
	//rewind(file);

	//while (fread(&u, sizeof(u), 1, file)) { // its for writng teh data we got like how much teh balnce changed etc..
	//	if (!strcmp(your_username, u.username)) {
	//		u.balance -= m.HowMuchSent;

	//		long offset =  -(long)sizeof(u); // need for the size of fseek for it to go back exectly where is the infomration we need
	//		fseek(file, offset, SEEK_CUR);

	//		fwrite(&u, sizeof(u), 1, file);
	//		fflush(file);

	//		UserFoundUpdate = 1;
	//		break;
	//	}
	//}

	for (index = 0; index < MAX; index++) { // need to differnt function here
		if (strcmp(Users[index].username, your_username)) {
			Users[index].balance -= TheAmountYouWantToSend;
			UserFoundUpdate = 1;
			break;
		}
	}
	 
	
	if (!UserFoundUpdate) {
		printf("Failed to update the blance\n");
		//fclose(file);
		//fclose(MoneyOpertions);
		return;
	}

	// you can do test that will have random acount and will somthing to another acount and that will see if thats works


	//fwrite(&m, sizeof(m), 1, MoneyOpertions); //DO TEST HERE //you can do that you will sent the info of how mcuh was sent 
											// how much was is balnce do the math and then chek if the numbers are equel


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
	printf("Your balance now is: %f\n", Users[index].balance); // will it work becuse index is in for loop?
	printf("press enter if you want to continue");
	getchar();

	//fclose(file);
	//fclose(MoneyOpertions);


	
	display(your_username); // not done
	MenuChose(your_username);

}

