#include <iostream>
using namespace std;

class Calculator{
    private:
        int addCount;
        int minCount;
        int mulCount;
        int divCount;
    public:
        void Init();
        double ADD(double a, double b);
        double Min(double a, double b);
        double Mul(double a, double b);
        double Div(double a, double b);
        void ShowOpCount();
};

int main(void){
    Calculator cal;
    cal.Init();
    cout << "3.2 + 2.4 = " << cal.ADD(3.2, 2.4) << endl;
    cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
    cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
    cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
    cal.ShowOpCount();
    return 0;
}

inline void Calculator::Init(){
    addCount = 0;
    minCount = 0;
    mulCount = 0;
    divCount = 0;
}
inline double Calculator::ADD(double a, double b){
    addCount++;
    return a + b;
}

inline double Calculator::Min(double a, double b){
    minCount++;
    return a - b;
}

inline double Calculator::Mul(double a, double b){
    mulCount++;
    return a * b;
}

inline double Calculator::Div(double a, double b){
    divCount++;
    return a / b;
}

inline void Calculator::ShowOpCount(){
    cout << "덧셈: " << addCount << " 뺄셈: " << minCount << " 곱셈: " << mulCount << " 나눗셈: " << divCount << endl;
}

