#include <iostream>
using namespace std;

void Divide(int num1, int num2) {
    if (num2 == 0) {
        throw num2;
    }
    cout << "나눗셈의 몫: " << num1/num2 << endl;
    cout << "나눗셈의 나머지: " << num1 % num2 << endl;
}

int main(void) {
    int num1, num2;
    cout << "input two number: "; cin >> num1 >> num2;

    try {
        Divide(num1, num2);
        cout << "Finish Divide" << endl;
    }
    catch(int expn) {
        cout << "can't divide by " << expn << endl;
        cout << "plz rerun program" << endl;
    }
    return 0;
}