#include <iostream>
#include "TG.h"
using namespace std;

int main() {
    TG t2(Point(1,2), Point(2,3), Point(3,4));
    TG t1(1, 2, 3, 4, 5, 6);
    t2.Show();
    t1.Show();
}