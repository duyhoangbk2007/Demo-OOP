#include "DSSV.h"
#include "XuLyChuoi.h"

bool DSSV::soSanhTang(const SinhVien& sv1, const SinhVien& sv2) {
    return sv1.getDiemTB() > sv2.getDiemTB();
}

bool DSSV::soSanhGiam(const SinhVien& sv1, const SinhVien& sv2) {
    return sv1.getDiemTB() < sv2.getDiemTB();
}

DSSV::DSSV() {
    this->ds = nullptr;
    this->soLuong = 0;
}

DSSV::~DSSV() {
    delete[] this->ds;
}

int DSSV::timTheoMa(const char* ma) const {
    for (int i = 0; i < this->soLuong; i++) {
        if (haiChuoiBangNhau(this->ds[i].getMaSV(), ma)) {
            return i;
        }
    }
    return -1;
}

bool DSSV::them(const SinhVien& sv) {
    if (sv.getMaSV() == nullptr || sv.getMaSV()[0] == '\0') {
        return false;
    }
    if (this->timTheoMa(sv.getMaSV()) != -1) {
        return false;
    }

    SinhVien* dsMoi = new SinhVien[this->soLuong + 1];
    for (int i = 0; i < this->soLuong; i++) {
        dsMoi[i] = this->ds[i];
    }
    dsMoi[this->soLuong] = sv;

    delete[] this->ds;
    this->ds = dsMoi;
    this->soLuong++;
    return true;
}

bool DSSV::xoaTheoMa(const char* ma) {
    int viTri = this->timTheoMa(ma);
    if (viTri == -1) {
        return false;
    }
    if (this->soLuong == 1) {
        delete[] this->ds;
        this->ds = nullptr;
        this->soLuong = 0;
        return true;
    }
    SinhVien* dsMoi = new SinhVien[this->soLuong - 1];
    int j = 0;

    for (int i = 0; i < this->soLuong; i++) {
        if (i != viTri) {
            dsMoi[j] = this->ds[i];
            j++;
        }
    }
    delete[] this->ds;
    this->ds = dsMoi;
    this->soLuong--;
    return true;
}

bool DSSV::suaTheoMa(const char* maCu, const SinhVien& thongTinMoi) {
    int viTriCu = this->timTheoMa(maCu);
    if (viTriCu == -1) {
        return false;
    }

    if (thongTinMoi.getMaSV() == nullptr ||
        thongTinMoi.getMaSV()[0] == '\0') {
        return false;
    }

    int viTriMoi = this->timTheoMa(thongTinMoi.getMaSV());
    if (viTriMoi != -1 && viTriMoi != viTriCu) {
        return false;
    }

    this->ds[viTriCu] = thongTinMoi;
    return true;
}

bool DSSV::xuatTheoMa(const char* ma, ostream& out) const {
    int viTri = this->timTheoMa(ma);
    if (viTri == -1) {
        return false;
    }

    out << this->ds[viTri];
    return true;
}

void DSSV::sapXep(bool (*hamSoSanh)(const SinhVien&, const SinhVien&)) {
    if (hamSoSanh == nullptr) {
        return;
    }

    for (int i = 0; i < this->soLuong - 1; i++) {
        for (int j = i + 1; j < this->soLuong; j++) {
            if (hamSoSanh(this->ds[i], this->ds[j])) {
                SinhVien tam;
                tam = this->ds[i];
                this->ds[i] = this->ds[j];
                this->ds[j] = tam;
            }
        }
    }
}

void DSSV::duyet(ostream& out) const {
    if (this->soLuong == 0) {
        out << "Danh sach rong!\n";
        return;
    }

    for (int i = 0; i < this->soLuong; i++) {
        out << "\n--- Sinh vien thu " << i + 1 << " ---\n";
        out << this->ds[i];
    }
}
