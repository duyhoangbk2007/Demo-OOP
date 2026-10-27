#include <iostream>
using namespace std;
#include "Map.h"
int main() {
   Map<int, double, Vector> m1(2,3);
   cout << m1;
   return 0;
}