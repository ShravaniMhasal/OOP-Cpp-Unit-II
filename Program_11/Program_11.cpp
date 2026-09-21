#include <iostream>
using namespace std;

// base class - but this one is special, it's an ABSTRACT class
class Shape {
public:
    // "= 0" at the end makes this a PURE virtual function
    // this means Shape doesn't define HOW area() works, it just says
    // "every shape that inherits from me MUST provide their own area() function"
    virtual double area() const = 0;

    // virtual destructor, good practice whenever we have virtual functions
    virtual ~Shape() = default;
};

// Rectangle inherits from Shape and MUST implement area() since it's pure virtual
class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    // constructor - sets both length and width
    Rectangle(double givenLength, double givenWidth)
        : length(givenLength), width(givenWidth) {}

    // giving my own definition of area() for a rectangle
    // "override" confirms I'm replacing the base class's version on purpose
    double area() const override {
        return length * width;
    }
};

// Circle also inherits from Shape and gives its OWN version of area()
class Circle : public Shape {
private:
    double radius;

public:
    // only one value needed for a circle, so explicit avoids accidental conversions
    explicit Circle(double givenRadius) : radius(givenRadius) {}

    // circle's own formula for area, completely different from rectangle's
    double area() const override {
        return 3.141592653589793 * radius * radius;
    }
};

int main() {
    Rectangle rectangle(5.0, 3.0);
    Circle circle(2.0);

    // even though both come from the same base class Shape,
    // each one calculates area() totally differently
    // this works because of polymorphism, same idea as the previous Vehicle example
    cout << "Rectangle Area: " << rectangle.area() << '\n';
    cout << "Circle Area: " << circle.area() << '\n';

    return 0;
}