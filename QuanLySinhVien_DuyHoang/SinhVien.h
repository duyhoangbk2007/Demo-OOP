#ifndef SINHVIEN_H
#define SINHVIEN_H

#include <iostream>
using namespace std;

class SinhVien {
private:
    char* maSV;
    char* hoTen;
    char* lop;

    char gioiTinh[5];
    char ngaySinh[11];
    float diemTB;

public:
    SinhVien();
    SinhVien(const SinhVien& sv);
    ~SinhVien();

    const char* getMaSV() const;
    const char* getHoTen() const;
    const char* getLop() const;
    const char* getGioiTinh() const;
    const char* getNgaySinh() const;
    float getDiemTB() const;

    void setMaSV(const char* ma);
    void setHoTen(const char* ten);
    void setLop(const char* lop);
    void setGioiTinh(const char* gt);
    void setNgaySinh(const char* ns);
    void setDiemTB(float diem);

    SinhVien& operator=(const SinhVien& sv);
    friend istream& operator>>(istream& in, SinhVien& sv);
    friend ostream& operator<<(ostream& out, const SinhVien& sv);
};


int doDaiChuoi(const char* s);
void saoChepChuoi(char* dich, const char* nguon);
bool haiChuoiBangNhau(const char* s1, const char* s2);


#endif
