#include "Department.h"
int main() {
    Teacher *t1 = new Teacher("NVA", 40);
    Teacher *t2 = new Teacher("NVB", 30);
    Teacher *t3 = new Teacher("NVC", 20);
    {
        Department d("CNTT");
        d.addTeacher(t1);
        d.addTeacher(t2);
        d.addTeacher(t3);
        cout << d;
    }
    cout << *t1 << *t2 << *t3;
    delete t1;
    delete t2;
    delete t3;
    return 0;
