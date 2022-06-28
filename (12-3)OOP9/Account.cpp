#include "BankingCommonDec1.h"
#include "Account.h"

Account::Account(int ID, int money, char * name)
    : accID(ID), balance(money)
{
    cusName = name;
}

int Account::GetAccID() const { return accID; }

void Account::Deposit(int money) {
    balance += money;
}

int Account::Withdraw(int money) {
    if (balance < money) {
        return 0;
    }
    balance -= money;
    return money;
}

void Account::ShowAccInfo() const {
    cout << "accID: " << accID << endl;
    cout << "name: " << cusName << endl;
    cout << "balance: " << balance << endl;
}
