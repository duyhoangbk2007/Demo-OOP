#include <iostream>
#include "Point.h"
using namespace std;

void Point::Show() {
    cout << this->xVal << ", " << this->yVal << endl;
}
Point::Point() 
{
    this->xVal = 1;
    this->yVal = 1;
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
//get
int Point::Get_xVal()
{
    return this->xVal;
}
int Point::Get_yVal()
{
    return this->yVal;
}
//set
void Point::Set_xVal(const int& x)
{
    this->xVal = x;
}
void Point::Set_yVal(const int& y)
{
    this->yVal = y;
}
void Display(Point& p)
{
    p.xVal = 2;
    p.yVal = 2;
}
