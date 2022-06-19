#include <iostream>
using namespace std;

class Base{
    public:
        Base() { cout << "Base Constructor" << endl;}
        void SimpleFunc() { cout << "BaseOne" << endl;}
};

class MiddleDerivedOne : virtual public Base {
    public:
        MiddleDerivedOne() : Base() {
            cout << "MiddleDerivedOne constructor" << endl;
        }
        void MiddleFuncOne() {
            SimpleFunc();
            cout << "MiddleDerivedOne" << endl;
        }
};

class MiddleDerivedTwo : virtual public Base {
    public:
        MiddleDerivedTwo() : Base() {
            cout << "MiddleDerivedTwo Constructor" << endl;
        }
        void MiddleFuncTwo() {
            SimpleFunc();
            cout << "MiddleDerivedTwo" << endl;
        }
};

class LastDerived : public MiddleDerivedOne, public MiddleDerivedTwo {
    public:
        LastDerived() : MiddleDerivedOne(), MiddleDerivedTwo() {
            cout << "LastDerived Constructor" << endl;
        }
        void ComplexFunc() {
            MiddleFuncOne();
            MiddleFuncTwo();
            SimpleFunc();
        }
};

int main(void) {
    cout << "before class" << endl;
    LastDerived ldr;
    cout << "after class" << endl;
    ldr.ComplexFunc();
    return 0;
}