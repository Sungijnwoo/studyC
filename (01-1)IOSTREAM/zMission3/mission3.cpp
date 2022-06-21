#include <iostream>

int main(void) {
    int number;
    std::cout<<"숫자를 입력하세요: ";
    std::cin>>number;

    for (int i=1; i<10; i++){
        std::cout<<number<<" X "<<i<<" = "<< number*i << std::endl;
    }
}