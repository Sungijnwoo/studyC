#include <iostream>

int main(void){
    char name[20], phoneNumber[20];
    std::cout<<"이름을 입력하세요: ";
    std::cin>>name;
    std::cout<<"전화번호 입력하세요: ";
    std::cin>>phoneNumber;

    std::cout<<"이름 :"<<name<<std::endl;
    std::cout<<"번호 :"<<phoneNumber<<std::endl;
}