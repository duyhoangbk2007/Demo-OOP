#include "ListPhanSo.h"

int main() {
    PhanSo a(1, 2), b(1, 3);
    cout << "Tong: " << a + b << ", Hieu: " << a - b << endl;
    cout << "Tich: " << a * b << ", Thuong: " << a / b << endl;
    
    ListPhanSo list(2);
    list[0] = a; list[1] = b;
    cout << "Danh sach: " << list << endl;
    return 0;
}
