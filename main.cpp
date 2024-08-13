#include <iostream>
#include <string>
#include <exception>
using namespace std;

class Person {          //Main Class
protected:
    string name;
    int id;
    string password;

public:
    // Constructor
    Person() {
         id = 0;
    }
    Person(string n, int i, string p) {
         id = i;
         password = p;
         name = n;
    }
    //Setters
    void SetID(int i) {
        id = i;
    }
   void setName(string n) {
         name = n;
    }
   void SetPass(string p) {
        password = p;
   }
    //   Getters

   int GetID() {
       return id;
   }
   string GetName() {
       return name;
   }
   string GetPass() {
       return password;
   }
    // Display basic info
    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
    }
};

class Client: public Person {

};

class Employee : public Person {

};

class Admin : public Person {

};
int main()
{
    Person p("Team", 123,"my passwrod");
    p.displayInfo();
}
