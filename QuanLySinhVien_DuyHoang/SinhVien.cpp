#include "SinhVien.h"

int doDaiChuoi(const char* s) {
    int dem = 0;
    while (s[dem] != '\0') dem++;
    return dem;
}

void saoChepChuoi(char* dich, const char* nguon) {
    int i = 0;
    while (nguon[i] != '\0') { 
        dich[i] = nguon[i]; 
        i++; 
    }
    dich[i] = '\0';
}

bool haiChuoiBangNhau(const char* s1, const char* s2) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) return false;
        i++;
    }
    return s1[i] == s2[i];
}

SinhVien::SinhVien() {
    this->maSV = nullptr; 
    this->hoTen = nullptr; 
    this->lop = nullptr;
    this->gioiTinh[0] = '\0';
    this->ngaySinh[0] = '\0'; 
    this->diemTB = 0;
}

SinhVien::SinhVien(const SinhVien& sv) {
    this->maSV = nullptr; 
    this->hoTen = nullptr; 
    this->lop = nullptr;
    this->setMaSV(sv.maSV); 
    this->setHoTen(sv.hoTen); 
    this->setLop(sv.lop);
    saoChepChuoi(this->gioiTinh, sv.gioiTinh);
    saoChepChuoi(this->ngaySinh, sv.ngaySinh);
    this->diemTB = sv.diemTB;
}

SinhVien::~SinhVien() {
    delete[] this->maSV;
    delete[] this->hoTen;
    delete[] this->lop;
}

const char* SinhVien::getMaSV() const {
    return this->maSV;
}
const char* SinhVien::getHoTen() const {
    return this->hoTen;
}
const char* SinhVien::getLop() const {
    return this->lop;
}
const char* SinhVien::getGioiTinh() const {
    return this->gioiTinh;
}
const char* SinhVien::getNgaySinh() const {
    return this->ngaySinh;
}
float SinhVien::getDiemTB() const {
    return this->diemTB;
}

void SinhVien::setMaSV(const char* ma) {
    delete[] this->maSV;
    if (ma == nullptr) { 
        this->maSV = nullptr; 
        return; 
    }
    int n = doDaiChuoi(ma);
    this->maSV = new char[n + 1]; 
    saoChepChuoi(this->maSV, ma);
}

void SinhVien::setHoTen(const char* ten) {
    delete[] this->hoTen;
    if (ten == nullptr) { 
        this->hoTen = nullptr; 
        return; 
    }
    int n = doDaiChuoi(ten);
    this->hoTen = new char[n + 1]; 
    saoChepChuoi(this->hoTen, ten);
}

void SinhVien::setLop(const char* l) {
    delete[] this->lop;
    if (l == nullptr) { 
        this->lop = nullptr; 
        return; 
    }
    int n = doDaiChuoi(l);
    this->lop = new char[n + 1]; 
    saoChepChuoi(this->lop, l);
}

void SinhVien::setGioiTinh(const char* gt) {
    saoChepChuoi(this->gioiTinh, gt);
}
void SinhVien::setNgaySinh(const char* ns) {
    saoChepChuoi(this->ngaySinh, ns);
}
void SinhVien::setDiemTB(float diem) {
    this->diemTB = diem;
}

SinhVien& SinhVien::operator=(const SinhVien& sv) {
    if (this == &sv) return *this;
    this->setMaSV(sv.maSV);
    this->setHoTen(sv.hoTen);
    this->setLop(sv.lop);
    saoChepChuoi(this->gioiTinh, sv.gioiTinh);
    saoChepChuoi(this->ngaySinh, sv.ngaySinh);
    this->diemTB = sv.diemTB;
    return *this;
}

istream& operator>>(istream& in, SinhVien& sv) {
    char temp[100];
    in.ignore();

    cout << "Nhap ma sinh vien: ";
    in.getline(temp, 100);
    sv.setMaSV(temp);

    cout << "Nhap ho ten: ";
    in.getline(temp, 100);
    sv.setHoTen(temp);

    cout << "Nhap lop: ";
    in.getline(temp, 100);
    sv.setLop(temp);

    cout << "Nhap gioi tinh (Nam/Nu/Khac): ";
    in.getline(sv.gioiTinh, 5);

    cout << "Nhap ngay sinh (dd/mm/yyyy): ";
    in.getline(sv.ngaySinh, 11);

    cout << "Nhap diem trung binh: ";
    in >> sv.diemTB;

    return in;
}

ostream& operator<<(ostream& out, const SinhVien& sv) {
    out << "Ma SV: "; 
    if (sv.maSV != nullptr) out << sv.maSV;
    out << endl << "Ho ten: "; 
    if (sv.hoTen != nullptr) out << sv.hoTen;
    out << endl << "Lop: "; 
    if (sv.lop != nullptr) out << sv.lop;
    out << "Gioi tinh: " << sv.gioiTinh << endl;
    out << "Ngay sinh: " << sv.ngaySinh << endl;
    out << "Diem TB: " << sv.diemTB << endl;
    return out;
}
