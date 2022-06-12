#include <iostream>
#include <cstring>
using namespace std;


const int NAME_LEN = 20;

void ShowMenu(void);
void MakeAccount(void);
void DepositMoney(void);
void WithDrawMoney(void);
void ShowAllAccInfo(void);

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

class Account{
    private:
        int accID;
        int balance;
        char * cusName;
    public:
        Account(int ID, int money, char * name) : accID(ID), balance(money) {
            cusName = new char[strlen(name)+1];
            strcpy(cusName, name);
        }

        Account(const Account & ref): accID(ref.accID), balance(ref.balance) {
            cusName = new char[strlen(ref.cusName)+1];
            strcpy(cusName, ref.cusName);
        }

        int GetAccID() const {return accID;}

        void Deposit(int money){
            balance += money;
        }

        int WithDraw(int money){
            if (balance < money){
                return 0;
            }
            balance -= money;
            return money;
        }

        void ShowAccInfo() const{
            cout << "accID: " << accID << endl;
            cout << "cusName: " << this->cusName << endl;
            cout << "balance: " << this->balance << endl;
        }

        ~Account() {
            delete []cusName;
        }
};

Account * accArr[100];
int accNum = 0;

int main(void){
    int choice;

    while(1){
        ShowMenu();
        cout << "select: "; cin >> choice;
        cout << endl;

        switch(choice){
            case MAKE:
                MakeAccount();
                break;
            case DEPOSIT:
                DepositMoney();
                break;
            case WITHDRAW:
                WithDrawMoney();
                break;
            case INQUIRE:
                ShowAllAccInfo();
                break;
            case EXIT:
                for (int i=0; i<accNum; i++)
                    delete accArr[i];
                return 0;
            default:
                cout << "Illegal selection.." << endl;
        }
    }
}

void ShowMenu(void){
    cout << "--------Menu----------" << endl;
    cout << "1. MakeAccount" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. WithDraw" << endl;
    cout << "4. ShowAllAccount" << endl;
    cout << "5. Break" << endl;
}

void MakeAccount(void){
    int id;
    char name[NAME_LEN];
    int balance;

    cout << "[MakeAccount]" << endl;
    cout << "AccountID: "; cin >> id;
    cout << "Name: "; cin >> name;
    cout << "Money: "; cin >> balance;
    cout << endl;

    accArr[accNum++] = new Account(id, balance, name);
}

void DepositMoney(void){
    int money;
    int id;
    cout << "[Deposit]" << endl;
    cout << "AccountID: "; cin >> id;
    cout << "Money: "; cin >> money;

    for (int i=0; i<accNum; i++){
        if (accArr[i]->GetAccID() == id){
            accArr[i]->Deposit(money);
            cout << "deposit complete" << endl;
            return;
        }
    }
    cout << "invalid id" << endl << endl;
}

void WithDrawMoney(void){
    int money;
    int id;
    cout << "[WithDraw]" << endl;
    cout<< "AccountID: "; cin >> id;
    cout << "Money: "; cin >> money;

    for (int i=0; i<accNum; i++){
        if (accArr[i]->GetAccID() == id){
            accArr[i]->WithDraw(money);
            cout << "withdraw complete" << endl;
            return;
        }
    }
    cout << "invalid id" << endl << endl;
}

void ShowAllAccInfo(void){
    for (int i=0; i<accNum; i++){
        accArr[i]->ShowAccInfo();
        cout << endl;
    }
}