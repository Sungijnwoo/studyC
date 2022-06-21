#include <iostream>
#include <cstring>

using namespace std;

const int NAME_LEN = 20;

void ShowMenu(void);
void MakeAccount(void);
void Deposit(void);
void WithDraw(void);
void PrintAllAccount(void);

enum {MAKE=1, DEPOSIT, WITHDRAW, PRINT, EXIT};

typedef struct{
    int accID;
    int balance;
    char cusName[NAME_LEN];
} Account;

Account accArr[100];
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
            break;
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
    cout << "[계좌개설]" << endl;
    cout << "계좌ID: ";
    cin >> accArr[accNum].accID;
    cout << "이름: ";
    cin >> accArr[accNum].cusName;
    cout << "입금액: ";
    cin >> accArr[accNum].balance;
    accNum++;
}

void Deposit(void){
    int id;
    int deposit;
    cout << "[입금]" << endl;
    cout << "계좌ID: ";
    cin >> id;
    cout << "입금 금액: ";
    cin >> deposit;

    for (int i=0; i<=accNum; i++){
        if (accArr[i].accID == id){
            accArr[i].balance += deposit;
            break;
        }
    }
}

void WithDraw(void){
    int id;
    int withdraw;
    cout << "[출금]" << endl;
    cout << "계좌ID: ";
    cin >> id;
    cout << "출금 금액: ";
    cin >> withdraw;

    for (int i=0; i<=accNum; i++) {
        if (accArr[i].accID == id){
            if (accArr[i].balance >= withdraw){
                accArr[i].balance -= withdraw;
            }
            else {
                cout << "잔고 부족\n";
            }
            break;
        }
    }
}

void PrintAllAccount(void){
    for (int i=0; i<accNum; i++) {
        cout << "계좌ID: " << accArr[i].accID << endl;
        cout << "이 름: " << accArr[i].cusName << endl;
        cout << "잔 액: " << accArr[i].balance << endl;
    }
}