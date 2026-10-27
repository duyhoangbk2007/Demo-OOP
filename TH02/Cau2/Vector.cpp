#include "Vector.h"
Vector::Vector(const int& n) : n(n)
{
    this->p = new int[this->n];
}
Vector::Vector(const Vector& v) : n(v.n)
{
    this->p = new int[this->n];
    for (int i = 0; i < v.n; i++)
    {
        (*this)[i] = *(v.p + i);
    }
}
Vector::~Vector()
{
    delete[] this->p;
}
ostream& operator<<(ostream& o, const Vector& v) {
    for (int i = 0; i < v.n; i++) {
        o << *(v.p + i) << " ";
    }
    o << endl;
    return o;
}
istream& operator>>(istream& in, Vector& v) {
    for (int i = 0; i < v.n; i++) {
        in >> v[i];
    }
    return in;
}
Vector Vector::operator+(const Vector& v) const {
    if (this->n != v.n) {
        return Vector(0);
    }
    Vector ketQua(this->n);
    for (int i = 0; i < this->n; i++) {
        ketQua.p[i] = this->p[i] + v.p[i];
    }
    return ketQua;
}
Vector Vector::operator-(const Vector& v) const {
    if (this->n != v.n) {
        return Vector(0);
    }
    Vector ketQua(this->n);
    for (int i = 0; i < this->n; i++) {
        ketQua.p[i] = this->p[i] - v.p[i];
    }
    return ketQua;
}
int& Vector::operator[](const int& index) {
    static int temp = 0;
    if (index >= 0 && index < this->n)
        return *(this->p + index);
    else {
        return temp;
    }
}
const Vector& Vector::operator=(const Vector& v)
{
    if(this != &v)
    {
        delete[] this->p;
        this->n = v.n;
        this->p = new int[this->n];
        for (int i = 0; i < v.n; i++)
        {
            (*this)[i] = *(v.p + i);
        }
        
    }
    return *this;
}
