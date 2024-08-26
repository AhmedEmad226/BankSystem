#ifndef PERSON_H
#define PERSON_H
#include <iostream>
using namespace std;
//WE Must put the Person here
class Person{
protected:
    string name;
    int id;
    string password;

public:
    // Constructor
    Person() : id(0) {}

    Person(string name, int id, string password) : name(name), id(id), password(password) {}

    // Setters
    void setID(int id) {
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
    void setPass(string password) {
        if (password.length() >= 8 && password.length() <= 20) {
            this->password = password;
            cout << "The Password has been changed Successfully\n";
        }
        else {
            cout << "The Password must be between 8 ~ 20 letters\n";
        }
    }

    // Getters
    int getID() const {
        return id;
    }
    string getName() const {
        return name;
    }
    string getPass() const {
        return password;
    }

    void loginAccount(string password, int id, bool& check) {
        if (this->password == password && this->id == id) {
            check = true;
            cout << "\nSuccessful Login\n";
        }
        else {
            check = false;
            cout << "\nUnsuccessful Login\n";
        }
    }

    // Display basic info
    void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
    }
};

#endif // PERSON_H
