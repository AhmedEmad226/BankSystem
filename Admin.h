#ifndef ADMIN_H
#define ADMIN_H
#include"Person.h"
#include <string>
using namespace std;
#include <iostream>

class Admin : public Person {

    double salary;

public:
    // Constructors
    Admin() {
        salary = 0;
    }


    Admin(string name, int id, string password, double salary) : Person(name, id, password) {
        this->salary = salary;
        this->name = name;
        this->id = id;
        this->password = password;
    }
    // Getters

    double getSalary() {
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

    void displayAdmin() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Password: " << password << endl;
        cout << "Salary: " << salary << endl;
    }
};

#endif // ADMIN_H
