#pragma once
//files
#include "../login/login.h" 
//main



//acounts
void acount();
void takeInput(char* InputMsg, void* var, char* format);
void acount_created();



//TESTS
void TestFileWrite();

//Hash map and deleting
void LoadToArray();
void LoadToFile();
void DeleteUser(); // do i need to add char username[])?
