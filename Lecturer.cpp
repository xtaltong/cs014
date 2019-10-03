#include <iostream>
#include <iomanip>

using namespace std;

#include "Lecturer.h"

Lecturer::Lecturer(const string &name, 
    const string &addr, 
    const string &email, 
    const string &eid, 
    double courseRate, 
    double emplPerc)
 : Employee(name, addr, email, eid),
   courseRate(courseRate), emplPerc(emplPerc)
{ }

double Lecturer::getCourseRate() const {
    return courseRate;
}

double Lecturer::getEmplPerc() const {
    return emplPerc;
}

void Lecturer::setCourseRate(double courseRate) {
    this->courseRate = courseRate;
}

void Lecturer::setEmplPerc(double emplPerc) {
    this->emplPerc = emplPerc;
}

void Lecturer::display() const {
    cout << fixed << setprecision(2);    
    Employee::display();
    cout << "Course Rate: $" << courseRate << endl
        << "Empl Perc: " << emplPerc * 100 << "%" << endl;
}

double Lecturer::paycheckAmt() const {
    return courseRate * 9 / 12 * emplPerc;
}

