#include <iostream>
using namespace std;


class SoSimple{
    private:
        static int simObjCnt;
    public:
        SoSimple(){
            simObjCnt++;
            cout << simObjCnt << " SoSimple object" << endl;
        }
};
int SoSimple::simObjCnt = 0;

class SoComplex{
    private:
        static int cmxobjCnt;
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
int SoComplex::cmxobjCnt = 0;

int main(void){
    SoSimple sim1;
    SoSimple sim2;

    SoComplex com1;
    SoComplex com2 = com1;
    SoComplex();
}