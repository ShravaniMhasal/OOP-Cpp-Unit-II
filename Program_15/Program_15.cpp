#include <iostream>
#include <string>
#include <utility>
using namespace std;

// base class - has stuff every vehicle needs, plus common rent calculation logic
class Vehicle {
protected:
    // protected so Car and Bike (children) can use these directly
    string registrationNumber;
    double ratePerDay;

public:
    // constructor - sets registration number and rate
    Vehicle(string registration, double rate)
        : registrationNumber(move(registration)), ratePerDay(rate) {}

    // virtual because I want Bike to be able to change how rent is calculated
    // if a child class doesn't override this, it just uses this default version
    virtual double calculateRent(int days) const {
        return ratePerDay * days;
    }

    // virtual because both Car and Bike want to ADD more info on top of this
    // (not replace it completely, they still call Vehicle::display() inside their own version)
    virtual void display() const {
        cout << "Registration: " << registrationNumber << '\n';
        cout << "Rate per day: " << ratePerDay << '\n';
    }

    // virtual destructor, standard practice when using virtual functions
    virtual ~Vehicle() = default;
};

// Car inherits from Vehicle, adds its own extra detail (numberOfDoors)
class Car : public Vehicle {
private:
    int numberOfDoors;

public:
    // constructor - sends registration and rate up to Vehicle, sets doors itself
    Car(string registration, double rate, int doors)
        : Vehicle(move(registration), rate), numberOfDoors(doors) {}

    // overriding display() but NOT replacing it completely
    // first call Vehicle's version (prints registration + rate), THEN add doors info
    // this way I don't have to retype the registration/rate printing again
    void display() const override {
        Vehicle::display();
        cout << "Doors: " << numberOfDoors << '\n';
    }

    // notice: Car does NOT override calculateRent()
    // so Car just uses Vehicle's normal version automatically, no changes needed
};

// Bike inherits from Vehicle too, but this one is a bit different from Car
class Bike : public Vehicle {
private:
    int engineCapacity;

public:
    // constructor - same pattern as Car
    Bike(string registration, double rate, int capacity)
        : Vehicle(move(registration), rate), engineCapacity(capacity) {}

    // THIS time I AM overriding calculateRent()
    // bikes get a 10% discount compared to the normal rate (that's why * 0.9)
    double calculateRent(int days) const override {
        return ratePerDay * days * 0.9;
    }

    // same idea as Car's display() - reuse Vehicle::display() then add my own extra line
    void display() const override {
        Vehicle::display();
        cout << "Engine Capacity: " << engineCapacity << " cc\n";
    }
};

int main() {
    Car car("MH12AB1234", 2000.0, 5);
    Bike bike("MH12CD5678", 800.0, 150);

    cout << "Car Details\n";
    car.display();
    // Car uses Vehicle's normal calculateRent() since it didn't override it
    cout << "Rent for 3 days: " << car.calculateRent(3) << "\n\n";

    cout << "Bike Details\n";
    bike.display();
    // Bike uses ITS OWN calculateRent() since it overrode it (gets the 10% discount)
    cout << "Rent for 3 days: " << bike.calculateRent(3) << '\n';

    return 0;
}