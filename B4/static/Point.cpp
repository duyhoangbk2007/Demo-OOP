#include <iostream>
#include "Point.h"
using namespace std;

int Point::n = 0;
void Point::TT(const int& x) {
    this->xVal += x;
    this->yVal += x;
}
void Point::Show() {
    cout << this->xVal << ", " << this->yVal << endl;
    cout << this->z << endl;
}
Point::Point() 
    : xVal(0), yVal(0), z(5)
{
    this->xVal = 1;
    this->yVal = 1;
    Point::n++;
}
// Point::Point(const Point& p) {
//     this->xVal = p.xVal;
//     this->yVal = p.yVal;
// }
// Point::Point(const int& xVal, const int& yVal) {
//     this->xVal = xVal;
//     this->yVal = yVal;
// }
Point::~Point() {
    //cout << "Huy Point: " << this->xVal << ", " << this->yVal << endl;
    Point::n--;
}
//get
int Point::Get_xVal()
{
    return this->xVal;
}
//set
void Point::Set_xVal(const int& x)
{
    this->xVal = x;
}
