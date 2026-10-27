#include <iostream>
using namespace std;

template<typename T>
class Vector
{
private:
    T *p;
    int n;
public:
    Vector(const int&);
    ~Vector();
    void Show();
};
template<typename T>
Vector<T>::Vector(const int& n) : n(n)
{
    this->p = new T[this->n];
    for (int i = 0; i < this->n; i++)
    {
        cin >> *(this->p + i);
    }
}


template<typename T>
Vector<T>::~Vector()
{
    delete[] this->p;
}
template<typename T>
void Vector<T>::Show() {
    for (int i = 0; i < this->n; i++)
    {
        cout << *(this->p + i) << " ";
    }
}

template class Vector<int>;
template class Vector<double>;