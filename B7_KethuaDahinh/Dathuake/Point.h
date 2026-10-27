#include <iostream>
using namespace std;
class Point
{
    protected:
        int xVal;
        int yVal;
    public:
        Point(const Point&);
        Point(const int&, const int&);
        virtual ~Point();
        virtual void Show(); 
        //overload
        void A();
        void A(int);
};