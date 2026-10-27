#include "Point3D.h"
Point3D::Point3D(const int& x, const int& y, const int& z)
    : Point(x, y)
{
    this->zVal = z;
}
Point3D::~Point3D()
{
    cout << "Huy Point3D" << endl;
}
void Point3D::Show3D()
{
    cout << this->xVal << ", " << this->yVal << ", " << this->zVal << endl;
}
void Point3D::Show() {
    Point::Show();
    cout << this->zVal << endl;
}
void Point3D::A() {
    cout << "A - 3D" << endl;
}
ostream& operator<<(ostream& o, const Point3D& p) {
    o << p.xVal << ", " << p.yVal << ", " << p.zVal << endl;
    return o;
}