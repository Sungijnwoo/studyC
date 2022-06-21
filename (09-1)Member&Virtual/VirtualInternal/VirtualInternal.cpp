#include <iostream>
using namespace std;

class AAA {
    private:
        int num;
    public:
        virtual void Func1() {cout << "Func1" << endl;}
        void Func2() { cout << "Func2" << endl;}
};

class BBB: public AAA {
    private:
        int num2;
    public:
        virtual void Func1() {cout << "BBB::Func1" << endl;}
        void Func2() {cout << "BBB::Func2" << endl;}
        void Func3() { cout << "Func3" << endl;}
};

int main(void) {
    AAA * aptr = new AAA();
    aptr->Func1();

    AAA * bptr = new BBB();
    bptr->Func1();
    bptr->Func2();
    return 0;
}