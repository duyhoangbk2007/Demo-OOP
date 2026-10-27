#include <iostream>
using namespace std;
class Date
{
private:
    int ngay;
    int thang;
    int nam;

    static bool laNamNhuan(int nam);

public:
    Date();
    Date(int ngay, int thang, int nam);

    bool hopLe() const;
    static int soNgayTrongThang(int thang, int nam);

    Date& operator++();
    const Date operator++(int);
    Date& operator--();
    const Date operator--(int);

    Date& operator+=(int soNgay);
    friend istream& operator>>(istream&, Date&);
    friend ostream& operator<<(std::ostream&, const Date&);
};
