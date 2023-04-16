#include "Stack_element.h"

Stack_elem::Stack_elem() {
    next= nullptr;
    data=0;
}

Stack_elem::Stack_elem(Stack_elem* ptr,int n){
    next = ptr;
    data = n;
}
Stack_elem::Stack_elem(const Stack_elem& elem) {
    this->data = elem.data;
    this->next = elem.next;
}
