#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

#include "Acounts/Acount.h" // Acount.h
#include "login/Login.h" //Login.h
#include "MoneyOperations/MoenyOperation.h"
#include "Menu/menu.h"
#include "HashMaps/HashMap.h"


//void acount(); // how you register to the acount // done
//void acount_created(); // after you did the acount this shows // done
//void transfermoney(); // tranfer the moeney to someone //
//void checkbalance(char*); // check your balance //
//void display(char*); // after you the chek balnce it shows you the info of your acount and it shows where you want to do after
//void login(); // done
//void loginsu(); // done 
//void logout(); // done
//int starter_menu(); // done



// for opening files need to do that creating a file and if its exeist then skip and if not create then close and then open  
// in rb mdoe or wb mode after we cheked if its exist or not

int main() { 


    LoadToArray(); // its a must from loading your acounts info that saved in file into hashmap(struck array)

    //TestLogin();  // Test if the account is written and read correctly // idk why its not working
    //AcountTest(); // test for tranfer Money working 
    //starter_menu(); // Starter Menu
    //transfermoney(); // what i am working right now after hashmpa
    
    return 0;
}

