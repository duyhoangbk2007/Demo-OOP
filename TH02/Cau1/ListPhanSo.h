#include "PhanSo.h"

class ListPhanSo {
private:
    PhanSo* ds;
    int n;

public:
    ListPhanSo(int n = 0);
    ~ListPhanSo();
    PhanSo& operator[](int index);

    friend istream& operator>>(istream& is, ListPhanSo& list);
    friend ostream& operator<<(ostream& os, const ListPhanSo& list);
};
