#include <iostream>
#include "ArrayTemplate.h"
#include "PointTemplate.h"
using namespace std;

int main(void) {
    BoundCheckArray<Point<int>> oarr1(3);
    oarr1[0] = Point<int>(3, 4);
    oarr1[1] = Point<int>(5, 6);
    oarr1[2] = Point<int>(7, 8);

    for (int i=0; i<oarr1.GetArrlen(); i++) {
        oarr1[i].ShowPosition();
    }

    BoundCheckArray<Point<double>> oarr2(3);
    oarr2[0] = Point<double>(3.14, 4.31);
    oarr2[1] = Point<double>(3.14, 4.31);
    oarr2[2] = Point<double>(3.14, 4.31);
}