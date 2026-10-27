#include "SV.h"

class SVCNTT: public SV {
    private:
        double DM1;
        double DM2;
    public:
        SVCNTT(const string& = "", const string& = "", double = 0, double = 0);
        double GPA() override;
        void Input() override;
        void Output() override;
};