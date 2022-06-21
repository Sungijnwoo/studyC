#include <iostream>
#include <cstring>

using namespace std;

const int NAME_LEN = 20;

void ShowMenu(void);
void MakeAccount(void);
void PrintAllAccount(void);

enum {MAKE=1, DEPOSIT, WITHDRAW, PRINT, EXIT};

class Account{
    private:
        int accID;
        int balance;
        char * cusName;
    public:
        Account(int ID, int money, char * name): accID(ID), balance(money){
            cusName = new char[strlen(name)+1];
            strcpy(cusName, name);
        }

        int GetAccID(){return this->accID;}

        void Deposit(int money){
            this->balance += money;
        }

        int Withdraw(int money){
            if (balance < money) return 0;
            balance -= money;
            return money;
        }

        void ShowAccInfo(){
            cout << "ID: " << accID << endl;
            cout << "Name: " << cusName << endl;
            cout << "balance: " << balance << endl;
        }

        ~Account(){
            delete []cusName;
        }
};

Account * accArr[100];
int accNum = 0;

int main(void){
    while(1){
        ShowMenu();
        int select;
        cout << "선택: ";
        cin >> select;
        cout << endl;
        if (select==MAKE){
            MakeAccount();
        }
        else if (select==DEPOSIT){
            Deposit();
        }
        else if (select == WITHDRAW){
            WithDraw();
        }
        else if (select == PRINT){
            PrintAllAccount();
        }
        else if (select == EXIT){
            for (int i = 0; i < accNum; i++){
                delete accArr[i];
            }
            return 0;
        }
    }
    return 0;
}

void ShowMenu(void){
    cout << "----Menu------" << endl;
    cout << "1. 계좌개설" << endl;
    cout << "2. 입금" << endl;
    cout << "3. 출금" << endl;
    cout << "4. 계좌정보 전체 출력" << endl;
    cout << "5. 종료" << endl;
}

void MakeAccount(void){
    int id;
    char name[NAME_LEN];
    int balance;

    cout << "[계좌개설]" << endl;
    cout << "계좌ID: "; cin >> id;
    cout << "이름: "; cin >> name;
    cout << "입금액: "; cin >> balance;
    cout << endl;
    accArr[accNum++] = new Account(id, balance, name);
}

void PrintAllAccount(void){
    for (int i=0; i<accNum; i++) {
        accArr[i]->ShowAccInfo();
    }
}