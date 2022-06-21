#include <iostream>

int main(void){
    int result = 0;
    for (int i=1; i<6; i++){
        int input;
        std::cout<<i<<"번째 정수입력: ";
        std::cin>>input;
        result += input;
    }
    std::cout<<"합계: "<<result<<std::endl;
}
