#ifndef BANK_H
#define BANK_H

#include <vector>
#include "Account.h"

class Bank {
    private:
        std::vector<Account> accounts;

    public:
        void createAccount(int accNum, const std::string& accName, const std::string& accPin, double accBalance);
        Account* findAccount(int accNum);
};

#endif