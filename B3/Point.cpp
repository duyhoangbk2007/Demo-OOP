#include <iostream>
#include "Point.h"
using namespace std;

void Point::TT(const int& x) {
    this->xVal += x;
    this->yVal += x;
}
void Point::Show() {
    cout << this->xVal << ", " << this->yVal << endl;
}
Point::Point() {
    this->xVal = 0;
    this->yVal = 0;
}
Point::Point(const Point& p) {
    this->xVal = p.xVal;
    this->yVal = p.yVal;
}
Point::Point(const int& xVal, const int& yVal) {
    this->xVal = xVal;
    this->yVal = yVal;
}
Point::~Point() {
    cout << "Huy Point: " << this->xVal << ", " << this->yVal << endl;
    
}
