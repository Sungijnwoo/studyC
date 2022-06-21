#include <iostream>
#include <cstring>
using namespace std;

class MyFriendInfo{
    private:
        char * name;
        int age;
    public:
        MyFriendInfo(char * myname, int age){
            this->age = age;
            name = new char[strlen(myname)+1];
            strcpy(name, myname);
        }
        void ShowMyFriendInfo(){
            cout << "name: " << name << endl;
            cout << "age: " << age << endl;
        }
        
        ~MyFriendInfo(){
            delete []name;
        }
};

class MyFriendDetailInfo : public MyFriendInfo{
    private:
        char * addr;
        char * phone;
    public:
        MyFriendDetailInfo(char * addr, char * phone, char * name, int age) : MyFriendInfo(name, age) {
            this->addr = new char[strlen(addr)+1];
            strcpy(this->addr, addr);
            this->phone = new char[strlen(phone)+1];
            strcpy(this->phone, phone);
        }

        void ShowMyFriendDetailInfo(){
            ShowMyFriendInfo();
            cout << "addr: " << this->addr << endl;
            cout << "phone: " << this->phone << endl;
        }

        ~MyFriendDetailInfo(){
            delete []addr;
            delete []phone;
        }
};

int main(void){
    MyFriendDetailInfo s1("lo123", "010-2222-4444", "jinwoo", 32);
    s1.ShowMyFriendDetailInfo();
}