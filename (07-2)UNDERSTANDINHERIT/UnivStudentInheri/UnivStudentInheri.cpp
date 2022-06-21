#include <iostream>
#include <cstring>
using namespace std;

class Person{
    private:
        int age;
        char name[50];
    public:
        Person(int myage, char *myname): age(myage){
            strcpy(name, myname);
        }
        void WhatYourName() const{
            cout << "my name: " << name << endl;
        }
        void HowOldAreYou() const{
            cout << "I'm " << age << " years old" << endl;
        }
};

class UnivStudent : public Person {
    private:
        char mymajor[50];
    public:
        UnivStudent(int myage, char *myname, char *mymajor): Person(myage, myname){
            strcpy(this->mymajor, mymajor);
        }
        void WhoAreYou() const{
            WhatYourName();
            HowOldAreYou();
            cout << "My Major is " << this->mymajor << endl;
        }
};

int main(void){
    UnivStudent ustd1(22, "Lee", "Computer");
    ustd1.WhoAreYou();
    return 0;
}