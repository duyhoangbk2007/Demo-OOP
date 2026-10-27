#include <iostream>
#include "IntSet.h"
using namespace std;
IntSet::IntSet(const int& n) : n(n)
{
    this->p = new double[this->n];
    for (int i = 0; i < this->n; i++)
    {
        cout << "IntSet p[" << i << "] = ";
        cin >> *(this->p + i); 
    }
}
IntSet::~IntSet()
{
    delete[] this->p;
}
void IntSet::Show()
{
    for (int i = 0; i < this->n; i++)
    {
        cout << *(this->p + i) << " ";
    }
    cout << endl; 
}
