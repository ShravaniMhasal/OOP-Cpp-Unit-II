#include <iostream>
using namespace std;

class Base {
public:
    void show() const {
        cout << "Base public function\n";
    }
};

//public inheritance "is-a" relationship
//everything that was public in Base stays public in PublicDerived
class PublicDerived : public Base {
};

//private inheritance NOT an "is-a" relationship
//everything that was public in Base becomes private in PrivateDerived
class PrivateDerived : private Base {
public:
    void callBaseShow() const {
        show(); //allowed here, since we're inside the class itself
    }
};

int main() {
    PublicDerived publicObject;
    publicObject.show(); //works fine, show() is still public

    PrivateDerived privateObject;
    privateObject.callBaseShow(); //works, we go through a public wrapper function

    return 0;
}