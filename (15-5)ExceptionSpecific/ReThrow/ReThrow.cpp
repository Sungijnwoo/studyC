#include <iostream>
using namespace std;

void Devide(int num1, int num2) {
    try {
        if (num2 == 0)
            throw 0;
        cout << "mock: " << num1/num2 << endl;
        cout << "mod: " << num1 % num2 << endl;
    }
    catch(int expn) {
        cout << "first catch" << endl;
        throw;
    }
}

int main(void) {
    try {
        Devide(9, 2);
        Devide(4, 0);
    }
    catch(int expn) {
        cout << "second catch" << endl;
    }
    return 0;
}