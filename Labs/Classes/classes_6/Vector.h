//
// Created by 1 on 10.04.2023.
//

#ifndef MAIN_CPP_VECTOR_H
#define MAIN_CPP_VECTOR_H
#include "iostream"
#include "string"

class Iterator{
    friend class Vector;
    int* elem;
public:
    Iterator(){ elem=0;}
    Iterator(const Iterator& it){elem = it.elem;}
    bool operator==(const Iterator& it){return elem==it.elem;}
    bool operator!=(const Iterator& it){return elem!=it.elem;}
    void operator ++(){++elem;}
    void operator --(){--elem;}
    int& operator *() const {return *elem;}
};

class Vector{
    int* data;
    int size;
    Iterator beg;
    Iterator end;
public:
    Vector();
    ~Vector();
    Vector(int);
    Vector(const Vector&);
    Iterator first(){ return beg;}
    Iterator last(){ return end;}
    Vector& operator=(const Vector&a);
    int& operator[](int index);
    Vector operator+(const int);
    int operator()();
    friend std::ostream& operator<<(std::ostream&,const Vector&);
    friend std::istream& operator>>(std::istream&,Vector&);
};
#endif //MAIN_CPP_VECTOR_H
