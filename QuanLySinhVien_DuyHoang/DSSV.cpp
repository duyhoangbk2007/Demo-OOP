#include "DSSV.h"

DSSV::DSSV() { 
    ds = nullptr; 
    soLuong = 0; 
}

DSSV::DSSV(const DSSV& other) {
    soLuong = other.soLuong;
    ds = soLuong > 0 ? new SinhVien[soLuong] : nullptr;
    for (int i = 0; i < soLuong; i++) ds[i] = other.ds[i];
}

DSSV::~DSSV() { 
    delete[] ds; 
}


int DSSV::getSoLuong() const { return soLuong; }

int DSSV::timTheoMa(const char* ma) const {
    for (int i = 0; i < soLuong; i++)
        if (ds[i].getMaSV() != nullptr && haiChuoiBangNhau(ds[i].getMaSV(), ma)) 
            return i;
    return -1;
}

void DSSV::themSinhVien() {
    SinhVien sv;
    cout << "\n--- NHAP SINH VIEN MOI ---\n"; 
    cin >> sv;
    if (timTheoMa(sv.getMaSV()) != -1) { 
        cout << "Ma sinh vien da ton tai!\n"; 
        return; 
    }
    SinhVien* temp = new SinhVien[soLuong + 1];
    for (int i = 0; i < soLuong; i++) 
        temp[i] = ds[i];
    temp[soLuong] = sv;
    delete[] ds; 
    ds = temp; 
    soLuong++;
    cout << "Them sinh vien thanh cong!\n";
}

void DSSV::suaSinhVien() {
    char ma[100]; 
    cin.ignore();
    cout << "Nhap ma sinh vien can sua: "; 
    cin.getline(ma, 100);
    int viTri = timTheoMa(ma);
    if (viTri == -1) { 
        cout << "Khong tim thay sinh vien!\n"; 
        return; 
    }
    char temp[100]; 
    float diem;
    cout << "Nhap ho ten moi: "; 
    cin.getline(temp, 100); 
    ds[viTri].setHoTen(temp);
    cout << "Nhap lop moi: "; 
    cin.getline(temp, 100); 
    ds[viTri].setLop(temp);
    cout << "Nhap gioi tinh moi: "; 
    cin.getline(temp, 100); 
    ds[viTri].setGioiTinh(temp);
    cout << "Nhap ngay sinh moi: "; 
    cin.getline(temp, 100); 
    ds[viTri].setNgaySinh(temp);
    cout << "Nhap diem trung binh moi: "; 
    cin >> diem; 
    ds[viTri].setDiemTB(diem);
    cout << "Sua sinh vien thanh cong!\n";
}

void DSSV::xoaSinhVien() {
    if (soLuong == 0) { 
        cout << "Danh sach rong!\n"; 
        return; 
    }
    char ma[100]; 
    cin.ignore();
    cout << "Nhap ma sinh vien can xoa: "; 
    cin.getline(ma, 100);
    int viTri = timTheoMa(ma);
    if (viTri == -1) { 
        cout << "Khong tim thay sinh vien!\n"; 
        return; 
    }
    if (soLuong == 1) {
        delete[] ds; 
        ds = nullptr; 
        soLuong = 0;
        cout << "Xoa sinh vien thanh cong!\n"; 
        return;
    }
    SinhVien* temp = new SinhVien[soLuong - 1];
    int j = 0;
    for (int i = 0; i < soLuong; i++) {
        if (i != viTri) temp[j++] = ds[i];
    }
    delete[] ds; 
    ds = temp; 
    soLuong--;
    cout << "Xoa sinh vien thanh cong!\n";
}

void DSSV::xuatMotSinhVien() const {
    char ma[100]; 
    cin.ignore();
    cout << "Nhap ma sinh vien: "; 
    cin.getline(ma, 100);
    int viTri = timTheoMa(ma);
    if (viTri == -1) { 
        cout << "Khong tim thay sinh vien!\n"; 
        return; 
    }
    cout << "\n--- THONG TIN SINH VIEN ---\n" << ds[viTri];
}

void DSSV::xuatDanhSach() const {
    if (soLuong == 0) { 
        cout << "Danh sach rong!\n"; 
        return; 
    }
    cout << "\n===== DANH SACH SINH VIEN =====\n";
    for (int i = 0; i < soLuong; i++) 
        cout << "\nSinh vien thu " << i + 1 << ":\n" << ds[i];
}

bool DSSV::soSanhTang(const SinhVien& a, const SinhVien& b) {
    return a.getDiemTB() > b.getDiemTB();
}

bool DSSV::soSanhGiam(const SinhVien& a, const SinhVien& b) {
    return a.getDiemTB() < b.getDiemTB();
}

void DSSV::sapXep(bool (*soSanh)(const SinhVien&, const SinhVien&)) {
    for (int i = 0; i < soLuong - 1; i++) {
        for (int j = i + 1; j < soLuong; j++) {
            if (soSanh(ds[i], ds[j])) {
                SinhVien temp = ds[i]; 
                ds[i] = ds[j]; 
                ds[j] = temp;
            }
        }
    }
}
