#include "Stack.h"

Stack::Stack() {
    top= nullptr;
    size=0;
}
Stack::Stack(Stack_elem *data, int n) {
    top=data;
    size = n;
}

Stack::Stack(const Stack &st) {
    top = st.top;
    size = st.size;
}

Stack::~Stack(){
    delete top;
    size = 0;
}

void Stack::push(Stack_elem* elem) {
    elem->set_next(top);
    top = elem;
}

Stack_elem Stack::pop(){
    Stack_elem st_el(top->get_next(),top->get_data());
    top = top->get_next();
    size--;
    return st_el;
}
