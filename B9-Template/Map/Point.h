#include <iostream>
using namespace std;
class Point
{
    protected:
        int xVal;
        int yVal;
    public:
        Point(const Point&);
        Point(const int& = 1, const int& = 1);
        virtual ~Point();
        friend ostream& operator<<(ostream&, const Point&);
        friend ostream& operator<<(const Point&, ostream&);
        friend istream& operator>>(istream&, Point&);
};


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