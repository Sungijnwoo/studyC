#include <iostream>

using std::cin;
using std::cout;
using std::endl;

namespace Hybrid{
    void HybFunc(void){
        cout<<"So simple Function"<<endl;
        std::cout<<"In namespace Hybrid!"<<endl;
    }
}

int main(void){
    using Hybrid::HybFunc;
    HybFunc();
    return 0;
}