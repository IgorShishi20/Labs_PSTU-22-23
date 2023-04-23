#include "Vector.h"
#include "Student.h"

Vector::Vector(int s){
    size = s;
    data = new Object * [s];
}

Vector::~Vector() {
    if (data!= nullptr) delete [] data;
    data = nullptr;
}

void Vector::Add(Object* p) {
    std::cout<<"If you want to put Person press 1"<<std::endl;
    std::cout<<"If you want to put Student press 2"<<std::endl;
    int y;
    std::cin>>y;
    if(y==1){
        Person* pers = new (Person);
        pers->Input();
        p=pers;
        if(curr<size){
            data[curr]=p;
            curr++;
        }
    }
    else{
        Student* stud = new (Student);
        stud->Input();
        p=stud;
        if(curr<size){
            data[curr]=p;
            curr++;
        }
    }
}

void Vector::Show() {
    if(curr==0){std::cout<<"The vector is empty"<<std::endl;}
    Object**p=data;
    for(int i=0;i<curr;i++) {
        (*p)->Show();
        p++;
    }
}

void Vector::Del() {
    if(curr) curr--;
}

void Vector::HandleEvent(const TEvent &event) {
    if(event.what==EvMessage){
        Object**p =data;
        for(int i=0;i<curr;i++){
            (*p)->Show();
            p++;
        }
    }
}
