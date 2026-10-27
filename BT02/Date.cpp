#include "Date.h"

#include <iomanip>
#include <stdexcept>

using namespace std;

Date::Date() : ngay(1), thang(1), nam(1970)
{}
Date::Date(int ngay, int thang, int nam)
    : ngay(ngay), thang(thang), nam(nam)
{}

bool Date::laNamNhuan(int nam)
{
    return nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0);
}

int Date::soNgayTrongThang(int thang, int nam)
{
    if (thang == 2) {
        if (laNamNhuan(nam))
            return 29;
        else
            return 28;
    }
    if (thang == 4 || thang == 6 || thang == 9 || thang == 11) {
        return 30;
    }
    return 31;
}
bool Date::hopLe() const
{
    return nam >= 1 && thang >= 1 && thang <= 12 && ngay >= 1 && ngay <= soNgayTrongThang(thang, nam);
}

Date& Date::operator++()
{
    if (ngay < soNgayTrongThang(thang, nam))
        ++ngay;
    else
    {
        ngay = 1;
        if (thang < 12)
            ++thang;
        else
        {
            thang = 1;
            ++nam;
        }
    }
    return *this;
}

const Date Date::operator++(int)
{
    Date d(*this);
    ++(*this);
    return d;
}

Date& Date::operator--()
{
    ngay--;
    if (ngay == 0) {
        thang--;
        if (thang == 0) {
            thang = 12;
            nam--;
        }
        ngay = soNgayTrongThang(thang, nam);
    }
    return *this;
}

const Date Date::operator--(int)
{
    Date d(*this);
    --(*this);
    return d;
}

Date& Date::operator+=(int soNgay)
{
    for (int i = 0; i < soNgay; i++) {
        ++(*this);
    }
    return *this;
}

istream& operator>>(istream& in, Date& d)
{
    in >> d.ngay >> d.thang >> d.nam;
    return in;
}

ostream& operator<<(ostream& o, const Date& d)
{
    o << d.ngay << "/" << d.thang << "/" << d.nam;
    return o;
}
