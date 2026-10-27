#include "Point3D.h"
class Point4D : public Point3D
{
    private:
        int tVal;
    public:
        Point4D(const int&, const int&, const int&, const int&);
        ~Point4D();
        void Show();
};