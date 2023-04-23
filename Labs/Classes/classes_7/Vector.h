//
// Created by 1 on 10.04.2023.
//

#ifndef MAIN_CPP_VECTOR_H
#define MAIN_CPP_VECTOR_H
#include "iostream"
#include "string"
using namespace std;

template <class T>
class Vector{
    T* data;
    int size;
public:
    Vector();
    ~Vector();
    Vector(int,T);
    Vector(const Vector<T>&);
    Vector& operator=(const Vector<T>&a);
    T& operator[](int index);
    Vector<T> operator+(const T);
    int operator()();
    friend ostream& operator<< (std::ostream&,const Vector<T>&a);
    friend istream& operator>> (std::istream&,Vector<T>&a);
};

#endif //MAIN_CPP_VECTOR_H
