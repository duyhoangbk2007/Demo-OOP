#include "PhanSo.h"

PhanSo::PhanSo(int tu, int mau) {
    this->tu = tu;
    this->mau = (mau != 0) ? mau : 1;
    this->rutGon();
}

void PhanSo::rutGon() {
    int a = (this->tu < 0) ? -this->tu : this->tu;
    int b = (this->mau < 0) ? -this->mau : this->mau;
    while (b != 0) {
        int du = a % b;
        a = b;
        b = du;
    }
    if (a != 0) {
        this->tu /= a;
        this->mau /= a;
    }
    if (this->mau < 0) {
        this->tu = -this->tu;
        this->mau = -this->mau;
    }
}

PhanSo PhanSo::operator+(const PhanSo& other) const {
    int t = this->tu * other.mau + other.tu * this->mau;
    int m = this->mau * other.mau;

    return PhanSo(t, m);
}

PhanSo PhanSo::operator-(const PhanSo& other) const {
    int t = this->tu * other.mau - other.tu * this->mau;
    int m = this->mau * other.mau;

    return PhanSo(t, m);
}

PhanSo PhanSo::operator*(const PhanSo& other) const {
    int t = this->tu * other.tu;
    int m = this->mau * other.mau;

    return PhanSo(t, m);
}

PhanSo PhanSo::operator/(const PhanSo& other) const {
    if (other.tu == 0) {
        cout << "Khong the chia cho 0!\n";
        return PhanSo();
    }

    int t = this->tu * other.mau;
    int m = this->mau * other.tu;

    return PhanSo(t, m);
}

ostream& operator<<(ostream& os, const PhanSo& ps) {
    os << ps.tu << "/" << ps.mau;
    return os;
}
istream& operator>>(istream& in, PhanSo& ps){
    in >> ps.tu;
    in >> ps.mau;
    while(ps.mau == 0)
    {
        cout << "mau so ko hop le nhap lai" << endl;
        in >> ps.tu;
        in >> ps.mau;
    }
    return in;
}