#include "P1.h"
#include "P2.h"
class C: public P1, public P2
{
    private:
        int c;
    public:
        C(const int&, const int&, const int&, const int&, const int&);
        ~C();
        void CC();   
        void PP();
};