
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

	errno_t err = fopen_s(&file, "username.txt", "wb");

	if (!err) {
		printf("there is an eror in opening the file in Acount tranfer File in LoadToArray function\n");
		return;
	}

	size_t ReadCount = fread(Users, sizeof(struct UserInfo), 1, file); // Users is struckt of arrays

	if (ReadCount == 0) {
		printf("there is a problem in read a file or eror in AcountTransfer in LoadToArrat function in size_t\n");
	}
	else {
		printf("%zu users loaded from the file\n");
	}

	fclose(file);

}


void LoadToFile() {
	FILE* file;
	errno_t err = fopen_s(&file, "username.txt", "ab");

	if (err == 0) {
		printf("there is an eror in opening the file in Acount tranfer File in LoadToArray function\n");
		return;
	}

	if (fwrite(Users, sizeof(struct UserInfo), MAX, file) != 1) {
		printf("Error writing to file\n");
		fclose(file);
		return;
	}

	fclose(file);
	printf("Users successfully written to file.\n");

}