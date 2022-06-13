#include <iostream>
#include <cstring>
using namespace std;

class Car{
    private:
        int gasolineGauge;
    public:
        Car(int n) : gasolineGauge(n){}
        int GetGasGuage(){
            return gasolineGauge;
        }
};

class HybridCar : public Car{
    private:
        int electricGauge;
    public:
        HybridCar(int n1, int n2) : Car(n1), electricGauge(n2){}
        int GetElecGauge(){
            return electricGauge;
        }
};

class HybridWaterCar : public HybridCar {
    private:
        int waterGauge;
    public:
        HybridWaterCar(int n1, int n2, int n3) : HybridCar(n1, n2), waterGauge(n3) {}
        void ShowCurrentGauage(){
            cout << "Gasoline: " << GetGasGuage() << endl;
            cout << "Electric: " << GetElecGauge() << endl;
            cout << "water: " << waterGauge << endl; 
        }
};

int main(void){
    HybridWaterCar s1(10, 20, 30);
    s1.ShowCurrentGauage();
    return 0;
}