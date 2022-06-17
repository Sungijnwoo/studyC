#include <iostream>
#include <cstring>
using namespace std;


const int NAME_LEN = 20;
enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};
double RANK[4] = {0, 7, 4, 22};

class Account{
    private:
        int accID;
        char * cusName;
    protected:
        int balance;
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

        virtual void Deposit(int money){
            balance += money;
        }

        int WithDraw(int money){
            if (balance < money){
                return 0;
            }
            balance -= money;
            return money;
        }

        virtual void ShowAccInfo() const{
            cout << "accID: " << accID << endl;
            cout << "cusName: " << this->cusName << endl;
            cout << "balance: " << this->balance << endl;
        }

        virtual ~Account() {
            cout << "delete cusName" << endl;
            delete []cusName;
        }
};

class NormalCount : public Account{
    protected:
        const int interestRatio;
    public:
        NormalCount(int ID, int money, char * name, int ratio) : Account(ID, money, name), interestRatio(ratio) {}

        virtual void Deposit(int money) {
            balance += (int)(money * interestRatio / 100);
        }

        virtual void ShowAccInfo() const {
            Account::ShowAccInfo();
            cout << "interestRatio: " << interestRatio << endl;
        }

        virtual ~NormalCount() {
            cout << "Delete NormalCount" << endl;
        }
};

class HighCreditAccount : public NormalCount {
    protected:
        const double addRatio;
    public:
        HighCreditAccount(int ID, int money, char * name, int ratio, int rankRatio) : NormalCount(ID, money, name, ratio), addRatio(rankRatio) {}

        virtual void Deposit(int money) {
            balance += (int)(money * (addRatio + interestRatio) / 100);
        }

        virtual void ShowAccInfo() const {
            NormalCount::ShowAccInfo();
            cout << "addRatio: " << addRatio << endl;
            cout << "finalRatio: " << addRatio + interestRatio << endl;
        }

        virtual ~HighCreditAccount() {
            cout << "Delete HighCreditCount" << endl;
        }
};

class AccountHandler{
    private:
        Account * accArr[100];
        int accNum;
    public:
        AccountHandler() : accNum(0){}
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
            double ratio;
            int kind;
            int rank;
            double addRatio;
            cout << "[MakeAccount]" << endl;
            cout << "[Select Account]" << endl;
            cout << "1. NormalAccount 2. HighCreditAccount" << endl;
            cout << "Select: "; cin >> kind;
            if (kind == 1) {
                cout << "[NormalAccount]" << endl;
                cout << "AccountID: "; cin >> id;
                cout << "Name: "; cin >> name;
                cout << "Money: "; cin >> balance;
                cout << "Ratio: "; cin >> ratio;
                accArr[accNum++] = new NormalCount(id, balance, name, ratio);
            }
            else if (kind == 2) {
                cout << "[HighCreditAccount]" << endl;
                cout << "AccountID: "; cin >> id;
                cout << "Name: "; cin >> name;
                cout << "Money: "; cin >> balance;
                cout << "Ratio: "; cin >> ratio;
                cout << "Rank(1 to A, 2 to B, 3 to C): "; cin >> rank;
                accArr[accNum++] = new HighCreditAccount(id, balance, name, ratio, RANK[rank]);
            }
            else {
                cout << "Invalid Input" << endl; 
                return;
            }
            cout << endl;
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

        ~AccountHandler() {
            for (int i=0; i<accNum; i++)
                delete accArr[i];
        }
};

int main(void){
    AccountHandler manager;
    int choice;
    while(1){
        manager.ShowMenu();
        cout << "select: "; cin >> choice;
        cout << endl;

        switch(choice){
            case MAKE:
                manager.MakeAccount();
                break;
            case DEPOSIT:
                manager.DepositMoney();
                break;
            case WITHDRAW:
                manager.WithDrawMoney();
                break;
            case INQUIRE:
                manager.ShowAllAccInfo();
                break;
            case EXIT:
                return 0;
            default:
                cout << "Illegal selection.." << endl;
        }
    }
    return 0;
}




