#include "DSSV.h"

void nhapMa(char ma[], int kichThuoc) {
    cin.getline(ma, kichThuoc);

    // Neu nguoi dung nhap qua dai, xoa phan con lai tren dong.
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

void inMenu() {
    cout << "\n========== QUAN LY SINH VIEN ==========\n";
    cout << "1. Them sinh vien\n";
    cout << "2. Xoa sinh vien theo ma\n";
    cout << "3. Sua sinh vien theo ma\n";
    cout << "4. Tim sinh vien theo ma\n";
    cout << "5. Xuat danh sach sinh vien\n";
    cout << "6. Sap xep diem tang dan\n";
    cout << "7. Sap xep diem giam dan\n";
    cout << "0. Thoat\n";
    cout << "Chon chuc nang: ";
}

int main() {
    DSSV danhSach;
    int luaChon = -1;
    char ma[100];

    do {
        inMenu();

        if (!(cin >> luaChon)) {
            cout << "Lua chon khong hop le!\n";
            cin.clear();
            cin.ignore(1000, '\n');
            luaChon = -1;
            continue;
        }
        cin.ignore(1000, '\n');

        if (luaChon == 1) {
            SinhVien sv;
            cout << "\n--- THEM SINH VIEN ---\n";
            cin >> sv;

            if (danhSach.them(sv)) {
                cout << "Them sinh vien thanh cong!\n";
            } else {
                cout << "Khong the them: ma sinh vien da ton tai!\n";
            }
        } else if (luaChon == 2) {
            cout << "Nhap ma sinh vien can xoa: ";
            nhapMa(ma, 100);

            if (danhSach.xoaTheoMa(ma)) {
                cout << "Xoa sinh vien thanh cong!\n";
            } else {
                cout << "Khong tim thay sinh vien!\n";
            }
        } else if (luaChon == 3) {
            cout << "Nhap ma hien tai cua sinh vien: ";
            nhapMa(ma, 100);

            if (danhSach.timTheoMa(ma) == -1) {
                cout << "Khong tim thay sinh vien!\n";
            } else {
                SinhVien thongTinMoi;
                cout << "Nhap lai thong tin sinh vien:\n";
                cin >> thongTinMoi;

                if (danhSach.suaTheoMa(ma, thongTinMoi)) {
                    cout << "Sua sinh vien thanh cong!\n";
                } else {
                    cout << "Khong the sua: ma moi da thuoc sinh vien khac!\n";
                }
            }
        } else if (luaChon == 4) {
            cout << "Nhap ma sinh vien can tim: ";
            nhapMa(ma, 100);

            if (!danhSach.xuatTheoMa(ma, cout)) {
                cout << "Khong tim thay sinh vien!\n";
            }
        } else if (luaChon == 5) {
            danhSach.duyet(cout);
        } else if (luaChon == 6) {
            danhSach.sapXep(DSSV::soSanhTang);
            cout << "Da sap xep diem tang dan!\n";
        } else if (luaChon == 7) {
            danhSach.sapXep(DSSV::soSanhGiam);
            cout << "Da sap xep diem giam dan!\n";
        } else if (luaChon == 0) {
            cout << "Da thoat chuong trinh.\n";
        } else {
            cout << "Khong co chuc nang nay!\n";
        }
    } while (luaChon != 0);

    return 0;
}
