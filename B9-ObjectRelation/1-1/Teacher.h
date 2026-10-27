#include <iostream>
#include <string>
using namespace std;

class Teacher
{
private:
    string name;
    int age;
public:
    Teacher(string = " ", int = 0);
    ~Teacher();
    friend ostream& operator<<(ostream&, const Teacher&);
};

Teacher::Teacher(string name, int age) : name(name), age(age)
{}

Teacher::~Teacher()
{
}

ostream& operator<<(ostream& o, const Teacher& t) {
    o << t.name << ", " << t.age << endl;
    return o;
}