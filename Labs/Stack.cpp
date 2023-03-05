#include <iostream>
using namespace std;

//stack element has data and pointer to the next element (under current)
struct StackElem
{
    int data;
    StackElem* next;
};

struct Stack{
    //first element of stack
    StackElem* top;
    //size of stack
    int size;

    void init(){
        top = nullptr;
        size = 0;
    }

    //push element - use data and show for new element next is stack.top and stack now starts from curr
    void push(int data){
        auto *curr = new StackElem;
        curr->data = data;
        curr->next = top;
        top = curr;
        size++;
    }

    //isEmpty returns true if stack has 0 elements, false otherwise
    bool isEmpty(){
        return top == nullptr;
    }

    //pop element - remove element from stack, so it give us value from top and top now is next element
    int pop(){
        int value = top->data;
        StackElem* tmp = top;
        top = top->next;
        size--;
        delete tmp;
        return value;
    }

};

//create stack of size n and
Stack create_stack(int n)
{
    Stack stack{};
    stack.init();
    int data;
    for (int i = 0; i < n; i++)
    {
        cin>>data;
        stack.push(data);
    }
    return stack;
}

void add_elem(Stack &stack,int pos){
    Stack new_stack{};
    new_stack.init();
    int data;
    cin>>data;
    if(pos==1){
        stack.push(data);
    }
    else{
        for(int i=1;i<pos;i++){
            new_stack.push(stack.pop());
        }
        stack.push(data);
        for(int i=1;i<pos;i++){
            stack.push(new_stack.pop());
        }
    }
}

void add_elems(Stack &stack,int pos,int k){
    for(int i=0;i<k;i++){
        add_elem(stack,pos+i);
    }
}

void delete_elems(Stack &stack,int pos,int k){
    Stack new_stack{};
    new_stack.init();
    if(pos==1){
        int tmp = stack.pop();
    }
    else{
        for(int i=1;i<pos;i++){
            new_stack.push(stack.pop());
        }
        int tmp = 0;
        for(int i=0;i<k;i++){
            tmp = stack.pop();
        }
        for(int i=1;i<pos;i++){
            stack.push(new_stack.pop());
        }
    }
}

int find_elem(Stack &stack,int value){
    Stack new_stack{};
    new_stack.init();
    int pos = 0;
    while(stack.top->data!=value && stack.top!= nullptr){
        new_stack.push(stack.pop());
        pos++;
    }
    if(stack.top->data==value){
        for(int i=0;i<pos;i++){
            stack.push(new_stack.pop());
        }
        return pos+1;
    }
    else{
        for(int i=0;i<pos;i++){
            stack.push(new_stack.pop());
        }
        return -1;
    }
}

void print_stack(Stack &stack){
    Stack new_stack{};
    new_stack.init();
    int value = 0;
    int size = stack.size;
    for(int i=0;i<size;i++){
        value = stack.pop();
        cout<<value<<' ';
        new_stack.push(value);
    }
    cout<<endl;
    for(int i=0;i<size;i++){
        stack.push(new_stack.pop());
    }
}

void delete_stack(Stack &stack) {
    while(stack.size>0){
        stack.pop();
    }
}

int main(){
    //create stack of n elements (user input)
    Stack test_stack = create_stack(10);
    //print stack elements from top to bottom (unfortunately no out of bounds checking - pain for user)
    print_stack(test_stack);
    //add 1 element on position pos
    add_elem(test_stack,5);
    print_stack(test_stack);
    //add k(3) elements from position pos(2)
    add_elems(test_stack,5,2);
    print_stack(test_stack);
    //delete k(3) elements from position pos(2)
    delete_elems(test_stack,5,2);
    print_stack(test_stack);
    //print position of element if found, -1 otherwise
    cout<<find_elem(test_stack,52)<<endl;
    //delete stack
    delete_stack(test_stack);
}
