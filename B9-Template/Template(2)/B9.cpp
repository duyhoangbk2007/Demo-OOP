#include <iostream>
using namespace std;
#include "Vector.h"
int main() {
   Vector<int, 2> v1;
   Vector<double, 3> v2;
   cout << v1 << endl << v2;
   return 0;
}