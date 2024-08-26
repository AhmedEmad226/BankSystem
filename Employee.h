#ifndef EMPLOYEE _H
#define EMPLOYEE _H
#include "Person.h"
#include<iostream>

class Employee : public Person {
    double salary;

public:
    // Constructors
    Employee() {
        salary = 0;
    }

    Employee(string name, int id, string password, double salary) : Person(name, id, password) {
        this->salary = salary;
    }

    // Getters
    double getSalary() {
        return salary;
    }



    // get paid method
    void getPaid() {
        if (salary > 0) {
            cout << "\nYou got paid $" << salary << endl;
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
#endif // EMPLOYEE _H
