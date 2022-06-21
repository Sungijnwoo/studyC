#include <iostream>
using namespace std;

class CountryArea{
    public:
        const static int RUSSIA = 1707540;
        const static int CANADA = 998467;
        const static int CHINA = 957290;
        const static int SOUTH_KOREA = 9922;
};

int main(void){
    cout << "Russia area: " << CountryArea::RUSSIA << "km" << endl;
    cout << "Canada area: " << CountryArea::CANADA << "km" << endl;
    cout << "China area: " << CountryArea::CHINA << "km" << endl;
    cout << "SouthKorea area: " << CountryArea::SOUTH_KOREA << "km" << endl;
    return 0;
}