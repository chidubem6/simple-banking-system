#include <iostream>
#include "Account.h"
#include "Bank.h"

int main() {
    Bank bank;
    bank.createAccount(1001, "Chidubem", "1234", 500);
    
    bank.logIn(1001, "1234");

    return 0;
}