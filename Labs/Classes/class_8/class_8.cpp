#include "Student.h"
#include "Vector.h"
#include "Dialog.h"

int main(){
    auto *pers1 = new Person();
    pers1->Input();
    pers1->Show();
    auto *stud1 = new Student();
    stud1->Input();
    stud1->Show();

    auto *pers2 = new Person();
    pers2->Input();
    auto *stud2 = new Student();
    stud2->Input();
    Vector v(10);
    Object* p = pers2;
    v.Add(p);
    p=stud2;
    v.Add(p);
    v.Show();
    v.Del();
    std::cout<<"The size of vector is "<<v()<<std::endl;

    Dialog d;
    d.EndExec();
    return 0;
}