#include <iostream>
#include "Point.h"
using namespace std;

int main() {
    Point p1(1,2);
    Point p2(2,3);
    Point p3 = p1 + p2;
    Point p4 = operator+(p1,p2);
    p3.Show();
    p4.Show();
    Point p5 = p2 - p1;
    Point p6 = p1 - p2;
    p5.Show();
    p6.Show();
}