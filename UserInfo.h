#pragma once
#ifndef USERINFO_H
#define USERINFO_H

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
};

struct money {
    char his_username[30];
    char your_username[30];
    float HowMuchSent;
};


#endif