#include <iostream>
#include <string>
#include <utility>
using namespace std;

//Base class(parent class)
//this has the common stuff that every employee should have
class Employee {
protected:
    //protected so that child classes (like Developer) can use "name" directly
    //if it was private, Developer wouldn't be able to touch it
    string name;
public:
    //constructor - just sets the name when we make an Employee
    explicit Employee(string employeeName) : name(move(employeeName)) {}
};
//Derived class (child class)
//Developer inherits from Employee, so it gets "name" for free
//basically saying "a Developer IS AN Employee, plus some extra stuff"
class Developer : public Employee {
private:
    //this is extra info only Developer has, Employee doesn't know about this
    string language;
public:
    //constructor - first calls Employee's constructor to set name,
    //then sets language for the Developer part
    Developer(string employeeName, string programmingLanguage)
        : Employee(move(employeeName)), language(move(programmingLanguage)) {}
    //function to print the developer's details
    void display() const {
        cout << "Developer: " << name << '\n'; //name comes from Employee class
        cout << "Language: " << language << '\n';
    }
};
int main() {
    //making a Developer object
    //this will first run Employee's constructor, then Developer's constructor
    Developer developer("Shravani", "C++");
    developer.display(); //this prints the developer's details
    return 0;
}