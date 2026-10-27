#include "DSSV.h"

void hienThiMenu() {
    cout << "\n+=========================================+\n";
    cout << "|       CHUONG TRINH QUAN LY SINH VIEN   |\n";
    cout << "+=========================================+\n";
    cout << "| 1. Them sinh vien                       |\n";
    cout << "| 2. Sua thong tin sinh vien              |\n";
    cout << "| 3. Xoa sinh vien                        |\n";
    cout << "| 4. Tim sinh vien theo ma                |\n";
    cout << "| 5. Xuat danh sach sinh vien             |\n";
    cout << "| 6. Sap xep diem tang dan                |\n";
    cout << "| 7. Sap xep diem giam dan                |\n";
    cout << "| 0. Thoat                                 |\n";
    cout << "+=========================================+\n";
    cout << "Nhap lua chon: ";
}

int main() {
    DSSV danhSach;
    int luaChon;

    do {
        hienThiMenu();
        cin >> luaChon;

        switch (luaChon) {
            case 1:
                danhSach.themSinhVien();
                break;
            case 2:
                danhSach.suaSinhVien();
                break;
            case 3:
                danhSach.xoaSinhVien();
                break;
            case 4:
                danhSach.xuatMotSinhVien();
                break;
            case 5:
                danhSach.xuatDanhSach();
                break;
            case 6:
                danhSach.sapXep(DSSV::soSanhTang);
                cout << "Sap xep tang dan thanh cong!\n";
                danhSach.xuatDanhSach();
                break;
            case 7:
                danhSach.sapXep(DSSV::soSanhGiam);
                cout << "Sap xep giam dan thanh cong!\n";
                danhSach.xuatDanhSach();
                break;
            case 0:
                cout << "Da thoat chuong trinh!\n";
                break;
            default:
                cout << "Lua chon khong hop le!\n";
        }
    } while (luaChon != 0);

    return 0;
}
