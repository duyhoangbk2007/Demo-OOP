#ifndef DSSV_H
#define DSSV_H

#include "SinhVien.h"

class DSSV {
private:
    SinhVien* ds;
    int soLuong;


public:
    DSSV();
    DSSV(const DSSV& other);
    ~DSSV();
    
    int getSoLuong() const;
    int timTheoMa(const char* ma) const;
    void themSinhVien();
    void suaSinhVien();
    void xoaSinhVien();
    void xuatMotSinhVien() const;
    void xuatDanhSach() const;
    void sapXep(bool (*soSanh)(const SinhVien&, const SinhVien&));
    static bool soSanhTang(const SinhVien& a, const SinhVien& b);
    static bool soSanhGiam(const SinhVien& a, const SinhVien& b);
};

#endif
