#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "String.h"

void AccountHandler::ShowMenu(void) const {
    cout << "--------Menu----------" << endl;
    cout << "1. MakeAccount" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. WithDraw" << endl;
    cout << "4. ShowAllAccount" << endl;
    cout << "5. Break" << endl;
}

void AccountHandler::MakeAccount(void) {
    int id;
    char name[NAME_LEN];
    int balance;
    int interRate;

    cout << "[NormalAccount]" << endl;
    cout << "AccountID: "; cin >> id;
    cout << "Name: "; cin >> name;
    cout << "Money: "; cin >> balance;
    cout << "Ratio: "; cin >> interRate;
    cout << endl;
    accArr[accNum++] = new NormalCount(id, balance, name, interRate);
}

void AccountHandler::MakeCreditAccount(void){
    int id;
    String name;
    int balance;
    int creditLevel;
    int interRate;

    cout << "[HighCreditAccount]" << endl;
    cout << "AccountID: "; cin >> id;
    cout << "Name: "; cin >> name;
    cout << "Money: "; cin >> balance;
    cout << "Ratio: "; cin >> interRate;
    cout << "Rank(1 to A, 2 to B, 3 to C): "; cin >> creditLevel;

    switch(creditLevel) {
        case 1:
            accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_A);
            break;
        case 2:
            accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_B);
            break;
        case 3;
            accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_B);
            break;
    }
}

void AccountHandler::DepositMoney(void) {
    int money;
    int id;
    cout << "[Deposit]" << endl;
    cout << "accID: "; cin >> id;
    cout << "money: "; cin >> money;

    for (int i=0; i<accNum; i++){
        if (accArr[i]->GetAccID() == id){
            accArr[i]->Deposit(money);
            cout << "complete" << endl << endl;
            return;
        }
    }
    cout << "Invalid ID" << endl << endl;
}

void AccountHandler::WithdrawMoney(void){
    int money;
    int id;
    cout << "[WithDraw]" << endl;
    cout<< "AccountID: "; cin >> id;
    cout << "Money: "; cin >> money;

    for (int i=0; i<accNum; i++){
        if (accArr[i]->GetAccID() == id){
            if (accArr[i]->WithDraw(money) == 0){
                cout << "Lack of Money" << endl << endl;
                return;
            }
            cout << "withdraw complete" << endl;
            return;
        }
    }
    cout << "invalid id" << endl << endl;
}

AccountHandler::AccountHandler() : accNum(0) {}

void AccountHandler::ShowAllAccInfo(void) const {
    for (int i=0; i<accNum; i++){
        accArr[i]->ShowAccInfo();
        cout << endl;
    }
}

AccountHandler::~AccountHandler() {
    for (int i=0; i<accNum; i++)
        delete accArr[i]
}