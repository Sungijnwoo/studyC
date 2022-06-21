#include <iostream>
using namespace std;

class SoSimple{
    private:
        int num;
    public:
        SoSimple(int n) : num(n){}
        SoSimple(const SoSimple& copy) : num(copy.num){
            cout << "Called SoSimple(const SoSimple& copy)" << endl;
        }
        void ShowData(){
            cout << "num: " << num << endl;
        }
};

void SimpleFuncObj(SoSimple ob){
    ob.ShowData();
}

int main(void){
    SoSimple obj(7);
    cout << "before call function" << endl;
    SimpleFuncObj(obj);
    cout << "after call function" << endl;
    return 0;
}