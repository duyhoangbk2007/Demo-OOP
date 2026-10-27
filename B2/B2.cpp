#include <iostream>
#include <iomanip>
using namespace std;

// int x = 2;
// int& A() {
//     static int y = 4;
//     return y;
// }
// int& B() {
//     return x;
// }

// const int& C() {
//     return x;
// }

// int sum(int a, int b) {
//     return a + b;
// }
// int sub(int a, int b) {
//     return a - b;
// }
// int TT(int a, int b, int (*p1)(int, int)) {
//     return p1(a, b);
// }

int main() {
    // A()++; B()++;
    // cout << A() << ", " << B() << endl;
    // //C()++
    // cout << C();

// CON TRỎ
    // int x = 10, y = 20;
    // int *p1, *p2;
    // p1 = &x; p2 = &y;
    // cout << "x = " << x;    // x = 10
    // cout << "y = " << y;    // y = 20;
    // cout << "*p1 = " << *p1;    //*p1 = 10
    // cout << "*p2 = " << *p2;    // *p2 = 20;

    // *p1 = 50; *p2 = 90;
    // cout << "x = " << x;    //x = 50
    // cout << "y = " << y;    //y = 90
    // cout << "*p1 = " << *p1;    //*p1 = 50
    // cout << "*p2 = " << *p2;    //*p2 = 90

    // *p1 = *p2;
    // cout << "x = " << x;    //x = 90
    // cout << "y = " << y;    //y = 90
    // cout << "*p1 = " << *p1;    //*p1 = 90
    // cout << "*p1 = " << *p2;    //*p2 = 90

//CON TRỎ HẰNG VÀ HẰNG CON TRỎ
    // int x = 2, y = 4;
    // //con trỏ hằng
    // const int *p1;
    // p1 = &x;
    // p1 = &y;
    // //(*p1)++;
    // cout << *p1 << endl;

    // //hằng con trỏ
    // int* const p2 = &x;
    // //p2 = &y;
    // (*p2)++;
    // cout << *p2;

//CON TRỎ HÀM
    // int (*p)(int, int);
    // p = sum;
    // cout << sum(2,1) << ", " << p(2, 1) << endl;
    // p = sub;
    // cout << sub(2,1) << ", " << p(2, 1) << endl;

    // cout << TT(2, 1, sum) << ", " << TT(2, 1, sub) << endl;

//MẢNG
    // int A[3] = {1, 2, 3};
    // for (int i = 0; i < 3; i++) {
    //     cout << A[i] << " ";
    // }
    // cout << endl;
    // int *p = A;
    // cout << A << ", " << &A[0] << ", " << p << ", " << &p[0] << endl;
    // cout << p + 1 << ", " << &A[1] << ", " << &p[1] << endl;
    // cout << *(p+1) << ", " << A[1] << ", " << p[1] << endl;

    // int A[2][3] = {1, 2, 3, 4, 5, 6};
    // for (int i = 0; i < 2; i++) {
    //     for (int j = 0; j < 3; j++) {
    //         cout << A[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // //A <-> &A[0][0]
    // cout << A << ", " << &A[0][0] << endl;
    // //*(A+i) <-> &A[i][0] -> i = 1
    // cout << *(A + 1) << ", " << &A[1][0] << endl;
    // //*(A+i) + j <-> &A[i][j] -> i = 1, j = 2
    // cout << *(A + 1) + 2 << ", " << &A[1][2] << endl;
    // //*(*(A+i) + j) <-> A[i][j] -> i = 1, j = 2
    // cout << *(*(A + 1) + 2) << ", " << A[1][2] << endl;

    int r, c;
    cout << "r = "; cin >> r;
    cout << "c = "; cin >> c;

    int **p = new int*[r];
    for (int i = 0; i < r; i++) {
        *(p + i) = new int[c];
        for (int j = 0; j < c; j++)
        {
            cin >> *(*(p + i) + j);
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
        {
            cout << *(*(p + i) + j);
        }
        cout << endl;
    }
    //giải phóng
    for (int i = 0; i < r; i++)
    {
        delete[] *(p + i);
    }
    delete[] p;
}