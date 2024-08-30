#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"
#include <iostream>
#include <fstream>
#include <vector>


class Employee : public Person {
private:
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
    double getSalary() const { return salary; }

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

    // Display employee details
    void displayEmployee() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Password: " << password << endl;
        cout << "Salary: " << salary << endl;
    }

    // Save employee data to file
    void saveToFile() const {
        string filename = name + ".txt";
        ofstream outFile(filename);

        if (outFile.is_open()) {
            outFile << "Name: " << name << endl;
            outFile << "ID: " << id << endl;
            outFile << "Password: " << password << endl;
            outFile << "Salary: " << salary << endl;
            outFile.close();
        } else {
            cerr << "Error: Could not create file: " << filename << endl;
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
            if (client.getID() == id) {
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
            cout << "Name: " << client.getName() << endl;
            cout << "ID: " << client.getID() << endl;
            cout << "Balance: " << client.getBalance() << endl;
            cout << "-------------------------\n";
        }
    }

    // Method to edit a client's information
    void editClient(int id, const string& name, const string& password, double balance) {
        Client* client = searchClient(id);
        if (client) {
            client->setName(name);
            client->setPassword(password);
            double balanceDiff = balance - client->getBalance();
            if (balanceDiff > 0) {
                client->deposit(balanceDiff, password);
            } else if (balanceDiff < 0) {
                client->withdraw(-balanceDiff, password);
            }
            client->saveToFile();
            cout << "Client details updated successfully.\n";
        } else {
            cout << "Client not found.\n";
        }
    }
};
#endif // EMPLOYEE_H
