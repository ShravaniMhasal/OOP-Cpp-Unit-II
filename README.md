# OOP C++ Programming – Unit II
<br>
Name: Shravani Mhasal
<br>
Division: B
<br>
Class: SY BTech
<br>
Branch: AI & Data Science
<br>
ZPRN: 125UAD1008
<br>
Roll Number: AD2233
<br>
Course Name: Object Oriented Programming with C++
<br>
#UNIT II: Programming Codes
<br>
1. Basic Single Inheritance:
<br>
Classes: Person → Student A base class (Person) stores common data; the derived class (Student) adds its own data and reuses the base class's function. Shows the basic "is-a" relationship.
<br>
2. Protected Member Access:
<br>
Classes: Employee → Developer Shows that a protected member (name) can be accessed directly inside a derived class, but not from outside code like main().
<br>
3. Public versus Private Inheritance
<br>
Classes: Base → PublicDerived, Base → PrivateDerived Compares inheritance modes: with public inheritance, base members keep their original access level; with private inheritance, public/protected base members become private in the derived class.
<br>
4. Multilevel Inheritance
<br>
Classes: Person → Employee → Manager A three-level chain where each class adds more data. Constructors run top-down (Person first), and Manager can use everything inherited from both ancestors.
<br>
5. Hierarchical Inheritance
<br>
Classes: Vehicle → Car, Vehicle → Bike One base class (Vehicle) is inherited independently by two sibling classes (Car, Bike), each adding its own unique function.
<br>
6. Multiple Inheritance
<br>
Classes: Academic + Sports → Student A single class inherits from two base classes at once, combining data from both (academicMarks + sportsMarks) into one derived class.
<br>
7. Resolving Multiple-Inheritance Ambiguity
<br>
Classes: Academic + Sports → Student When both base classes have a function with the same name (display()), the scope-resolution operator (ClassName::functionName()) is used to remove ambiguity.
<br>
8. Constructor and Destructor Order
<br>
Classes: Base → Derived Demonstrates object lifecycle: constructors run Base → Derived, while destructors run in reverse, Derived → Base.
<br>
9. Parameterized Base Constructor
<br>
Classes: Person → Student Shows how a derived class passes a value to a parameterized base-class constructor using an initializer list.
<br>
10. Function Overriding
<br>
Classes: Vehicle → Car, Vehicle → Boat Introduces virtual and override for run-time polymorphism — the same function name (move()) behaves differently depending on the actual object type.
<br>
11. Abstract Class
<br>
Classes: Shape → Rectangle, Shape → Circle Shape is abstract due to a pure virtual function (virtual double area() const = 0;), so it can't be instantiated directly. Every derived class must implement its own version.
<br>
12. Virtual Base Class and Diamond Inheritance
<br>
Classes: Person → Student, Employee → TeachingAssistant Solves the "diamond problem": when two classes (Student, Employee) inherit from the same base (Person), virtual inheritance ensures TeachingAssistant gets only one shared copy of Person.
<br>
13. Friend Class
<br>
Classes: Account, Auditor (no inheritance relationship) friend class Auditor; grants Auditor special access to Account's private data, even though there's no parent-child relationship between them.
<br>
14. Nested Class
<br>
Classes: University::Department A class defined inside another class for code organization (not inheritance). Accessed using the scope-resolution operator: University::Department.
<br>
15. Mini-Project — Vehicle Rental System
<br>
Classes: Vehicle → Car, Vehicle → Bike Integrates virtual functions and overriding into a small application: both Car and Bike override display() (reusing Vehicle::display() first), while only Bike overrides calculateRent() for a discounted rate.
<br>
16. Mini-Project — Employee Payroll System
<br>
Classes: Employee → PermanentEmployee, Employee → ContractEmployee Employee is abstract (calculateSalary() is pure virtual). A single function displayPaySlip(const Employee&) works correctly for both derived types through polymorphism — one function, multiple salary calculation behaviors.
