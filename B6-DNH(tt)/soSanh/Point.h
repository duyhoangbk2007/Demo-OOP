#include <iostream>
using namespace std;
class Point
{
    public:
        int xVal;
        int yVal;
    public:
        Point();
        Point(const Point&);
        Point(const int&, const int&);
        ~Point();
        void Show();
        friend Point operator+(const Point&, const Point&);
        Point operator-(const Point&);
        friend ostream& operator<<(ostream&, const Point&);
        friend ostream& operator<<(const Point&, ostream&);
        friend istream& operator>>(istream&, Point&);
        Point& operator++ (); //prefix
        const Point operator++ (int); //postfix
};