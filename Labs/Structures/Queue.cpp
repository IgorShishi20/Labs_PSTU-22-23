#include <iostream>
using namespace std;

//stack element has data and pointer to the next element (under current)
struct QueueElem
{
    int data;
    QueueElem* next;
    QueueElem* prev;
};

struct Queue{
    //first element of stack
    QueueElem* front;
    QueueElem* back;
    //size of stack
    int size;

    void init(){
        front = nullptr;
        back = front;
        size = 0;
    }

    //push element - use data and show for new element next is stack.top and stack now starts from curr
    void push(int data){
        auto *curr = new QueueElem;
        curr->data = data;
        curr->next = nullptr;
        curr->prev = back;
        if(back!= nullptr){
            back->next = curr;
        }
        if(front == nullptr){
            front = curr;
        }
        back = curr;
        size++;
    }

    //isEmpty returns true if stack has 0 elements, false otherwise
    bool isEmpty(){
        return front == nullptr;
    }

    //pop element - remove element from stack, so it give us value from top and top now is next element
    int pop(){
        int value = front->data;
        QueueElem* tmp = front;
        if(size==1){
            back = nullptr;
        }
        front = front->next;
        size--;
        delete tmp;
        return value;
    }

};

//create stack of size n and
Queue create_queue(int n)
{
    Queue queue{};
    queue.init();
    int data;
    for (int i = 0; i < n; i++)
    {
        cin>>data;
        queue.push(data);
    }
    return queue;
}

void add_elem(Queue &queue,int pos){
    Queue new_queue{};
    new_queue.init();
    int data;
    int size = queue.size;
    cin>>data;
    if(pos==1){
        queue.push(data);
    }
    else{
        for(int i=0;i<pos-1;i++){
            new_queue.push(queue.pop());
        }
        new_queue.push(data);
        for(int i=0;i<size-pos+1;i++){
            new_queue.push(queue.pop());
        }
        queue = new_queue;
    }
}

void add_elems(Queue &queue,int pos,int k){
    for(int i=0;i<k;i++){
        add_elem(queue,pos+i);
    }
}

void delete_elems(Queue &queue,int pos,int k){
    Queue new_queue{};
    new_queue.init();
    int size = queue.size;
    if(pos==1){
        queue.pop();
    }
    else{
        for(int i=0;i<pos-1;i++){
            new_queue.push(queue.pop());
        }
        for(int i=0;i<k;i++){
            queue.pop();
        }
        for(int i=0;i<size-pos-k+1;i++){
            new_queue.push(queue.pop());
        }
        queue = new_queue;
    }
}

int find_elem(Queue &queue,int value){
    Queue new_queue{};
    new_queue.init();
    int pos = 0;
    while(queue.front->data!=value && queue.front!= nullptr){
        new_queue.push(queue.pop());
        pos++;
    }
    if(queue.front->data==value){
        for(int i=0;i<pos;i++){
            queue.push(new_queue.pop());
        }
        return pos+1;
    }
    else{
        for(int i=0;i<pos;i++){
            queue.push(new_queue.pop());
        }
        return -1;
    }
}

void print_queue(Queue &queue){
    Queue new_queue{};
    new_queue.init();
    int value = 0;
    int size = queue.size;
    for(int i=0;i<size;i++){
        value = queue.pop();
        cout<<value<<' ';
        new_queue.push(value);
    }
    cout<<endl;
    for(int i=0;i<size;i++){
        queue.push(new_queue.pop());
    }
}

void delete_queue(Queue &queue) {
    while(queue.size>0){
        queue.pop();
    }
}

int main(){
    //create stack of n elements (user input)
    Queue test_stack = create_queue(10);
    //print stack elements from top to bottom (unfortunately no out of bounds checking - pain for user)
    print_queue(test_stack);
    //add 1 element on position pos
    add_elem(test_stack,5);
    print_queue(test_stack);
    //add k(3) elements from position pos(2)
    add_elems(test_stack,5,2);
    print_queue(test_stack);
    //delete k(3) elements from position pos(2)
    delete_elems(test_stack,5,2);
    print_queue(test_stack);
    //print position of element if found, -1 otherwise
    cout<<find_elem(test_stack,52)<<endl;
    //delete stack
    delete_queue(test_stack);
}
