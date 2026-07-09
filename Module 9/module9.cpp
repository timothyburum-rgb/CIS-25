#include <iostream>
#include <string>
using namespace std;

// Base class
class User {
public:
    string username;
    virtual void accessLevel() {
        cout << "General Access\n";
    }
};

// Derived from User
class Employee : public User {
public:
    void accessLevel() override {
        cout << "Employee Access: View inventory\n";
    }
};

// Derived from User
class Manager : public User {
public:
    void accessLevel() override {
        cout << "Manager Access: View and update inventory\n";
    }
};

// Derived from User
class Admin : public User {
public:
    void accessLevel() override {
        cout << "Admin Access: Full access: add, update, delete inventory\n";
    }
};

int main() {
    Employee emp;
    emp.accessLevel();

    Manager mgr;
    mgr.accessLevel();

    Admin adm;
    adm.accessLevel();

    return 0;
}
