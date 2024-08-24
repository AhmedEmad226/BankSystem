#include <iostream>
#include <string>
using namespace std;

class Person
{
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
                recipient.deposit(amount, recipient.getPass());
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


int main() {
    // Increase the console screen width for a better view
    cout << "#     #                                                                                      ######                       " << endl;
    cout << "#  #  # ###### #       ####   ####  #    # ######    #####  ####      ####  #    # #####     #     #   ##   #    # #    # " << endl;
    cout << "#  #  # #      #      #    # #    # ##  ## #           #   #    #    #    # #    # #    #    #     #  #  #  ##   # #   #  " << endl;
    cout << "#  #  # #####  #      #      #    # # ## # #####       #   #    #    #    # #    # #    #    ######  #    # # #  # ####   " << endl;
    cout << "#  #  # #      #      #      #    # #    # #           #   #    #    #    # #    # #####     #     # ###### #  # # #  #   " << endl;
    cout << "#  #  # #      #      #    # #    # #    # #           #   #    #    #    # #    # #   #     #     # #    # #   ## #   #  " << endl;
    cout << " ## ##  ###### ######  ####   ####  #    # ######      #    ####      ####   ####  #    #    ######  #    # #    # #    # " << endl;

    cout << "\n\n\n";

    // Creating clients
    Employee emp("Ahmed", 789, "pass123", 5500);
    Client c1("Team", 123, "password"), c2("Amin", 456, "password456");
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
        }


    }


    /*
    p.displayInfo();
    q.displayInfo();

    p.deposit(1000, "password");
    p.checkBalance();

    p.transferTo(q, 500, "password");
    p.checkBalance();
    q.checkBalance();

    p.transferTo(q, 200, "wrongpassword");

    cout << "\n\n";

    cout << "Employee's Name: " << emp.getName() << endl;
    cout << "Employee's ID: " << emp.getID() << endl;
    cout << "Employee's Pass: " << emp.getPass() << endl;
    cout << "Employee's Salary: " << emp.getSalary() << endl;

    emp.loginAccount("ABC123@#$", 789);
    emp.getPaid();
    emp.getPaid();
    emp.setName("Ahmed Emad");
    emp.setPass("EFG456%^&");
    emp.displayEmployee();
    */
}
