#include <iostream>
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
        void ShowNameCardInfo(){
            cout << "name: " << name << endl;
            cout << "company: " << companyName << endl;
            cout << "phoneNumber: " << phoneNumber << endl;
            cout << "position: ";
            COMP_POS::ShowPositionInfo(position);
            cout << endl;
        }
        ~NameCard(){
            delete []name;
            delete []companyName;
            delete []phoneNumber;
        }
};

int main(void){
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard manSenior("Hong", "OrangeEng", "010-3333-44444", COMP_POS::SENIOR);
    NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
    manClerk.ShowNameCardInfo();
    manSenior.ShowNameCardInfo();
    manAssist.ShowNameCardInfo();
    return 0;
}