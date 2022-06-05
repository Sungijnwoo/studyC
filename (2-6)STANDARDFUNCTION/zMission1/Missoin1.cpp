#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main(void){
    char *str1 = "ABC 123 ";
    char *str2 = "DEF 456 ";
    // char *sentence = "Hello World";
    // char *questionmark = "Welcome";
    cout << "문자열 길이: " << strlen(str1) << endl;

    strcat(str1, str2);
    cout << "please" << endl;
    cout << str1 << endl;

    // char cpysentence[50];
    // strcpy(cpysentence, sentence);

    // if(strcmp(sentence, cpysentence) == 1){
    //     cout << "같음" << endl;
    // } else {
    //     cout << "다름" << endl;
    // }

    return 0;

}