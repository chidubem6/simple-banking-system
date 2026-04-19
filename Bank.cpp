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

Account* Bank::logIn(int accNum, const std::string& inputPin) {
    Account* account = findAccount(accNum);

    if (account != nullptr && account->verifyPin(inputPin)) {
        return account;
    }
    return nullptr;
    
}

void Bank::transfer(int senderAccNum, int receiverAccNum, double amount) {
    Account* sender = findAccount(senderAccNum);
    Account* receiver = findAccount(receiverAccNum);

    if (sender != nullptr && receiver != nullptr) {
        if (sender->withdraw(amount)) {
            receiver->deposit(amount);
            std::cout << "Transfer successful. $" << amount << " was sent to " << receiver->getName() << "\n";
        } else {
            std::cout << "Insufficient Balance";
        }
        

    } else {
        std::cout << "Transfer unsuccessful.\n" ;
    }
}

