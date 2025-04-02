
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

#include "Acount.h"
#include "../login/Login.h"
#include"../UserInfo.h" // Its file with the structs defentions


void LoadToArray() {
	FILE* file;

	errno_t err = fopen_s(&file, "username.txt", "rb");

	if (err != 0) {
		printf("there is an eror in opening the file in Acount tranfer File in LoadToArray function\n");
		return;
	}

	size_t ReadCount = fread(Users, sizeof(struct UserInfo), MAX, file); // Users is struckt of arrays

	if (ReadCount == 0) {
		printf("No users read from the file\n");
	}
	else {
		printf("%zu users loaded from the file\n", ReadCount);
	}

	Sleep(1000);

	fclose(file);

}


void LoadToFile() {
	FILE* file;
	errno_t err = fopen_s(&file, "username.txt", "wb");

	if (err == 0) {
		printf("there is an eror in opening the file in Acount tranfer File in LoadToArray function\n");
		return;
	}

	size_t written = (fwrite(Users, sizeof(struct UserInfo), MAX, file) != 1);
	if (written != MAX) {
		printf("Error: Only %zu out of %d users written.\n", written, MAX);
	}
	else {
		printf("All %d users saved successfully.\n", MAX);
	}

	

	

	fclose(file);
	printf("Users successfully written to file.\n");

}