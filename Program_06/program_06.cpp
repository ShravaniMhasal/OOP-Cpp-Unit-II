#include <iostream>
using namespace std;

// first base class - handles academic marks only
class Academic {
protected:
    // protected so Student (which inherits from this) can access it directly
    int academicMarks;

public:
    // constructor - sets academic marks
    explicit Academic(int marks) : academicMarks(marks) {}

    // prints academic marks
    void showAcademic() const {
        cout << "Academic Marks: " << academicMarks << '\n';
    }
};

// second base class - handles sports marks only
// this is completely separate from Academic, doesn't know Academic exists
class Sports {
protected:
    int sportsMarks;

public:
    // constructor - sets sports marks
    explicit Sports(int marks) : sportsMarks(marks) {}

    // prints sports marks
    void showSports() const {
        cout << "Sports Marks: " << sportsMarks << '\n';
    }
};

// this is MULTIPLE inheritance - Student inherits from TWO base classes at once
// (Academic AND Sports), not just one like in the previous examples
// so "a Student IS AN Academic" AND "a Student IS A Sports" at the same time
class Student : public Academic, public Sports {
public:
    // constructor - need to initialize BOTH base classes here
    // Academic(academic) sets up academicMarks, Sports(sports) sets up sportsMarks
    Student(int academic, int sports)
        : Academic(academic), Sports(sports) {}

    // this function can use variables from BOTH base classes at once
    // academicMarks comes from Academic, sportsMarks comes from Sports
    void showTotal() const {
        cout << "Total Marks: " << academicMarks + sportsMarks << '\n';
    }
};

int main() {
    // making a Student runs BOTH Academic's constructor and Sports's constructor
    Student student(80, 15);

    student.showAcademic(); // inherited from Academic
    student.showSports();   // inherited from Sports
    student.showTotal();    // Student's own function, uses data from both parents

    return 0;
}