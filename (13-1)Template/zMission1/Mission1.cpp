#include <iostream>
using namespace std;

class Point {
    private:
        int xpos, ypos;
    public:
        Point(int x =0, int y=0) : xpos(x), ypos(y) {}
        void ShowPosition() const {
            cout << '[' << xpos << ", " << ypos << ']' << endl;
        }
};

template <typename T>

void SwapData(T& pos1, T& pos2) {
    T temp = pos1;
    pos1 = pos2;
    pos2 = temp;
}

int main(void) {
    Point pos1(3, 4);
    Point pos2(10, 20);
    SwapData(pos1, pos2);
    pos1.ShowPosition();
    pos2.ShowPosition();
}