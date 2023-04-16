#include "Vector.h"
Vector::Vector(int s){
    size = s;
    data = new int [size];
    for(int i=0;i<size;i++){
        data[i]=0;
    }
    beg.elem=&data[0];
    end.elem=&data[size];
}

Vector::~Vector() {
    delete [] data;
    data = nullptr;
}

Vector::Vector(const Vector &a) {
    size = a.size;
    data = new int[size];
    for(int i=0;i<size;i++){
        data[i]=a.data[i];
    }
    beg=a.beg;
    end=a.end;
}

Vector &Vector::operator=(const Vector &a) {
    size=a.size;
    if(data != nullptr) delete[] data;
    data = new int[size];
    for(int i=0;i<size;i++){
        data[i] = a.data[i];
    }
    beg=a.beg;
    end=a.end;
    return *this;
}

int &Vector::operator[](int index) {
    if(index<size) return data[index];
    else std::cout<<"Error. Out of bounds!"<<std::endl;
}

int Vector::operator()() {return size;}

Vector Vector::operator+(const int k) {
    Vector tmp(size);
    for(int i=0;i<size;i++){
        tmp.data[i]+=data[i]+k;
    }
    return tmp;
}

std::ostream& operator<<(std::ostream& out,const Vector& a){
    for(int i=0;i<a.size;i++){
        out<<a.data[i]<<" ";
    }
    return out;
}

std::istream& operator>>(std::istream& in,Vector& a){
    for(int i=0;i<a.size;i++){
        in>>a.data[i];
    }
    return in;
}


///— »Ќ№ QT твою сибирскую