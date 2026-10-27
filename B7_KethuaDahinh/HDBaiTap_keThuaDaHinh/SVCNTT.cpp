#include "SVCNTT.h"

SVCNTT::SVCNTT(const string& maSV, const string& ten, double DM1, double DM2)
    : SV(maSV, ten), DM1(DM1), DM2(DM2) {}

double SVCNTT::GPA() {
    return (DM1 + DM2) / 2.0;
}

void SVCNTT::Input() {
    SV::Input();
    cout << "Diem mon 1: ";
    cin >> DM1;
    cout << "Diem mon 2: ";
    cin >> DM2;
}

void SVCNTT::Output() {
    SV::Output();
    cout << "Diem mon 1: " << DM1 << endl;
    cout << "Diem mon 2: " << DM2 << endl;
    cout << "GPA: " << GPA() << endl;
}
