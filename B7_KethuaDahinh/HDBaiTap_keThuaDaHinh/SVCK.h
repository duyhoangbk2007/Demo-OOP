#include "SV.h"

class SVCK : public SV {
private:
    double DM1;
    double DM2;
    double DPVCD;

public:
    SVCK(const string& = "", const string& = "", double = 0, double = 0, double = 0);
    double GPA() override;
    void Input() override;
    void Output() override;
};