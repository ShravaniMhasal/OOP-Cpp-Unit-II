#include <iostream>
#include <string>
#include <utility>
using namespace std;

// base class - has the stuff that EVERY vehicle needs, no matter what type
class Vehicle {
protected:
    // protected so Car and Bike can use this directly since they inherit from Vehicle
    string registrationNumber;

public:
    // constructor - sets the registration number when a Vehicle is made
    explicit Vehicle(string registration)
        : registrationNumber(move(registration)) {}

    // common function, both Car and Bike can use this as-is
    void start() const {
        cout << "Vehicle " << registrationNumber << " started\n";
    }
};

// Car inherits from Vehicle -> "a Car IS A Vehicle" + its own extra stuff (openBoot)
class Car : public Vehicle {
public:
    // constructor - just passes the registration up to Vehicle's constructor
    // Car doesn't need anything extra of its own to set up
    explicit Car(string registration) : Vehicle(move(registration)) {}

    // this function is ONLY for Car, Bike doesn't have this
    void openBoot() const {
        cout << "Car boot opened\n";
    }
};

// Bike inherits from Vehicle too -> "a Bike IS A Vehicle" + its own extra stuff (helmetReminder)
// notice both Car and Bike are separate branches coming from the SAME base class Vehicle
class Bike : public Vehicle {
public:
    // constructor - same idea, just forwards registration to Vehicle
    explicit Bike(string registration) : Vehicle(move(registration)) {}

    // this function is ONLY for Bike, Car doesn't have this
    void helmetReminder() const {
        cout << "Please wear a helmet\n";
    }
};

int main() {
    // making a Car and a Bike, both call Vehicle's constructor internally first
    Car car("MH12AB1234");
    Bike bike("MH12CD5678");

    car.start();       // inherited from Vehicle
    car.openBoot();    // Car's own function

    bike.start();          // inherited from Vehicle (same function, reused)
    bike.helmetReminder(); // Bike's own function

    return 0;
}