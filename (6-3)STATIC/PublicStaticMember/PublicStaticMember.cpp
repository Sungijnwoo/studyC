#include <iostream>
using namespace std;

class SoSimple{
    public:
        static int simObjCnt;
    public:
        SoSimple(){
            simObjCnt++;
        }
};

int SoSimple::simObjCnt = 0;

int main(void){
    cout << SoSimple::simObjCnt << "SoSimple obj" << endl;
    SoSimple sim1;
    SoSimple sim2;

    cout << SoSimple::simObjCnt << "번째 SoSimple obj" << endl;
    cout << sim1.simObjCnt << endl;
    cout << sim2.simObjCnt << endl;
}