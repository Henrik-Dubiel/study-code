#include <iostream>
#include <string>

class BankAccount {
private:
    std::string owner;
    double balance;

public:
    // Problem: 'balance' would be uninitialized at the beginning of the program.
    // That would lead to undefined behavior when using it.
    // Solution: initialize it to 0.0 in the constructor.
    BankAccount() {
        balance = 0.0;
    }

    void setOwner(const std::string& name) {
        owner = name;
    }

    std::string getOwner() {
        return owner;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        } else {
            std::cout << "Invalid deposit amount!" << std::endl;
        }
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            std::cout << "Invalid withdrawal amount!" << std::endl;
        } else if (balance >= amount) {
            balance -= amount;
        } else {
            std::cout << "Insufficient funds!" << std::endl;
        }
    }

    double getBalance();

    std::string getAccountInfo();
};

double BankAccount::getBalance() {
    return balance;
}

std::string BankAccount::getAccountInfo() {
    return "Owner: " + owner + ", Balance: " + std::to_string(balance);
}

int main() {
    BankAccount account;
    std::string name;

    std::cout << "Enter account owner's name: ";
    std::getline(std::cin, name);
    account.setOwner(name);

    account.deposit(1000);
    std::cout << account.getAccountInfo() << std::endl;

    account.withdraw(500);
    std::cout << account.getAccountInfo() << std::endl;

    account.withdraw(600);
    std::cout << account.getAccountInfo() << std::endl;

    return 0;
}