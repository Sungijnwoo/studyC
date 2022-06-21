#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS{
    enum {CLERK, SENIOR, ASSIST, MANAGER};

    void ShowPositionInfo(int pos){
        switch(pos){
            case CLERK:
                cout << "사원" << endl;
                break;
            case SENIOR:
                cout << "주임" << endl;
                break;
            case ASSIST:
                cout << "대리" <<endl;
            case MANAGER:
                cout << "과장" << endl;
        }
    }
}


class NameCard{
    private:
        char * name;
        char * companyName;
        char * phoneNumber;
        int position;
    
    public:
        NameCard(char * _name, char * _company, char * _phone, int pos): position(pos){
            name = new char[strlen(_name) + 1];
            companyName = new char[strlen(_company) + 1];
            phoneNumber = new char[strlen(_phone)+1];
            strcpy(name, _name);
            strcpy(companyName, _company);
            strcpy(phoneNumber, _phone);
        }
        NameCard(NameCard &copy): position(copy.position){
            name = new char[strlen(copy.name) + 1];
            strcpy(name, copy.name);

            companyName = new char[strlen(copy.companyName)+1];
            phoneNumber = new char[strlen(copy.phoneNumber)+1];
        }
        void ShowNameCardInfo(){
            cout << "name: " << name << endl;
            cout << "company: " << companyName << endl;
            cout << "phoneNumber: " << phoneNumber << endl;
            cout << "position: ";
            COMP_POS::ShowPositionInfo(position);
            cout << endl;
        }
        ~NameCard(){
            cout << "called delete" << endl;
            delete []name;
            delete []companyName;
            delete []phoneNumber;
        }
};

int main(void){
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard copy1 = manClerk;
    NameCard manSenior("Hong", "OrangeEng", "010-3333-44444", COMP_POS::SENIOR);
    NameCard copy2 = manSenior;
    copy1.ShowNameCardInfo();
    copy2.ShowNameCardInfo();
    return 0;
}