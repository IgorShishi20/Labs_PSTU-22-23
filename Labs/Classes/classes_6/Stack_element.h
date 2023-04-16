//
// Created by 1 on 10.04.2023.
//

#ifndef MAIN_CPP_STACK_ELEMENT_H
#define MAIN_CPP_STACK_ELEMENT_H

class Stack_elem{
    int data;
    Stack_elem* next;
public:
    Stack_elem();
    Stack_elem(Stack_elem*,int);
    Stack_elem(const Stack_elem&);
    int get_data(){return data;}
    Stack_elem* get_next(){return next;}
    void set_data(int new_data){data = new_data;}
    void set_next(Stack_elem* new_next){ next=new_next;}
};

#endif //MAIN_CPP_STACK_ELEMENT_H
