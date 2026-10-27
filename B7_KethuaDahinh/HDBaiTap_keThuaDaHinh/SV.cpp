#include "SV.h"

SV::SV(const string& maSV, const string& ten) : MaSV(maSV), hoTen(ten) {}

SV::~SV()
{}

void SV::Input() {
    cout << "Nhap ma sinh vien: ";
    cin >> MaSV;
    cin.ignore();
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
}

void SV::Output() {
    cout << "Ma sinh vien: " << MaSV << endl;
    cout << "Ho ten: " << hoTen << endl;
}
