#ifndef SINHVIEN_H
#define SINHVIEN_H

#include <iostream>

using namespace std;

class SinhVien {
private:
    char* maSV;
    char* hoTen;
    char* lop;
    double diemTB;

public:
    SinhVien();
    ~SinhVien();
    
    const char* getMaSV() const;
    double getDiemTB() const;
    void setMaSV(const char* ma);
    void setHoTen(const char* ten);
    void setLop(const char* tenLop);
    void setDiemTB(double diem);
    
    SinhVien& operator=(const SinhVien& sv);
    friend istream& operator>>(istream& in, SinhVien& sv);
    friend ostream& operator<<(ostream& out, const SinhVien& sv);
};

#endif
