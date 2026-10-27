#include "Point.h"
class Point3D: public Point
{
    private:
        //xVal, yVal
        int zVal;
    public:
        //Show()
        Point3D(const int&, const int&, const int&);
        ~Point3D();
        void Show3D();
};