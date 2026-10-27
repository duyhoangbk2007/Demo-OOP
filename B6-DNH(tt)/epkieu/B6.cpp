#include <iostream>
#include "Number.h"
using namespace std;

int main() {
    Number n1(1.1);
    int x = int(n1);
    double y = double(n1);
    cout << x << ", " << y << endl;
}