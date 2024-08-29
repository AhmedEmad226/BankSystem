#ifndef CLIENT_H
#define CLIENT_H

#include "Person.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Client : public Person {
private:
    double balance;

public:
    // Constructors
    Client() : Person(), balance(0.0) {}

    Client(string name, int id, string password)
        : Person(name, id, password), balance(0.0) {
        saveToFile();
    }

    // Getters
    double getBalance() const { return balance; }

    // Deposit method
    void deposit(double amount, const string& password) {
        if (this->password == password) {
            if (amount > 0) {
                balance += amount;
                cout << "Deposit successful. New balance: " << balance << endl;
                saveToFile();
            } else {
                cout << "Invalid deposit amount." << endl;
            }
        } else {
            cout << "Incorrect password." << endl;
        }
    }

    // Withdraw method
    void withdraw(double amount, const string& password) {
        if (this->password == password) {
            if (amount <= balance) {
                balance -= amount;
                cout << "Withdrawal successful. New balance: " << balance << endl;
                saveToFile();
            } else {
                cout << "Insufficient funds." << endl;
            }
        } else {
            cout << "Incorrect password." << endl;
        }
    }

    // Check balance method
    void checkBalance() const {
        cout << "Current balance: " << balance << endl;
    }

    // Transfer method
    void transferTo(Client& recipient, double amount, const string& password) {
        if (this->password == password) {
            if (amount <= balance) {
                balance -= amount;
                recipient.deposit(amount, recipient.password());
                cout << "Transfer successful. New balance: " << balance << endl;
                saveToFile();
            } else {
                cout << "Insufficient funds for transfer." << endl;
            }
        } else {
            cout << "Incorrect password." << endl;
        }
    }

    // Save client data to file
    void saveToFile() const {
        if (name.empty()) {
            cerr << "Error: Client name is empty.\n";
            return;
        }

        string filename = name + ".txt";
        ofstream outFile(filename);

        if (outFile.is_open()) {
            outFile << "Name: " << name << endl;
            outFile << "ID: " << id << endl;
            outFile << "Password: " << password << endl;
            outFile << "Balance: " << balance << endl;
            outFile.close();
        } else {
            cerr << "Error: Could not open file: " << filename << endl;
        }
    }
};

#endif // CLIENT_H
