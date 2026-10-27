#include "Teacher.h"
class Department
{
private:
    Teacher *teacher;
    string nameDep;
public:
    Department(string = " ", Teacher* = nullptr);
    ~Department();
    friend ostream& operator<<(ostream&, const Department&);
};

Department::Department(string name, Teacher* teacher) : nameDep(name), teacher(teacher)
{
}

Department::~Department()
{
    delete this->teacher;
}
ostream& operator<<(ostream& o, const Department& d) {
    o << d.nameDep << ": " << *d.teacher << endl;
    return o;
}
