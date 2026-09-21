#include <iostream>
#include <string>
#include <utility>
using namespace std;

// this is the topmost base class, most general one
// everyone (Employee, Manager) will eventually get "name" from here
class Person {
protected:
    // protected so that child classes can use "name" directly
    // if I made it private, Employee and Manager wouldn't be able to touch it
    string name;

public:
    // constructor - runs when a Person object is made, just sets the name
    explicit Person(string personName) : name(move(personName)) {}

    // function to print name, any child class can call this
    void showPerson() const {
        cout << "Name: " << name << '\n';
    }
};

// Employee inherits from Person -> so "an Employee IS A Person" + extra stuff (id)
class Employee : public Person {
protected:
    // protected here too, so that Manager (which inherits from Employee) can use it
    int employeeId;

public:
    // constructor - first sets up the Person part (name), then sets employeeId
    Employee(string employeeName, int id)
        : Person(move(employeeName)), employeeId(id) {}

    // prints employee id
    void showEmployee() const {
        cout << "Employee ID: " << employeeId << '\n';
    }
};

// Manager inherits from Employee -> so "a Manager IS AN Employee" + extra stuff (teamSize)
// this makes it a multi-level inheritance chain: Person -> Employee -> Manager
class Manager : public Employee {
private:
    // private because only Manager needs this, no other class needs to touch teamSize
    int teamSize;

public:
    // constructor - calls Employee's constructor first (which itself calls Person's constructor)
    // then sets teamSize for Manager
    Manager(string managerName, int id, int size)
        : Employee(move(managerName), id), teamSize(size) {}

    // this function shows everything - name from Person, id from Employee, and teamSize from itself
    void showManager() const {
        showPerson();   // inherited all the way from Person
        showEmployee(); // inherited from Employee
        cout << "Team Size: " << teamSize << '\n'; // Manager's own data
    }
};

int main() {
    // making a Manager triggers the whole chain:
    // Person's constructor runs first, then Employee's, then Manager's
    Manager manager("shravani", 987, 8);
    manager.showManager();
    return 0;
}