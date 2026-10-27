#include <iostream>
#include "Point.h"
using namespace std;

int main() {
    Point p1(1,2);
    Point p2(1,2);
    Point p3 = ++p1;
    Point p4 = p2++;
    cout << p1 << p3;
    cout << p2 << p4;
}