#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>

class Account {
    private:
        int accountNumber{};
        std::string name{};
        std::string pin{};
        double balance{};
    
    public:
        // Constructor
        Account(int accNum, const std::string& accName, const std::string& accPin, double accBalance)
            : accountNumber{ accNum }, name{ accName }, pin{ accPin }, balance{ accBalance } {}

        // Methods
        int getAccountNumber() const { return accountNumber; }
        const std::string& getName() const { return name; }
        double getBalance() const { return balance; }

        bool verifyPin(const std::string& inputPin) const { return inputPin == pin; }

        bool deposit(double amount);
        bool withdraw(double amount);
    
};
#endif