#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double x = 12345.6;
    cout << setiosflags(ios::showpoint) << setprecision(5);
    cout << x;
}

//Test git pull
