#ifndef DSSV_H
#define DSSV_H

#include "SinhVien.h"

class DSSV {
private:
    SinhVien* ds;
    int soLuong;

public:
    DSSV();
    ~DSSV();

    int timTheoMa(const char* ma) const;
    bool them(const SinhVien& sv);
    bool xoaTheoMa(const char* ma);
    bool suaTheoMa(const char* maCu, const SinhVien& thongTinMoi);
    bool xuatTheoMa(const char* ma, ostream& out) const;
    void duyet(ostream& out) const;
    void sapXep(bool (*hamSoSanh)(const SinhVien&, const SinhVien&));
    static bool soSanhTang(const SinhVien& sv1, const SinhVien& sv2);
    static bool soSanhGiam(const SinhVien& sv1, const SinhVien& sv2);
};

#endif
