#include <iostream>
#include <cstring>
using namespace std;

class Rectangle{
    private:
        int width;
        int height;
    public:
        Rectangle(int w, int h) : width(w), height(h) {}
        void ShowAreaInfo() {
            cout << "면적 : " << width * height << endl;
        }
};

class Square : public Rectangle {
    public:
        Square(int w) : Rectangle(w, w) {}
};


int main(void){
    Rectangle rec(4, 3);
    rec.ShowAreaInfo();

    Square sqr(7);
    sqr.ShowAreaInfo();
    return 0;
}