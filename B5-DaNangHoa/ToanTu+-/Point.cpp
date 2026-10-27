#include "Point.h"

void Point::Show() {
    cout << this->xVal << ", " << this->yVal << endl;
}
Point::Point()
    : xVal(0), yVal(0)
{ }
Point::Point(const Point& p) {
    this->xVal = p.xVal;
    this->yVal = p.yVal;
}
Point::Point(const int& xVal, const int& yVal) {
    this->xVal = xVal;
    this->yVal = yVal;
}
Point::~Point() 
{ }

Point operator+(const Point& p1, const Point& p2)
{
    Point p(p1.xVal + p2.xVal, p1.yVal + p2.yVal);
    return p;
}

Point Point::operator-(const Point& q) {
    Point p(this->xVal - q.xVal, this->yVal - q.yVal);
    return p;
}