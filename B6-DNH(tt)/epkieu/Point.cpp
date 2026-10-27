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
    return Point (p1.xVal + p2.xVal, p1.yVal + p2.yVal);
}

Point Point::operator-(const Point& q) {
    return Point (this->xVal - q.xVal, this->yVal - q.yVal);

}

ostream& operator<<(ostream& o, const Point& p) {
    o << p.xVal << ", " << p.yVal << endl;
    return o;
}
ostream& operator<<(const Point& p, ostream& o) {
    o << p.xVal << ", " << p.yVal << endl;
    return o;
}
istream& operator>>(istream& in, Point& p) {
    cout << "xVal = ";
    in >> p.xVal;
    cout << "yVal = ";
    in >> p.yVal;
    return in;
}
Point& Point::operator++() {
    this->xVal++;
    this->yVal++;
    return *this;
}
const Point Point::operator++(int) {
    Point p = *this;
    this->xVal++;
    this->yVal++;
    return p;
}