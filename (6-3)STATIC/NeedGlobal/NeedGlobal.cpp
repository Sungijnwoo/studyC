#include <iostream>
using namespace std;

int simObjCnt = 0;
int cmxobjCnt = 0;

class SoSimple{
    public:
        SoSimple(){
            simObjCnt++;
            cout << simObjCnt << " SoSimple object" << endl;
        }
};

class SoComplex{
    public:
        SoComplex(){
            cmxobjCnt++;
            cout << cmxobjCnt << "번째 SoComplex 객체" << endl;
        }
        SoComplex(SoComplex &copy){
            cmxobjCnt++;
            cout << cmxobjCnt << "번째 SoComplex Obj" << endl;
        }
};

int main(void){
    SoSimple sim1;
    SoSimple sim2;

    SoComplex com1;
    SoComplex com2 = com1;
    SoComplex();
}