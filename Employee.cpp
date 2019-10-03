#include <iostream>

using namespace std;

#include "Employee.h"

Employee::Employee(const string &name,
    const string &addr,
    const string &email,
    const string &eid)
 : name(name), addr(addr), email(email), eid(eid)
{ }

const string & Employee::getName() const {
    return name;
}

const string & Employee::getAddr() const {
    return addr;
}

const string & Employee::getEmail() const {
    return email;
}

const string & Employee::getEid() const {
    return eid;
}

void Employee::setName(const string &name) {
    this->name = name;
}

void Employee::setAddr(const string &addr) {
    this->addr = addr;
}

void Employee::setEmail(const string &email) {
    this->email = email;
}

void Employee::display() const {
    cout << "Name: " << name << endl
        << "Address: " << addr << endl
        << "Email: " << email << endl
        << "EID: " << eid << endl;
}

