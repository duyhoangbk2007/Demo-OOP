#include <iostream>
#include "RealSet.h"
using namespace std;

int main() {
    IntSet i1(3);
    RealSet r1(4);
    i1.SetToReal(r1);
    r1.Show();
}