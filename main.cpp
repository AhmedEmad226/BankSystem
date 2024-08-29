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



    return 0;
}
