#pragma once
#include <iostream>
#include <string>
using namespace std;

class SV {
     protected:
        string MaSV;
        string hoTen;
    public:
        SV(const string& = "", const string& = "");
        virtual ~SV();
        virtual double GPA() = 0;
        virtual void Input();
        virtual void Output();
};
