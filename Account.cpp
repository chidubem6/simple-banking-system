#include "Account.h"
#include <iostream>

bool Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        transactionHistory.push_back(
            Transaction("Deposit", amount, "Money deposited", balance)
        );
        return true;
    }
    return false;
}

bool Account::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        transactionHistory.push_back(
            Transaction("Withdrawal", amount, "Money withdrawn", balance)
        );

        return true;
    }
    return false;
}

void Account::addTransaction(const Transaction& transaction) {
    transactionHistory.push_back(transaction);
}

void Account::showTransactionHistory() const {
    if (transactionHistory.empty()) {
        std::cout << "No transactions have been made \n";
        return;
    }

    for (const auto& transaction : transactionHistory) {
        std::cout << transaction.toString() << std::endl;
    }
}
