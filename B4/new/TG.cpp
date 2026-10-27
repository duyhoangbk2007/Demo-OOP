#include "TG.h"
TG::TG(const Point& pA, const Point& pB, const Point& pC)
{
    this->A = pA; this->B = pB; this->C = pC;
}
TG::TG(const int& xA, const int& yA, const int& xB, const int& yB,const int& xC,const int& yC)
    : A(xA, yA), B(xB, yB), C(xC, yC)
{

}
TG::~TG()
{
}
void TG::Show()
{
    (this->A).Show();
    (this->B).Show();
    (this->C).Show();
}