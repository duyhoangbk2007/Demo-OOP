#include <iostream>
#include "Matrix.h"
using namespace std;

int main() {
    Matrix m1(2,3);
    m1(1,2) = 9;
    cout << m1;
}