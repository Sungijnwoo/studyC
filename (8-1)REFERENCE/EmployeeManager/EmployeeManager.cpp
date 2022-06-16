#include <iostream>
#include <cstring>
using namespace std;

class Employee {
    private:
        char name[100];
    public:
        Employee(char * name){
            strcpy(this->name, name);
        }
        void ShowYourName() const {
            cout << "name: " << this->name << endl;
        }
};

class PermanentWorker: public Employee{
    private:
        int salary;
    public:
        PermanentWorker(char* name, int money) : Employee(name), salary(money){}
        int GetPay() const{
            return salary;
        }
        void ShowSalaryInfo() const{
            ShowYourName();
            cout << "salary: " << GetPay() << endl << endl;
        }
};

class EmployeeHandler{
    private:
        PermanentWorker* empList[50];
        int empNum;
    public:
        EmployeeHandler() : empNum(0) {}
        void AddEmployee(PermanentWorker* emp){
            empList[empNum++] = emp;
        }
        void ShowAllSalaryInfo() const {
            for (int i=0; i<empNum; i++){
                empList[i]->ShowSalaryInfo();
            }
        }
        void ShowTotalSalary() const {
            int sum = 0;
            for(int i=0; i<empNum; i++){
                sum += empList[i]->GetPay();
            }
            cout << "salary sum: " << sum << endl;
        }
        ~EmployeeHandler(){
            for (int i=0; i<empNum; i++){
                delete empList[i];
            }
        }
};

int main(void){
    EmployeeHandler handler;

    handler.AddEmployee(new PermanentWorker("Kim", 1000));
    handler.AddEmployee(new PermanentWorker("Lee", 1500));
    handler.AddEmployee(new PermanentWorker("Jun", 2000));

    handler.ShowAllSalaryInfo();
    handler.ShowTotalSalary();
    return 0;
}