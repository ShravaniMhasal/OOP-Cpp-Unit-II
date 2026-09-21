#include <iostream>
#include <string>
#include <utility>
using namespace std;

// abstract base class - can't make an Employee object directly
// because calculateSalary() is pure virtual (= 0)
class Employee {
protected:
    // protected so PermanentEmployee and ContractEmployee can use these directly
    int employeeId;
    string name;

public:
    // constructor - sets common details every employee has
    Employee(int id, string employeeName)
        : employeeId(id), name(move(employeeName)) {}

    // pure virtual function - no body here, every child class MUST write its own version
    // this makes total sense because permanent and contract employees get paid differently
    virtual double calculateSalary() const = 0;

    // this one is NOT pure virtual, it's a normal function
    // both child classes can just use this as-is, no need to override it
    void displayBasicDetails() const {
        cout << "Employee ID: " << employeeId << '\n';
        cout << "Name: " << name << '\n';
    }

    // virtual destructor, needed since we're using this class polymorphically
    virtual ~Employee() = default;
};

// PermanentEmployee inherits from Employee, MUST implement calculateSalary()
class PermanentEmployee : public Employee {
private:
    double basicSalary;
    double allowance;

public:
    // constructor - sends id and name up to Employee, sets its own salary details
    PermanentEmployee(int id, string employeeName, double basic, double extra)
        : Employee(id, move(employeeName)), basicSalary(basic), allowance(extra) {}

    // permanent employee salary = basic + allowance, simple fixed formula
    double calculateSalary() const override {
        return basicSalary + allowance;
    }
};

// ContractEmployee inherits from Employee too, but salary logic is COMPLETELY different
class ContractEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;

public:
    // constructor - same pattern, sends id/name to Employee, sets its own rate/hours
    ContractEmployee(int id, string employeeName, double rate, int hours)
        : Employee(id, move(employeeName)), hourlyRate(rate), hoursWorked(hours) {}

    // contract employee salary = rate * hours worked, totally different formula
    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }
};

// this function takes ANY kind of Employee (Permanent or Contract) using a reference
// this works because of polymorphism - even though the parameter type is just "Employee",
// it automatically calls the RIGHT calculateSalary() depending on what object is actually passed
void displayPaySlip(const Employee& employee) {
    employee.displayBasicDetails();
    cout << "Salary: " << employee.calculateSalary() << "\n\n";
}

int main() {
    PermanentEmployee permanentEmployee(101, "Asha", 40000.0, 8000.0);
    ContractEmployee contractEmployee(102, "Vikas", 500.0, 80);

    // passing different object types to the SAME function
    // displayPaySlip doesn't care which one it is, it just works because of polymorphism
    displayPaySlip(permanentEmployee);
    displayPaySlip(contractEmployee);

    return 0;
}