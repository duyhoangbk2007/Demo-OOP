#ifndef SINHVIEN_H
#define SINHVIEN_H

#include <iostream>

int doDaiChuoi(const char chuoi[]);
int soSanhChuoi(const char a[], const char b[]);
bool saoChepChuoi(char dich[], int kichThuocDich, const char nguon[]);
char chuyenThanhChuThuong(char kyTu);

class SinhVien {
    private:
        char* maSinhVien;
        char* hoTen;
        char* lop;
        char ngaySinh[11];
        char gioiTinh[5];
        float diemTrungBinh;

        void ganChuoi(char*& dich, const char nguon[]);

    public:
        SinhVien();
        SinhVien(const SinhVien& other);
        ~SinhVien();
        
        // Nhap lai thong tin qua cin, giu nguyen ma sinh vien.
        void capNhat();
        
        const char* getMaSinhVien() const;
        const char* getHoTen() const;
        const char* getLop() const;
        float getDiemTrungBinh() const;
        
        friend std::istream& operator>>(std::istream& in, SinhVien& sinhVien);
        friend std::ostream& operator<<(std::ostream& out, const SinhVien& sinhVien);
        SinhVien& operator=(const SinhVien& other);
};

#endif
