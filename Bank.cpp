#include <iostream>
#include "Bank.h"

void Bank::createAccount(int accNum, const std::string& accName, const std::string& accPin, double accBalance) {
    if (findAccount(accNum)) {
        std::cout << "Create account unsuccessful. Account already exists." << "\n";

    } else {
        accounts.push_back(Account(accNum, accName, accPin, accBalance));
        std::cout << "Account creation sucessful." << "\n";
    }
};

Account* Bank::findAccount(int accNum) {
    for (auto& account : accounts) {
        if (account.getAccountNumber() == accNum) {
            return &account;
        }
    } return nullptr;
};

void Bank::logIn(int accNum, const std::string& inputPin) {
    Account* account = findAccount(accNum);

    if (account != nullptr && account->verifyPin(inputPin)) {
        std::cout << "Successful login. Pin matches." << "\n";
        std::cout << "Welcome, " << account->getName()  << "\n";
    } else {
        std::cout << "Unsuccessful login.";
    }

}

