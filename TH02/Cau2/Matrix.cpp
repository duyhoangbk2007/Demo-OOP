#include "Matrix.h"
Matrix::Matrix(const int& r, const int& c) : r(r), c(c)
{
    this->p = new int*[this->r];
    for (int i = 0; i < this->r; i++)
    {
        *(this->p + i) = new int[this->c];
    }
}
Matrix::Matrix(const Matrix& m) : r(m.r), c(m.c)
{
    this->p = new int*[this->r];
    for (int i = 0; i < this->r; i++)
    {
        *(this->p + i) = new int[this->c];
        for (int j = 0; j < this->c; j++)
        {
            *(*(this->p + i) + j) = *(*(m.p + i) + j);
        }
    }
}
Matrix::~Matrix()
{
    for (int i = 0; i < this->r; i++)
    {
        delete[] *(this->p + i);
    }
    delete[] this->p;
}
const Matrix& Matrix::operator=(const Matrix& m)
{
    if (this != &m)
    {
        for (int i = 0; i < this->r; i++)
        {
            delete[] *(this->p + i);
        }
        delete[] this->p;

        this->r = m.r;
        this->c = m.c;
        this->p = new int*[this->r];
        for (int i = 0; i < this->r; i++)
        {
            *(this->p + i) = new int[this->c];
            for (int j = 0; j < this->c; j++)
            {
                *(*(this->p + i) + j) = *(*(m.p + i) + j);
            }
        }
    }
    return *this;
}
Matrix Matrix::operator+(const Matrix& m) const
{
    if (this->r != m.r || this->c != m.c)
        return Matrix(0, 0);

    Matrix ketQua(this->r, this->c);
    for (int i = 0; i < this->r; i++)
    {
        for (int j = 0; j < this->c; j++)
        {
            ketQua.p[i][j] = this->p[i][j] + m.p[i][j];
        }
    }
    return ketQua;
}
Matrix Matrix::operator-(const Matrix& m) const
{
    if (this->r != m.r || this->c != m.c)
        return Matrix(0, 0);

    Matrix ketQua(this->r, this->c);
    for (int i = 0; i < this->r; i++)
    {
        for (int j = 0; j < this->c; j++)
        {
            ketQua.p[i][j] = this->p[i][j] - m.p[i][j];
        }
    }
    return ketQua;
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
    static int temp = 0;
    if (r >= 0 && r < this->r && c >= 0 && c < this->c) {
        return *(*(this->p + r) + c);
    }
    else
        return temp;
}
