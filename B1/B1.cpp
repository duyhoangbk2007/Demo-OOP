#include<iostream>
using namespace std;
//P2:
// int z = 2;
// void A()
// {
//     int x = 3; //cục bộ động (được giải phóng)
//     static int y = 5; //cục bộ tĩnh //không được giải phóng
//     x++; y++;
//     cout << x << ", " << y << endl;
// }

//P4
// void HV(int a, int b)
// {
//     cout << "Truoc HV: " << a << ", " << b << endl;
//     int t = a; a = b; b = t;
//     cout << "Sau HV: " << a << ", " << b << endl;
// }

// void HV1(int &a, &b)
// {
//     int t = a; a = b; b = t;
// }

// void HV2(int *a, int *b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

//p7
// void A(int x, int y = 2, int z = 4) {
//     cout << x << ", " << y << ", " << z << endl;
// }
int main() {
    //P1:
    // int x = 1;
    // x = 2;
    // cout << x << ", " << &x << endl;
    // int &y = x;
    // y = 4;
    // cout << x << ", " << y << endl;
    // cout << &x << ", " << &y << endl;
    // int *p = &x;
    // //*p <-> x <-> y
    // cout << *p << ", " << x << ", " << y << endl;
    // //p <-> &x
    // cout << p << ", " << &x << endl;
    // //&p
    // cout << &p << endl;

    //P2:
    // A();
    // A();
    // int z = 4;
    // cout << z << ", " << ::z << endl;

    //P3:
    // int x = 1;
    // cout << "x = ";
    // cout << x;
    // cout << endl;

    // cout << "x = " << x << endl;
    // int x = 1; char y;
    // cout << "Input x = ";
    // cin >> x;
    // y = x; //ASCII
    // cout << x << ", " << y << endl;
    // cout << "Input y = ";
    // cin >> y;
    // x = y;
    // cout << x << ", " << y << endl;

    //P4
    // int x, y;
    // cin >> x >> y;
    // HV(&x,&y);
    // cout << x << ", " << y << endl;

    //P5
    // enum Color
    // {
    //     R, //0
    //     B, //1
    //     G = 5,
    //     Y //6
    // };
    // Color c = B;
    // Color d = Y;
    // cout << c << ", " << d << endl;

    //P6
    // int a = 2;
    // const int b = 2;
    // const int &x = b;
    // cout << x << ", " << b << endl;
    // const int &y = a;
    // a++;    //y++
    // cout << y << ", " << a << endl;
    // const int &z = 5;
    // cout << z << ", " << &z << endl;

    //P7
    // A(1);   //1, 2, 4
    // A(1,4);     //1, 4, 5
    // A(1, 4, 6); //1, 4, 6
    //A(1, ,6);
}