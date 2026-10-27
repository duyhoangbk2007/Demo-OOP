#include <iostream>
#include "Vector.h"
using namespace std;

int main() {
    Vector v1(3);
    Vector v2(4);
    v2 = v1;
    cout << v2;
}