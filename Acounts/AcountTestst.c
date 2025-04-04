#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

#include "Acount.h"


#include"../UserInfo.h" // Its file with the struct UserInfo

void TestFileWrite() { // i did it a bit wrong i need to do the test before the program starts

	//system("cls"); // no sure


	FILE* file;
	errno_t err = fopen_s(&file, "username.txt", "rb"); // rb is read file in binary

	if (err != 0) {
		printf("File could not be opened for reading in test_file_write!\n");
		return;
	}


	struct UserInfo u; // just use union // how tf do i use union here
	size_t NumRead = fread(&u, sizeof(u), 1, file);

	if (NumRead != 1) {
		printf("Test failed: Failed to read the account from the file.\n");
		fclose(file);
		return;
	}


	FILE* originalFile;

	struct UserInfo original_u;

	errno_t err_original = fopen_s(&originalFile, "username.txt", "rb");
	if (err_original != 0) {
		printf("The file could not be opened again for reading in the second pass!\n");
		fclose(file);
		return;
	}

	size_t original_num_read = fread(&original_u, sizeof(original_u), 1, originalFile);
	if (original_num_read != 1) {
		printf("Test failed: Failed to re-read the original account data.\n");
		fclose(originalFile);
		fclose(file);
		return;
	}

	if (memcmp(&u, &original_u, sizeof(u)) != 0) { // maybe need to change "original_num_read" to "original_u"
		printf("Test failed: Account data does not match after writing and reading.\n");
		printf("The data was either incorrectly written or incorrectly read.\n");

	}
	else {
		printf("TEST ACOUNT PASSED: Account data matches after writing and reading.!!!!!\n"); // idk why it doesnt show and it doing rh acount() function ininty
	}
	
	fclose(file);
	fclose(originalFile);

	Sleep(800);
}