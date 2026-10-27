#include "Number.h"
Number::Number(const double& d) : data(d)
{}
Number::~Number()
{}
Number::operator int()
{
    return int(this->data);
}
Number::operator double()
{
    return this->data;
}