#include "Teacher.h"
#include <vector>

class Department
{
private:
    vector<Teacher *> teacher;
    string nameDept;
public:
    Department(string = " ");
    ~Department();
    void addTeacher(Teacher*);
    friend ostream& operator<<(ostream&, const Department&);
};

Department::Department(string name) : nameDept(name)
{
}

Department::~Department()
{
    this->teacher.clear();
}
void Department::addTeacher(Teacher *t)
{
    this->teacher.push_back(t);
}
ostream& operator<<(ostream& o, const Department& d) {
    o << d.nameDept << ": " << endl;
    for (unsigned int i = 0; i < d.teacher.size(); i++) {
        o << *d.teacher[i];
    }
    o << endl;
    return o;
}
