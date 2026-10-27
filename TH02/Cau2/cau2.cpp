#include "Vector.h"
#include "Matrix.h"

int main() {
    Vector a(2), b(2);
    cout << "Nhap 2 toa do vector a: "; cin >> a;
    cout << "Nhap 2 toa do vector b: "; cin >> b;
    cout << "Vector tong: " << a + b;
    
    Matrix x(1, 2), y(1, 2);
    cout << "Nhap 2 phan tu matrix x: "; cin >> x;
    cout << "Nhap 2 phan tu matrix y: "; cin >> y;
    cout << "Matrix tong:\n" << x + y;
    return 0;
}
