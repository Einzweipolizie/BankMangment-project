#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>// need to do this file after transfer money file
#include <string.h>

#include "MoenyOperation.h"
#include "../Menu/Menu.h" // its fot the function that are getting called for 

#include"../UserInfo.h" // Its file with the struct UserInfo

void checkbalance(char username[]) {

	system("cls");

	FILE* MoneyOpertions;

	struct UserInfo u; // i dont know it its needed

	struct money m;


	errno_t err = fopen_s(&MoneyOpertions, "money.txt", "a+b");

	int k = 5, l = 10;
	int j = 30, n = 10;
	int z = 60, v = 10;
	

	gotoxy(30, 2);
	printf("==== BALANCE DASHBOARD ====");
	gotoxy(30, 3);
	printf("***************************");
	gotoxy(k, l);
	printf("S no.");
	gotoxy(j, n);
	printf("TRANSACTION ID");
	gotoxy(z, v);
	printf("AMOUNT");

	// need to end trnafer moeny and adter that start this
}
