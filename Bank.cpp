#include <iostream>
#include <fstream>
#include <sstream>
#include "Bank.h"
#include "Transaction.h"

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
        if (sender->getBalance() >= amount) {
            sender->setBalance(sender->getBalance() - amount);
            receiver->setBalance(receiver->getBalance() + amount);
            sender->addTransaction(Transaction("Transfer Out", amount, "Sent to " + receiver->getName(), sender->getBalance()));
            receiver->addTransaction(Transaction("Transfer In", amount, "Received from " + sender->getName(), receiver->getBalance()));
            std::cout << "Transfer successful. $" << amount << " was sent to " << receiver->getName() << "\n";
        } else {
            std::cout << "Insufficient Balance\n";
        }
        

    } else {
        std::cout << "Transfer unsuccessful.\n" ;
    }
}

void Bank::saveToFile(const std::string& filename) {
    // Implementation for saving accounts and transactions to a file
    std::ofstream file(filename);

    if (!file) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }

    for (const auto& account : accounts) {
        file << account.getAccountNumber() << "," 
        << account.getName() << "," 
        << account.getPin() << "," 
        << account.getBalance() 
        << "\n";
    }

    file.close();
}

void Bank::loadFromFile(const std::string& filename) {
    // Implementation for loading accounts and transactions from a file
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Error opening file for reading: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::string accNum, name, pin, balance;

        std::istringstream accountLine(line);
        
        std::getline(accountLine, accNum, ',');
        std::getline(accountLine, name, ',');
        std::getline(accountLine, pin, ',');
        std::getline(accountLine, balance, ',');

        createAccount(std::stoi(accNum), name, pin, std::stod(balance));
    }
    file.close();
}
