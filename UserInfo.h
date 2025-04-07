#pragma once


#define MAX 50


struct UserInfo { // add malloc to the size //
    char name[MAX];
    char last_name[MAX];
    char username[MAX];
    int year;
    int month;
    int day;
    float balance;
    char password[MAX];

    // maybe add here a struct Money for it to be the smae index as UserInfo?
} typedef UserInfo;

struct UserInfo Users[MAX]; // for the hashmap 

struct UserDatabase { // add here the number of users
    int num_users;
    
};

struct UserDatabase  num;



struct Money {
    char his_username[MAX];
    char your_username[MAX];
    float HowMuchSent;
};

struct Money Mon[MAX]; // hashmap for Moeny struct




