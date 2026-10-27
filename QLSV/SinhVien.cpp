#include "SinhVien.h"
#include "XuLyChuoi.h"

SinhVien::SinhVien() {
    this->maSV = nullptr;
    this->hoTen = nullptr;
    this->lop = nullptr;
    this->diemTB = 0;
}

SinhVien::~SinhVien() {
    delete[] this->maSV;
    delete[] this->hoTen;
    delete[] this->lop;
}

const char* SinhVien::getMaSV() const {
    return this->maSV;
}

double SinhVien::getDiemTB() const {
    return this->diemTB;
}

void SinhVien::setMaSV(const char* ma) {
    char* duLieuMoi = nullptr;
    if (ma != nullptr) {
        duLieuMoi = new char[doDaiChuoi(ma) + 1];
        saoChepChuoi(duLieuMoi, ma);
    }
    delete[] this->maSV;
    this->maSV = duLieuMoi;
}

void SinhVien::setHoTen(const char* ten) {
    char* duLieuMoi = nullptr;
    if (ten != nullptr) {
        duLieuMoi = new char[doDaiChuoi(ten) + 1];
        saoChepChuoi(duLieuMoi, ten);
    }
    delete[] this->hoTen;
    this->hoTen = duLieuMoi;
}

void SinhVien::setLop(const char* tenLop) {
    char* duLieuMoi = nullptr;
    if (tenLop != nullptr) {
        duLieuMoi = new char[doDaiChuoi(tenLop) + 1];
        saoChepChuoi(duLieuMoi, tenLop);
    }
    delete[] this->lop;
    this->lop = duLieuMoi;
}

void SinhVien::setDiemTB(double diem) {
    this->diemTB = diem;
}

SinhVien& SinhVien::operator=(const SinhVien& sv) {
    if (this == &sv) {
        return *this;
    }
    this->setMaSV(sv.maSV);
    this->setHoTen(sv.hoTen);
    this->setLop(sv.lop);
    this->diemTB = sv.diemTB;
    return *this;
}

istream& operator>>(istream& in, SinhVien& sv) {
    char tam[100];
    double diem;

    cout << "Nhap ma sinh vien: ";
    in.getline(tam, 100);
    if (in.fail()) {
        in.clear();
        in.ignore(1000, '\n');
    }
    while (tam[0] == '\0') {
        cout << "Ma sinh vien khong duoc rong. Nhap lai: ";
        in.getline(tam, 100);
        if (in.fail()) {
            in.clear();
            in.ignore(1000, '\n');
        }
    }
    sv.setMaSV(tam);

    cout << "Nhap ho ten: ";
    in.getline(tam, 100);
    if (in.fail()) {
        in.clear();
        in.ignore(1000, '\n');
    }
    sv.setHoTen(tam);

    cout << "Nhap lop: ";
    in.getline(tam, 100);
    if (in.fail()) {
        in.clear();
        in.ignore(1000, '\n');
    }
    sv.setLop(tam);

    cout << "Nhap diem trung binh (0 - 10): ";
    while (!(in >> diem) || diem < 0 || diem > 10) {
        cout << "Diem khong hop le. Nhap lai (0 - 10): ";
        in.clear();
        in.ignore(1000, '\n');
    }
    sv.setDiemTB(diem);
    in.ignore(1000, '\n');

    return in;
}

ostream& operator<<(ostream& out, const SinhVien& sv) {
    out << "Ma sinh vien: " << (sv.maSV == nullptr ? "" : sv.maSV) << endl;
    out << "Ho ten: " << (sv.hoTen == nullptr ? "" : sv.hoTen) << endl;
    out << "Lop: " << (sv.lop == nullptr ? "" : sv.lop) << endl;
    out << "Diem trung binh: " << sv.diemTB << endl;
    return out;
}
