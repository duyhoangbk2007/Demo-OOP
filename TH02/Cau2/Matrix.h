#include <iostream>
using namespace std;
class Matrix
{
private:
    int **p;
    int c, r;
public:
    Matrix(const int&, const int&);
    Matrix(const Matrix&);
    ~Matrix();
    const Matrix& operator=(const Matrix&);
    Matrix operator+(const Matrix&) const;
    Matrix operator-(const Matrix&) const;
    friend ostream& operator<<(ostream&, const Matrix&);
    friend istream& operator>>(istream&, Matrix&);
    int& operator()(const int&, const int&);
};

