#include "SVCNTT.h"
#include "SVCK.h"
#include <iostream>
using namespace std;

int main() {
    SV** p = new SV*[2];

    p[0] = new SVCNTT("", "", 0, 0);
    p[1] = new SVCK("", "", 0, 0, 0);

    p[0]->Input();
    p[1]->Input();

    p[0]->Output();
    p[1]->Output();

    delete p[0];
    delete p[1];
    delete[] p;

    return 0;
}