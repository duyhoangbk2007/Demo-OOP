#include <iostream>
using namespace std;

void nhapMang(int *A, int n) {
    for (int i = 0; i < n; i++) {
        cout << "A[" << i << "] = ";
        cin >> *(A + i);
    }
}

void xuatMang(int *A, int n) {
    for (int i = 0; i < n; i++) {
        cout << *(A + i) << " ";
    }
    cout << endl;
}

void chen(int *A, int &n, int k, int x) {
    if (k < 1 || k > n) {
        cout << "Vi tri khong hop le!\n";
        return;
    }
    for (int i = n; i >= k; i--) {
        *(A + i) = *(A + i - 1);
    }
    *(A + k - 1) = x;
    n++;
}

void xoa(int *A, int &n, int k) {
    if (k < 1 || k > n) {
        cout << "Vi tri khong hop le!\n";
        return;
    }
    for (int i = k - 1; i < n - 1; i++) {
        *(A + i) = *(A + i + 1);
    }
    n--;
}

int linearSearch(int *A, int n, int x) {
    for (int i = 0; i < n; i++) {
        if (*(A + i) == x) {
            return i;
        }
    }
    return -1;
}

void capNhat(int *A, int n, int k ,int x) {
    if (k < 1 || k > n) {
        cout << "Vi tri khong hop le!\n";
        return; 
    }
    *(A + k - 1) = x;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool tangDan(int a, int b) {
    return a > b;
}

bool giamDan(int a, int b) {
    return a < b;
}

void bubbleSort(int *A, int n, bool (*compare)(int, int)) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (compare(*(A + j), *(A + j + 1))) {
                swap(A + j, A + j + 1);
            }
        }
    }
}

int main() {
    int n;
    cout << "Nhap so phan tu n = ";
    cin >> n;

    int *A = new int[n + 1];

    cout << "\n===== 1. NHAP MANG/ XUAT MANG =====\n";
    nhapMang(A, n);
    cout << "Mang A: ";
    xuatMang(A, n);

    int k, x;
    cout << "\n===== 2. CHEN =====\n";
    cout << "Nhap vi tri k can chen (1 <= k <= n): ";
    cin >> k;
    cout << "Nhap gia tri can chen: ";
    cin >> x;
    chen(A, n, k, x);
    cout << "Mang sau khi chen: ";
    xuatMang(A, n);

    cout << "\n===== 3. XOA =====\n";
    cout << "Nhap vi tri k can xoa (1 <= k <= n): ";
    cin >> k;
    xoa(A, n, k);
    cout << "Mang sau khi xoa: ";
    xuatMang(A, n);

    cout << "\n===== 4. TIM KIEM =====\n";
    cout << "Nhap gia tri can tim: ";
    cin >> x;
    int pos = linearSearch(A, n, x);
    if (pos != -1) {
        cout << "Tim thay!\n";
        cout << "Vi tri: " << pos + 1 << endl;
        cout << "Gia tri: " << *(A + pos) << endl;
    }
    else {
        cout << "Khong tim thay!\n";
    }
    
    cout << "\n===== 5. CAP NHAT =====\n";
    cout << "Nhap vi tri k can cap nhat (1 <= k <= n): ";
    cin >> k;
    cout << "Nhap gia tri moi: ";
    cin >> x;
    capNhat(A, n, k, x);
    cout << "Mang sau khi cap nhat: ";
    xuatMang(A, n);

    cout << "\n===== 6. BUBBLE SORT =====\n";
    cout << "1. Tang dan\n";
    cout << "2. Giam dan\n";
    cout << "Chon thu tu sap xep: ";
    cin >> k;

    bool (*compare)(int, int);
    if (k == 1) {
        compare = tangDan;
    }
    else {
        compare = giamDan;
    }
    bubbleSort(A, n, compare);
    cout << "Mang sau khi sap xep: ";
    xuatMang(A, n);

    delete[] A;
    return 0;
}