#ifndef ADMIN_H
#define ADMIN_H

#include "Person.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Admin : public Person {
private:
    double salary;

public:
    Admin() : salary(0.0) {}

    Admin(string name, int id, string password, double salary)
        : Person(name, id, password), salary(salary) {
        saveToFile();
    }

    double getSalary() const {
        return salary;
    }

    void loginAccount(string password, int id) {
        if (this->password == password && this->id == id) {
            cout << "\nSuccessful Login\n";
        } else {
            cout << "\nUnsuccessful Login\n";
        }
    }

    void getPaid() {
        if (salary > 0) {
            cout << "\nYou got paid $" << salary << endl;
            salary = 0;
            saveToFile();
        } else {
            cout << "\nYou already got paid, your salary is 0\n";
        }
    }

    void displayAdmin() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Password: " << password << endl;
        cout << "Salary: " << salary << endl;
    }

    void saveToFile() const {
        std::string filename = name + ".txt";
        std::ofstream outFile(filename);

        if (outFile.is_open()) {
            outFile << "Name: " << name << std::endl;
            outFile << "ID: " << id << std::endl;
            outFile << "Password: " << password << std::endl;
            outFile << "Salary: " << salary << std::endl;
            outFile.close();
        } else {
            std::cout << "Error: Could not create file: " << filename << std::endl;
        }
    }
};

#endif // ADMIN_H
