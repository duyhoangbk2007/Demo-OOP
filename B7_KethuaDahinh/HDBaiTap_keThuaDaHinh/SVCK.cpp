#include "SVCK.h"

SVCK::SVCK(const string& maSV, const string& ten, double DM1, double DM2, double DPVCD)
    : SV(maSV, ten), DM1(DM1), DM2(DM2), DPVCD(DPVCD) 
{}

double SVCK::GPA() {
    return DM1*0.4 + DM2*0.4 + DPVCD*0.2;
}
void SVCK::Input() {
    SV::Input();
    cout << "Diem mon 1: ";
    cin >> DM1;
    cout << "Diem mon 2: ";
    cin >> DM2;
    cout << "Diem phuc vu cong dong: ";
    cin >> DPVCD;
}
void SVCK::Output() {
    SV::Output();
    cout << "Diem mon 1: " << DM1 << endl;
    cout << "Diem mon 2: " << DM2 << endl;
    cout << "Diem PVCD: " << DPVCD << endl;
    cout << "GPA: " << GPA() << endl;
}
