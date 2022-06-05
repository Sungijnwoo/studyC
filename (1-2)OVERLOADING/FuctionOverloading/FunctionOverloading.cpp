#include <iostream>

void MyFunc(void){
    std::cout<<"MyFunnc(void) called"<<std::endl;
}

void MyFunc(char c){
    std::cout<<"MyFunc(char c) called\n";
}

void MyFunc(int a, int b){
    std::cout<<"MyFunnc(int a, int b) called"<<std::endl;
}

int main(void){
    MyFunc();
    MyFunc('A');
    MyFunc(2, 3);
}