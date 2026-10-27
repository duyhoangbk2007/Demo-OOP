#include "Point.h"

void Point::Show() {
    cout << this->xVal << ", " << this->yVal << endl;
}

Point::Point(const Point& p) {
    this->xVal = p.xVal;
    this->yVal = p.yVal;
}
Point::Point(const int& xVal, const int& yVal) {
    this->xVal = xVal;
    this->yVal = yVal;
}
Point::~Point() 
{
    cout << "Huy Point" << endl;
}

