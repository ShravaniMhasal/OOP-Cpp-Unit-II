#include <iostream>
#include <string>
#include <utility>
using namespace std;

// base class - top of the "diamond" shape (explained below)
class Person {
protected:
    string name;

public:
    explicit Person(string personName) : name(move(personName)) {}

    void displayName() const {
        cout << "Name: " << name << '\n';
    }
};

// Student inherits from Person, but notice the "virtual" keyword here
// this is called VIRTUAL INHERITANCE - I'm using this to avoid a problem
// that happens later (called the "diamond problem", explained in TeachingAssistant)
class Student : virtual public Person {
public:
    // giving a default name for now since Student alone doesn't take a name parameter
    Student() : Person("Unknown") {}
};

// Employee ALSO inherits from Person virtually, same reason as Student
class Employee : virtual public Person {
public:
    Employee() : Person("Unknown") {}
};

// this is where it gets interesting - TeachingAssistant inherits from
// BOTH Student and Employee, and BOTH of them inherit from Person
// so without "virtual" above, TeachingAssistant would end up with
// TWO separate copies of Person (one via Student, one via Employee) - that's the "diamond problem"
// using virtual inheritance makes sure there's only ONE shared copy of Person
class TeachingAssistant : public Student, public Employee {
public:
    // even though Person is technically "2 levels up", because of virtual inheritance
    // I can (and MUST) initialize Person directly right here myself
    // if I don't do this, compiler will get confused about which path to use for Person
    explicit TeachingAssistant(string assistantName)
        : Person(move(assistantName)), Student(), Employee() {}
};

int main() {
    // this only creates ONE "name" inside, thanks to virtual inheritance
    TeachingAssistant assistant("Riya");

    // works fine and prints "Riya", no ambiguity about which Person's name to use
    assistant.displayName();

    return 0;
}