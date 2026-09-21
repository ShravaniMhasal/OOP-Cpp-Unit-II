#include <iostream>
#include <string>
#include <utility>
using namespace std;

// this is the "outer" class, doesn't really do much on its own here
class University {
public:
    // this is a NESTED class - a class defined INSIDE another class
    // Department only exists "inside" University's scope, kind of like
    // Department is a small part that belongs to University
    // this is NOT inheritance, University is not a parent of Department
    class Department {
    private:
        string name;

    public:
        // constructor - sets the department name
        explicit Department(string departmentName)
            : name(move(departmentName)) {}

        // prints the department name
        void display() const {
            cout << "Department: " << name << '\n';
        }
    };
};

int main() {
    // to create a Department object, I have to write University::Department
    // because Department is defined INSIDE University, so I need to
    // tell the compiler where to find it using the :: (scope resolution) operator
    University::Department department("Artificial Intelligence and Data Science");

    department.display();
    return 0;
}