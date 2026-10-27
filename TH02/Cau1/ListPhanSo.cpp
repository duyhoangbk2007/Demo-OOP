#include "ListPhanSo.h"

ListPhanSo::ListPhanSo(int n) {
    this->n = (n >= 0) ? n : 0;
    this->ds = new PhanSo[this->n];
}

ListPhanSo::~ListPhanSo() {
    delete[] this->ds;
}

PhanSo& ListPhanSo::operator[](int index) {
    static PhanSo temp;
    if (index >= 0 && index < this->n)
        return *(this->ds + index);
    return temp;
}

istream& operator>>(istream& is, ListPhanSo& list) {
    int n;
    cout << "Nhap so luong phan so: ";
    is >> n;
    delete[] list.ds;
    list.n = n;
    list.ds = new PhanSo[list.n];
    for (int i = 0; i < n; i++) {
        is >> list.ds[i];
    }
    return is;
}

ostream& operator<<(ostream& os, const ListPhanSo& list) {
    for (int i = 0; i < list.n; i++) {
        os << list.ds[i] << " ";
    }

    return os;
}
