#include <iostream>
using namespace std;

void PlusOne(int &val) {
    val++;
}

void ChangeSignal(int &val) {
    val *= -1;
}

int main(void) {
    int value = 1;

    cout << "value: " << value << endl;
    PlusOne(value);
    cout << "value: " << value << endl;
    ChangeSignal(value);
    cout << "value: " << value << endl;
}