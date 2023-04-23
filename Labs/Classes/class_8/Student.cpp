#include "Student.h"

Student::Student():Person() {
    rating=0;
}

Student::Student(std::string str, int t, float r): Person(str,t) {
    rating = r;
}

Student::Student(const Student &stud){
    name = stud.name;
    age = stud.age;
    rating = stud.rating;
}

Student &Student::operator=(const Student &stud) {
    if(&stud==this) {return *this;}
    name = stud.name;
    age = stud.age;
    rating = stud.rating;
    return *this;
}

void Student::Show() {
    std::cout<<"This student is called "<<name<<std::endl;
    std::cout<<"And this student is "<<age<<" old."<<std::endl;
    std::cout<<"Moreover, this student has "<<rating<<" rating"<<std::endl;
}

void Student::Input() {
    std::cout<<"This student is called "<<std::endl;
    std::cin>>name;
    std::cout<<"And this student age is "<<std::endl;
    std::cin>>age;
    std::cout<<"And this student has rating of "<<std::endl;
    std::cin>>rating;
}
