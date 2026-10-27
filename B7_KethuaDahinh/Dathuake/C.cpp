#include "C.h"
C::C(const int& x, const int& y, const int& z, const int& t, const int& k)
{
    this->P1::d = t;
    this->P2::d = k;
    this->c = z;
}
C::~C()
{
    cout << "Huy C" << endl;
}
void C::CC()
{
    cout << "CC" << endl;
}
void C::PP()
{
    cout << "PP - C" << endl;
}