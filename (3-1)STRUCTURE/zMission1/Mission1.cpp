#include <iostream>
using namespace std;

struct Point{
    int xpos;
    int ypos;

    void MovePos(int dx, int dy){
        xpos += dx;
        ypos += dy;
    }

    void AddPoint(const Point &pos){
        xpos += pos.xpos;
        ypos += pos.ypos;
    }

    void ShowPosition(){
        cout << "xpos: " << xpos << " ";
        cout << "ypos: " << ypos << endl;
    }
};

int main(void) {
    Point pos1 = {12, 4};
    Point pos2 = {20, 30};

    pos1.MovePos(-7, 10);
    pos1.ShowPosition();

    pos1.AddPoint(pos2);
    pos1.ShowPosition();
    return 0;
}