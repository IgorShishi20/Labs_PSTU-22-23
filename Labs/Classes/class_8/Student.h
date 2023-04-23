#ifndef MAIN_CPP_STUDENT_H
#define MAIN_CPP_STUDENT_H
#include "Person.h"

class Student :public Person{
protected:
    float rating;
public:
    Student();
    Student(const Student&);
    Student(std::string,int,float);
    ~Student(){};
    //once again
    void Show();
    void Input();
    //setters and getters
    float get_rating(){return rating;};
    void set_rating(float r){rating=r;};
    Student& operator=(const Student&);
};

#endif //MAIN_CPP_STUDENT_H
