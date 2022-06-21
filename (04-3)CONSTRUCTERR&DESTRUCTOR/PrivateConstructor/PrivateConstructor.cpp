#include <iostream>
using namespace std;

class AAA{
    private:
        int num;
    public:
        AAA() : num(0) {}
        AAA& CreateInitObj(int n) const{
            AAA *ptr = new AAA(n);
            return *ptr;
        }
        void ShowNum() const {cout << num << endl;}
    private:
        AAA(int n): num(n) {}

};

int main(void){
    AAA base;
    base.ShowNum();

    AAA &obj1 = base.CreateInitObj(3);
    obj1.ShowNum();

    AAA &obj2 = base.CreateInitObj(10);
    obj2.ShowNum();
    
    AAA &obj3 = obj2;
    obj3.ShowNum();

    base.ShowNum();
    delete &obj1;
    delete &obj2;

    int &b = test(3);
    cout << b << endl;
    return 0;
}