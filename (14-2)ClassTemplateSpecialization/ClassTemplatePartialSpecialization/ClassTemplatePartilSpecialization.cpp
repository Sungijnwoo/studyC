#include <iostream>
using namespace std;

template <typenmae T1, typename T2>
class MySimple
{
    public:
        void WhoAreYou() {
            cout << "size of T1: " << sizeof(T1) << endl;
            cout << "size of T2: " << sizeof(T2) << endl;
            cout << "<typenmae T1, typename T2>" << endl;
        }
};

template <>
class MySimple<int, double> {
    public:
        void WhoAreYou() {
            cout << "size of int: " << sizeof(int) << endl;
            cout << "size of double: " << sizeof(double) << endl;
            cout << "<typenmae T1, typename T2>" << endl;
        }
};

template <typenmae T1>
class MySimple<T1, double> {
    
}