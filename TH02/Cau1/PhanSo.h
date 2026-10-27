#include <iostream>
using namespace std;

class PhanSo {
private:
    int tu;
    int mau;
    void rutGon();

public:
    PhanSo(int tu = 0, int mau = 1);

    PhanSo operator+(const PhanSo& other) const;
    PhanSo operator-(const PhanSo& other) const;
    PhanSo operator*(const PhanSo& other) const;
    PhanSo operator/(const PhanSo& other) const;
    friend ostream& operator<<(ostream& os, const PhanSo& ps);
    friend istream& operator>>(istream& is, PhanSo& ps);
};
