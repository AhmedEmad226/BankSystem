#include <iostream>
#include <string>
#include "Admin.h"
#include "Client.h"
#include "Employee.h"
#include "Person.h"

using namespace std;

int main() {

    Employee emp("moaz", 1, "pass123", 5500);

    Client c1("hello", 123, "password"), c2("Amin", 456, "password456");

    Admin admin("amin", 789, "adminPass", 7500);
 int input{ 0 }, id{ 0 }, temp{ 0 };
    string pass, s;
    bool check = false;

    cout << "Welcome user, choose your account using its number\n\n1 Admin\n2 Employee\n3 Client\n\n";
    cin >> input;

    if (input == 1) {
        cout << "you are Admin";
    }

    else if (input == 2) {
        cout << "Please enter your Password & ID\n Password: ";
        cin >> pass;
        cout << "ID: ";
        cin >> id;
        emp.loginAccount(pass, id, check);

        if (check) {
            cout << "\nChoose from the methods below\n\n1 Check the salary\n2 get paid\n3 Change Name\n4 Change ID\n5 Change Password\n\n";
            cin >> input;
        }
        else if (!check) {
            cout << "\nTry again later\n";
        }


        if (input == 1) {
            cout << "Your salary is " << emp.getSalary() << endl;
        }

        else if (input == 2) {
            cout << "Loading...\n";
            emp.getPaid();
        }

        else if (input == 3) {
            cout << "your new Name: ";
            cin >> s;
            emp.setName(s);
        }

        else if (input == 4) {
            cout << "your new Id: ";
            cin >> temp;
            emp.setID(id);
        }

        else if (input == 3) {
            cout << "your new Password: ";
            cin >> s;
            emp.setPass(s);
        }

        else {
            cout << "\nWrong Input, Try again later\n";
        }

    }

    else if (input == 3) {
        cout << "Choose account:          1-" << c1.getName() << "         2-" << c2.getName() << endl;
        cin >> input;
        cout << "Please enter your Password & ID\n Password: ";
        cin >> pass;
        cout << "ID: ";
        cin >> id;

        if (input == 1) {
            c1.loginAccount(pass, id, check);
            temp = 1;
        }
        else if (input == 2) {
            c2.loginAccount(pass, id, check);
            temp = 2;
        }
        else {
            cout << "\nWrong input";
        }

        if (check) {
            cout << "\nChoose from the methods below\n\n1 Check the balance\n2 Change Name\n3 Change ID\n4 Change Password\n\n";
            cin >> input;
        }

        else {
            cout << "\nTry again later\n";
        }

        if (input == 1 && temp == 1) {
            cout << "your salary is ";
            c1.getBalance();
        }

        else if (input == 2 && temp == 1) {
            cout << "your new Name: ";
            cin >> s;
            c1.setName(s);
        }

        else if (input == 3 && temp == 1) {
            cout << "your new ID: ";
            cin >> id;
            c1.setID(id);
        }

        else if (input == 4 && temp == 1) {
            cout << "your new Password: ";
            cin >> s;
            c1.setPass(s);
        };


    return 0;
};
}
