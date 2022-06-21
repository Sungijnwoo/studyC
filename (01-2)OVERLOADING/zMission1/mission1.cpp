#include <iostream>

void swap(int *addr1, int *addr2){
    int temp;
    temp = *addr2;
    *addr2 = *addr1;
    *addr1 = temp;
}

void swap(char *addr1, char *addr2){
    char temp;
    temp = *addr2;
    *addr2 = *addr1;
    *addr1 = temp;
}

void swap(double *addr1, double *addr2){
    double temp;
    temp = *addr2;
    *addr2 = *addr1;
    *addr1 = temp;
}

int main(void){
    int num1 = 20, num2 = 30;
    swap(&num1, &num2);
    std::cout<<num1<<' '<<num2<<std::endl;

    char ch1='A', ch2 = 'Z';
    swap(&ch1, &ch2);
    std::cout<<ch1<<' '<<ch2<<std::endl;
    
    double dbl1 = 1.111, dbl2 = 5.555;
    swap(&dbl1, &dbl2);
    std::cout<<dbl1<< ' '<<dbl2<<std::endl;
}