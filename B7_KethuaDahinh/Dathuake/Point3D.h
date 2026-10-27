#include "Point.h"
class Point3D: public Point
{
    protected:
        //xVal, yVal
        int zVal;
    public:
        //Show()
        Point3D(const int&, const int&, const int&);
        virtual ~Point3D();
        void Show3D();
        void Show() override;
        
        void A();
        friend ostream& operator<<(ostream&, const Point3D&);
};