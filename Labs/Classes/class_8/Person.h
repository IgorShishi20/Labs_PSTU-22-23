#ifndef MAIN_CPP_PERSON_H
#define MAIN_CPP_PERSON_H
#include <utility>

#include "iostream"
#include "Object.h"

class Person:public Object{
protected:
    std::string name;
    int age;
public:
    Person();
    Person(std::string,int);
    Person(const Person&);
    ~Person();
    void Show();
    //do we really need input?
    void Input();
    //setters and getters
    void set_name(std::string str){name = str;};
    void set_age(int a){age = a;};
    int get_age() const{return age;};
    std::string get_name(){return name;};
    Person& operator=(const Person&);
    void HandleEvent(const TEvent &event);
};

#endif //MAIN_CPP_PERSON_H
