#include <iostream>

namespace BestComImpl{
    void SimpleFunc(void);
    void PrettyFunc(void);
}

namespace ProgComImpl{
    void SimpleFunc(void);
    void PrettyFunc(void);
}

int main(void){
    BestComImpl::SimpleFunc();
    return 0;
}

void BestComImpl::SimpleFunc(void){
    std::cout<<"BestCom define"<<std::endl;
    PrettyFunc();
    // ProgComImpl::SimpleFunc();
}

void BestComImpl::PrettyFunc(void){
    std::cout<<"BestCom Pretty"<<std::endl;
}