#include <iostream>
#include "Bank.h"

int main() {
    Bank bank;
    int choice;

    do {
        std::cout << "\n--- Banking System ---\n";
        std::cout << "1. Create Account\n";
        std::cout << "2. Login\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (choice == 1) {
            int accNum;
            std::string name, pin;
            double balance;

            std::cout << "Enter account number: ";
            std::cin >> accNum;
            std::cout << "Enter name: ";
            std::cin >> name;
            std::cout << "Enter PIN: ";
            std::cin >> pin;
            std::cout << "Enter initial balance: ";
            std::cin >> balance;

            bank.createAccount(accNum, name, pin, balance);
        }
        else if (choice == 2) {
            int accNum;
            std::string pin;

            std::cout << "Enter account number: ";
            std::cin >> accNum;
            std::cout << "Enter PIN: ";
            std::cin >> pin;

            Account* user = bank.logIn(accNum, pin);

            if (user != nullptr) {
                std::cout << "Login successful. Welcome, " << user->getName() << "\n";
            } else {
                std::cout << "Invalid login.\n";
            }
        }

    } while (choice != 3);

    return 0;
}