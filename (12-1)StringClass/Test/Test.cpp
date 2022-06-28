#include <iostream>
#include <cstring>

using namespace std;

char print(char * s) {
    return s;
}

int main(void) {
    char * s = "hi";
    cout << print(s) << endl;
    return 0;
}