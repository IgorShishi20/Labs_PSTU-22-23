#include "Person.h"

Person::Person() {
    name = "";
    age = 0;
}

Person::Person(std::string str, int t) {
    name = str;
    age = t;
}

Person::Person(const Person &p) {
    name = p.name;
    age = p.age;
}

Person::~Person() {
}

Person &Person::operator=(const Person& p) {
    if(this==&p){ return *this;}
    name = p.name;
    age = p.age;
    return *this;
}

void Person::Show() {
    std::cout<<"This person is called "<<name<<std::endl;
    std::cout<<"And this person is "<<age<<" old."<<std::endl;
}

void Person::Input() {
    std::cout<<"This person is called "<<std::endl;
    std::cin>>name;
    std::cout<<"And this person age is "<<std::endl;
    std::cin>>age;
}

void Person::HandleEvent(const TEvent &event) {
    if(event.what==EvMessage){
        switch (event.command) {
            case cmGet: std::cout<<"Name is "<<get_name()<<std::endl; break;
        }
    }
}
