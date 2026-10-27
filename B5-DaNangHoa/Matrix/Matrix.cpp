#include "Matrix.h"
Matrix::Matrix(const int& r, const int& c) : r(r), c(c)
{
    this->p = new int*[this->r];
    for (int i = 0; i < this->r; i++)
    {
        *(this->p + i) = new int[this->c];
    }
    
    cin >> *(this);
}
Matrix::~Matrix()
{
    for (int i = 0; i < this->r; i++)
    {
        delete[] *(this->p + i);
    }
    delete[] this->p;
}
ostream& operator<<(ostream& o, const Matrix& m) {
    for (int i = 0; i < m.r; i++)
    {
        for (int j = 0; j < m.c; j++)
        {
            o << *(*(m.p + i) + j) << " ";
        }
        o << endl;
    }
    return o;
}
istream& operator>>(istream& in, Matrix& m) {
    for (int i = 0; i < m.r; i++)
    {
        for (int j = 0; j < m.c; j++)
        {
            in >> m(i,j);
        }
    }
    return in;
}
int& Matrix::operator()(const int& r, const int& c) {
    static int NGU = 0;
    if (r >= 0 && r < this->r && c >= 0 && c < this->c) {
        return *(*(this->p + r) + c);
    }
    else
        return NGU;
}