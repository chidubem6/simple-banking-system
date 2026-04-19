#include "Bank.h"

void Bank::createAccount(int accNum, const std::string& accName, const std::string& accPin, double accBalance) {
    /*if (findAccount(accNum)) {


    } else{
        accounts.push_back(Account(accNum, accName, accPin, accBalance));
    }
}; */

Account* Bank::findAccount(int accNum) {
    for (auto& account : accounts) {
        if (account.getAccountNumber() == accNum) {
            return &account;
        }
    } return nullptr;
};

