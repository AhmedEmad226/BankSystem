#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"
#include <iostream>
#include <fstream>
#include <vector>

class Employee : public Person {
    double salary;

public:
    // Constructors
    Employee() : salary(0) {}

    Employee(std::string name, int id, std::string password, double salary) : Person(name, id, password), salary(salary) {
        saveToFile();
    }

    // Getters
    double getSalary() const {
        return salary;
    }

    // Method to get paid
    void getPaid() {
        if (salary > 0) {
            std::cout << "\nYou got paid $" << salary << std::endl;
            salary = 0;
            saveToFile();
        } else {
            std::cout << "\nYou already got paid, your salary is 0\n";
        }
    }

    void displayEmployee() const {
        std::cout << "Name: " << name << std::endl;
        std::cout << "ID: " << id << std::endl;
        std::cout << "Password: " << password << std::endl;
        std::cout << "Salary: " << salary << std::endl;
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

#endif // EMPLOYEE_H
