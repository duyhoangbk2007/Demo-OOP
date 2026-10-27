#include "IntSet.h"
class RealSet
{
    private:
        double *p;
        int n;
    public:
        RealSet(const int&);
        ~RealSet();
        void Show();
        friend void IntSet::SetToReal(RealSet&);
};