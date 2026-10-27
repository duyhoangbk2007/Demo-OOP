#include <iostream>
#include "Point.h"
using namespace std;

int main() {
    Point p1;
    p1 << cout;
    cin >> p1;
    p1 << cout;
    Point p2;
    cout << p1 << p2;
}