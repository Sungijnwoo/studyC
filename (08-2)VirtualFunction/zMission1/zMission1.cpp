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
        virtual int GetPay() const = 0;
        virtual void ShowSalaryInfo() const = 0;
};

class PermanentWorker: public Employee{
    private:
        int salary;
    public:
        PermanentWorker(char* name, int money) : Employee(name), salary(money){}
        virtual int GetPay() const{
            return salary;
        }
        virtual void ShowSalaryInfo() const{
            ShowYourName();
            cout << "salary: " << GetPay() << endl << endl;
        }
};

class TemporaryWorker : public Employee {
    private:
        int workTime;
        int payPerHour;
    public:
        TemporaryWorker(char * name, int pay) : Employee(name), payPerHour(pay)
        {}
        void AddWorkTime(int time){
            workTime += time;
        }
        virtual int GetPay() const {
            return workTime * payPerHour;
        }
        virtual void ShowSalaryInfo() const {
            ShowYourName();
            cout << "Salary: " << GetPay() << endl << endl;
        }
};

class SalesWorker : public PermanentWorker {
    private:
        int salesResult;
        double bonusRatio;
    public:
        SalesWorker(char * name, int money, double ratio) : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
        {}
        void AddSalesResult(int value){
            salesResult += value;
        }
        virtual int GetPay() const {
            return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
        }
        virtual void ShowSalaryInfo() const {
            ShowYourName();
            cout << "Salary: " << this->GetPay() << endl;
        }
};

class ForeignSalesWorker : public SalesWorker {
    private:
        const double dangerIncentive;
    public:
        ForeignSalesWorker(char * name, int money, double ratio, double dangerRatio): SalesWorker(name, money, ratio), dangerIncentive(dangerRatio)
        {}
        int riskPay() const {
            return dangerIncentive * SalesWorker::GetPay();
        }
        virtual int GetPay() const {
            return SalesWorker::GetPay() + riskPay();
        }
        virtual void ShowSalaryInfo() const {
            ShowYourName();
            cout << "Salary: " << SalesWorker::GetPay() << endl; 
            cout << "riskPay: " << riskPay()  << endl;
            cout << "sum: " << GetPay() << endl << endl;
        }
};

class EmployeeHandler{
    private:
        Employee* empList[50];
        int empNum;
    public:
        EmployeeHandler() : empNum(0) {}
        void AddEmployee(Employee * emp){
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

    ForeignSalesWorker * fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, 0.3);
    fseller1->AddSalesResult(7000);
    handler.AddEmployee(fseller1);

    // ForeignSalesWorker * fseller2 = new ForeignSalesWorker("Jin", 1000, 0.1, 0.2);
    // fseller1->AddSalesResult(7000);
    // handler.AddEmployee(fseller2);

    // ForeignSalesWorker * fseller3 = new ForeignSalesWorker("Woo", 1000, 0.1, 0.1);
    // fseller1->AddSalesResult(7000);
    // handler.AddEmployee(fseller3);

    handler.ShowAllSalaryInfo();
    
    return 0;
}