#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int id;
    string password;

public:
    // Constructor
    Person() : id(0) {}

    Person(string name, int id, string password) : name(name), id(id), password(password) {}

    // Setters
    void SetID(int id) {
        this->id = id;
    }
    void setName(string name) {
        this->name = name;
    }
    void SetPass(string password) {
        this->password = password;
    }

    // Getters
    int GetID() const {
        return id;
    }
    string GetName() const {
        return name;
    }
    string GetPass() const {
        return password;
    }

    // Display basic info
    void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
    }
};

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
            else {
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
                recipient.deposit(amount, recipient.GetPass());
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

int main() {
    // Creating clients
    Client p("Team", 123, "password");
    Client q("Amin", 456, "password456");


    p.displayInfo();
    q.displayInfo();


    p.deposit(1000, "password");
    p.checkBalance();

    p.transferTo(q, 500, "password");
    p.checkBalance();
    q.checkBalance();


    p.transferTo(q, 200, "wrongpassword");


}
