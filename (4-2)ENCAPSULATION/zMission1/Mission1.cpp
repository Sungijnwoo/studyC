#include <iostream>
using namespace std;


class Point{
    private:
        int xpos, ypos;
    public:
        void Init(int x, int y){
            xpos = x;
            ypos = y;
        }
        void ShowPointerInfo() const{
            cout << "[" << xpos << ", " << ypos << "]" << endl;
        }
};

class Ring{
    private:
        Point InnerCircle;
        Point OuterCircle;
        int innerR, outerR;
    public:
        void Init(int x1, int y1, int r1, int x2, int y2, int r2){
            if (r1 >= r2){
                InnerCircle.Init(x1, y1);
                OuterCircle.Init(x2, y2);
                innerR = r2;
                outerR = r1;
            }
            else {
                InnerCircle.Init(x2, y2);
                OuterCircle.Init(x1, y1);
                innerR = r1;
                outerR = r2;
            }
        }
        void ShowRingInfo(){
            cout << "Inner Circle Info.." << endl;
            cout << "radius: " << innerR << endl;
            InnerCircle.ShowPointerInfo();
            cout << "Outer Circle Info.." << endl;
            cout << "radius: " << outerR << endl;
            OuterCircle.ShowPointerInfo();
        }
};

int main(void){
    Ring ring;
    ring.Init(1, 1, 4, 2, 2, 9);
    ring.ShowRingInfo();
    return 0;
}