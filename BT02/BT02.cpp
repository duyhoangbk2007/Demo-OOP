#include <iostream>

#include "Date.h"

using namespace std;

int main()
{
    int ngay, thang, nam;
    cout << "Nhap ngay thang nam (vi du: 28 2 2024): ";
    if (!(cin >> ngay >> thang >> nam)) {
        cout << "Du lieu nhap khong hop le!" << endl;
        return 1;
    }
    Date d(ngay, thang, nam);
    if (!d.hopLe()) {
        cout << "Ngay khong hop le!" << endl;
        return 1;
    }
    cout << "Ngay hop le: " << d << endl;
    cout << "So ngay trong thang: " << Date::soNgayTrongThang(thang, nam) << endl;

    Date tam = d;
    cout << "Ngay ke tiep: " << ++tam << endl;

    tam = d;
    --tam;
    if (tam.hopLe()) {
        cout << "Ngay truoc do: " << tam << endl;
    }
    else {
        cout << "Khong co ngay hop le truoc ngay vua nhap." << endl;
    }

    return 0;
}
