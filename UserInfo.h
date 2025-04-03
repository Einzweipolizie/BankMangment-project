#pragma once


#define MAX 50


struct UserInfo {
    char name[MAX];
    char last_name[MAX];
    char username[MAX];
    int year;
    int month;
    int day;
    float balance;
    char password[MAX];

    // maybe add here a struct Money for it to be the smae index as UserInfo?
};

struct UserInfo Users[MAX]; // for the hashmap 



struct Money {
    char his_username[MAX];
    char your_username[MAX];
    float HowMuchSent;
};

struct Money Mon[MAX]; // hashmap for Moeny struct

