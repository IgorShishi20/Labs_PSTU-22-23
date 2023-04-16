//
// Created by 1 on 10.04.2023.
//

#ifndef MAIN_CPP_STACK_H
#define MAIN_CPP_STACK_H
#include "iostream"
#include "string"
#include "Stack_element.h"

class Stack{
    Stack_elem* top;
    int size;
public:
    Stack();
    Stack(Stack_elem*,int);
    Stack(const Stack&);
    ~Stack();
    Stack_elem* get_top(){return top;}
    int get_size(){return size;}
    void push(Stack_elem*);
    Stack_elem pop();
    bool isEmpty(){ return size==0;}
};

#endif //MAIN_CPP_STACK_H
