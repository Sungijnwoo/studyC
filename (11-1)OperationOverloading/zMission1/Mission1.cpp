#include <iostream>
#include <cstring>
using namespace std;

class Gun {
    private:
        int bullet;
    public:
        Gun(int bnum) : bullet(bnum) {}
        void Shot() {
            cout << "BBANG!" << endl;
            bullet--;
        }
        Gun& operator=(const Gun &ref){
            bullet = ref.bullet;
        }
};

class Police : public Gun {
    private:
        int handcuffs;
    public:
        Police(int bnum, int bcuff) : Gun(bnum), handcuffs(bcuff){}
        void PutHandcuff() {
            cout << "SNAP!" << endl;
            handcuffs--;
        }
        Police& operator=(const Police &ref) {
            Gun::operator=(ref);
            handcuffs = ref.handcuffs;
        }
};

int main(void) {
    Police pman(5, 3);
    pman.Shot();
    pman.PutHandcuff();
    return 0;
}