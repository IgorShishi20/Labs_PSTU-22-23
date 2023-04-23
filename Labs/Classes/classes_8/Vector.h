#ifndef MAIN_CPP_VECTOR_H
#define MAIN_CPP_VECTOR_H

#include "Object.h"

class Vector{
protected:
    Object**data;
    int size;
    int curr;
public:
    Vector(int);
    ~Vector();
    void Add(Object*);
    void Del();
    void Show();
    int operator ()();
    void HandleEvent(const TEvent &event);
};

#endif //MAIN_CPP_VECTOR_H
