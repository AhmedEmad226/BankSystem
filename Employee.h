#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"
#include <iostream>
#include <fstream>
#include <vector>

class Employee : public Person {
    double salary;
    vector<Client> clients;  // Collection to store clients

public:
    // Constructors
    Employee() : salary(0) {}

    Employee(string name, int id, string password, double salary)
        : Person(name, id, password), salary(salary) {
        saveToFile();
    }

    // Getters
    double getSalary() const {
        return salary;
    }

    // Method to get paid
    void getPaid() {
        if (salary > 0) {
            cout << "\nYou got paid $" << salary << endl;
            salary = 0;
            saveToFile();
        } else {
            cout << "\nYou already got paid, your salary is 0\n";
        }
    }

    void displayEmployee() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Password: " << password << endl;
        cout << "Salary: " << salary << endl;
    }

    void saveToFile() const {
        string filename = name + ".txt";
        ofstream outFile(filename);

        if (outFile.is_open()) {
            outFile << "Name: " << name << endl;
            outFile << "ID: " << id <<endl;
            outFile << "Password: " << password << endl;
            outFile << "Salary: " << salary << endl;
            outFile.close();
        } else {
            cout << "Error: Could not create file: " << filename <<endl;
        }
    }

    // Method to add a client
    void addClient(Client& client) {
        clients.push_back(client);
        cout << "Client added successfully.\n";
    }

    // Method to search for a client by ID
    Client* searchClient(int id) {
        for (auto& client : clients) {
            if (client.getId() == id) {
                return &client;
            }
        }
        cout << "Client not found.\n";
        return nullptr;
    }

    // Method to list all clients
    void listClient() const {
        if (clients.empty()) {
            cout << "No clients available.\n";
            return;
        }

        for (const auto& client : clients) {
            cout << "Name: " << client.getName() << std::endl;
            cout << "ID: " << client.getId() << std::endl;
            cout << "Balance: " << client.getBalance() << std::endl;
            cout << "-------------------------\n";
        }
    }

    // Method to edit a client's information
    void editClient(int id, std::string name, std::string password, double balance) {
        Client* client = searchClient(id);
        if (client) {
            client->setName(name);
            client->setPassword(password);
            client->deposit(balance - client->getBalance(), client->getPassword()); // Adjust balance
            client->saveToFile();
            cout << "Client details updated successfully.\n";
        } else {
            cout << "Client not found.\n";
        }
    }
};
#endif // EMPLOYEE_H
