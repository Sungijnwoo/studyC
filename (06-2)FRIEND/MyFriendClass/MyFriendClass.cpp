#include <iostream>
#include <cstring>
using namespace std;

class Girl;
class Boy{
    private:
        int height;
        friend class Girl;
    public:
        Boy(int len) : height(len){}
        void ShowYourFriendInfo(Girl &frn);
};

class Girl{
    private:
        char *phNum;
    public:
        Girl(char * num){
            phNum = new char[strlen(num)+1];
            strcpy(phNum, num);
        }
        void ShowYourFriendInfo(Boy &frn);
        friend class Boy;
        ~Girl(){
            delete []phNum;
            cout << "delete phNum" << endl;
        }
};

void Boy::ShowYourFriendInfo(Girl &frn){
    cout << "Her Phone number: " << frn.phNum << endl;
}

void Girl::ShowYourFriendInfo(Boy &frn){
    cout << "His Height: " << frn.height << endl;
}

int main(void){
    Boy boy(170);
    Girl girl("010-8291-2247");
    boy.ShowYourFriendInfo(girl);
    girl.ShowYourFriendInfo(boy);
    return 0;
}