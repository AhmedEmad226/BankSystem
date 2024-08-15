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
        if (name.length() >= 5 && name.length() <= 20) {
            this->name = name;
            cout << "The name has been changed Successfully\n";
        }
        else {
            cout << "The name must be between 5 ~ 20 letters\n";
        }
    }
    void SetPass(string password) {
        if (password.length() >= 8 && password.length() <= 20) {
            this->password = password;
            cout << "The Password has been changed Successfully\n";
        }
        else {
            cout << "The Password must be between 8 ~ 20 letters\n";
        }
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


class Employee : public Person {
    double salary;

public:
    // Constructors
    Employee() {
        salary = 0;
    }

    Employee(string name, int id, string password, double salary) : Person(name, id, password) {
        this->salary = salary;
        this->name = name;
        this->id = id;
        this->password = password;
    }

    // Getters

    double getSalary(){
        return salary;
    }

    // Login Method

void loginAccount(string password, int id) {

    if (this->password == password && this->id == id) {
        cout << "\nSuccessful Login\n";
    }

    else {
        cout << "\nUnsuccessful Login\n";
    }
}

    // get paid method

    void getPaid() {
        if (salary > 0) {
        cout << "\nyou got paid $" << salary << endl;
        salary = 0;
        }

        else {
            cout << "\nYou already got paid, your salary is 0\n";
        }
    }

    void displayEmployee() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Password: " << password << endl;
        cout << "Salary: " << salary << endl;
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
    Employee emp("Ahmed", 789, "ABC123@#$", 5500);


    p.displayInfo();
    q.displayInfo();


    p.deposit(1000, "password");
    p.checkBalance();

    p.transferTo(q, 500, "password");
    p.checkBalance();
    q.checkBalance();


    p.transferTo(q, 200, "wrongpassword");

    cout << "\n\n";

    cout << "Employee's Name: " << emp.GetName() << endl;
    cout << "Employee's ID: " << emp.GetID() << endl;
    cout << "Employee's Pass: " << emp.GetPass() << endl;
    cout << "Employee's Salary: " << emp.getSalary() << endl;

    emp.loginAccount("ABC123@#$", 789);
    emp.getPaid();
    emp.getPaid();
    emp.setName("Ahmed Emad");
    emp.SetPass("EFG456%^&");
    emp.displayEmployee();

}
