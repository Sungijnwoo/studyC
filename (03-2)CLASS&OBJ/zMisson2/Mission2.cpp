#include <iostream>
using namespace std;

class Printer{
    private:
        char *saveString;
    public:
        void SetString(char *inputString);
        void ShowString();
};

int main(void) {
    Printer pnt;
    pnt.SetString("Hello world!");
    pnt.ShowString();

    pnt.SetString("I love c++");
    pnt.ShowString();
    return 0;
}

inline void Printer::SetString(char *inputString){
    saveString = inputString;
}

inline void Printer::ShowString(){
    cout << saveString << endl;
}