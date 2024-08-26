#ifndef CLIENT_H
#define CLIENT_H
#include "Person.h"
using namespace std;
#include<iostream>

class Client : public Person {
private:
    double balance;

public:
    // Constructor
    Client() : Person(), balance(0.0) {}

    Client(string name, int id, string password) : Person(name, id, password), balance(0.0) {}

    // Getters
    double getBalance() const {
        return balance;
    }

    // Method to deposit money with password check
    void deposit(double amount, const string& password) {
        if (this->password == password) {
            if (amount > 0) {
                balance += amount;
                cout << "Deposit successful. New balance: " << balance << endl;
            }
            else {
                cout << "Invalid deposit amount." << endl;
            }
        }
        else {
            cout << "Incorrect password." << endl;
        }
    }

    // Method to withdraw money with password check
    void withdraw(double amount, const string& password) {
        if (this->password == password) {
            if (amount <= balance) {
                balance -= amount;
                cout << "Withdrawal successful. New balance: " << balance << endl;
            }
            else if (amount >= balance) {
                cout << "Insufficient funds." << endl;
            }
        }
        else {
            cout << "Incorrect password." << endl;
        }
    }

    // Method to check balance
    void checkBalance() const {
        cout << "Current balance: " << balance << endl;
    }

    // Method to transfer money to another client with password check
    void transferTo(Client& recipient, double amount, const string& password) {
        if (this->password == password) {
            if (amount <= balance) {
                balance -= amount;
                recipient.deposit(amount, recipient.getPass());
                cout << "Transfer successful. New balance: " << balance << endl;
            }
            else {
                cout << "Insufficient funds for transfer." << endl;
            }
        }
        else {
            cout << "Incorrect password." << endl;
        }
    }
};


#endif // CLIENT_H
