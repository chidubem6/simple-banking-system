#include <iostream>
#include "Account.h"

int main() {
    // Create an account
    Account acc1(1, "Chidubem Okafor", "0809", 1000.00);

    std::cout << "Name: " << acc1.getName() << "\n";
    std::cout << "Account Number: " << acc1.getAccountNumber() << "\n";
    std::cout << "Balance: $" << acc1.getBalance() << "\n";

    // Deposit money
    if (acc1.deposit(500.00)) {
        std::cout << "Deposit successful of 500. New Balance: $" << acc1.getBalance() << "\n";
    } else {
        std::cout << "Deposit failed.\n";
    }

    // Withdraw money
    if (acc1.withdraw(100.00)) {
        std::cout << "Withdrawal sucessful off 100. New balance: " << acc1.getBalance() << "\n"; 
    } else {
        std::cout << "Withdrawl unsuccessful. Balance is still: " << acc1.getBalance() << "\n";
    }

    // Enter Pin
    std::string inputPin{};
    std::cout << "Enter your pin: ";
    std::cin >> inputPin; 
    
    if (acc1.verifyPin(inputPin)) {
        std::cout << "Pin entered matches!";
    } else {
        std::cout << "Incorrect pin";
    }



    return 0;
}