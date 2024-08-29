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

    Client(string name, int id, string password) : Person(name, id, password), balance(0.0) {
        saveToFile();
    }

    // Getters
    double getBalance() const {
        return balance;
    }

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


    void checkBalance() const {
        cout << "Current balance: " << balance << endl;
    }


    void transferTo(Client& recipient, double amount, const string& password) {
        if (this->password == password) {
            if (amount <= balance) {
                balance -= amount;
                recipient.deposit(amount, recipient.getPass());
                cout << "Transfer successful. New balance: " << balance << endl;
                saveToFile();  // Save to file after transfer
            } else {
                cout << "Insufficient funds for transfer." << endl;
            }
        } else {
            cout << "Incorrect password." << endl;
        }
    }

    void saveToFile() const {
        if (name.empty()) {
            cerr << "Error: Client name is empty.\n";
            return;
        }

        std::string filename = name + ".txt";
        std::ofstream outFile(filename);

        if (outFile.is_open()) {
            outFile << "Name: " << name << std::endl;
            outFile << "ID: " << id << std::endl;
            outFile << "Password: " << password << std::endl;
            outFile << "Balance: " << balance << std::endl;
            outFile.close();
        } else {
            cerr << "Error: Could not open file: " << filename << endl;
        }
    }
};

#endif // CLIENT_H
