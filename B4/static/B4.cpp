#include <iostream>
#include "Point.h"
using namespace std;

int main() {
    // Point p1;
    // p1.Show();
    cout << Point::n << endl; //0
    Point p1; // -> n = 1
    cout << Point::n << ", " << p1.n << endl; //1,1
    Point *p = new Point;
    cout << Point::n << ", " << p1.n << ", " << p->n << endl;   //2, 2, 2
    cout << Point::m << ", " << p1.m << ", " << p->m << endl;
    delete p;
    cout << Point::n << ", " << p1.n << endl; //1, 1
}