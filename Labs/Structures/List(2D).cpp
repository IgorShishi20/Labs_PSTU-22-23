#include <iostream>
using namespace std;

struct ListElem
{
    int data;
    ListElem* next;
    ListElem* prev;
};

ListElem* createList(int n)
{
    ListElem* start;
    ListElem *prev, *curr;
    start = new ListElem;
    cin >> start->data;
    start->next = nullptr;
    start->prev = nullptr;
    prev = start;
    for (int i = 0; i < n-1; i++) {
        curr = new ListElem;
        cin >> curr->data;
        curr->next = nullptr;
        curr->prev = prev;
        prev->next = curr;
        prev = curr;
    }
    return start;
}

void add_elem(ListElem* start,int pos){
    ListElem *first=start, *last;
    for(int i=0;i<pos-1;i++){
        first = first->next;
    }
    last = first->next;
    auto *new_elem = new ListElem;
    cin>>new_elem->data;
    new_elem->prev = first;
    new_elem->next = last;
    last->prev = new_elem;
    first->next = new_elem;
}

void add_elems(ListElem* list,int pos,int k){
    for(int i=0;i<k;i++){
        add_elem(list,pos+i);
    }
}

void delete_elem(ListElem* start,int pos,int k){
    ListElem *first=start;
    ListElem *last;
    for(int i=0;i<pos;i++){
        first = first->next;

    }
    last = first;
    for(int i=0;i<k+1;i++){
        last = last->next;
    }
    first->next = last;
    last->prev = first;
}

int find_elem(ListElem* start,int value){
    ListElem *curr = start;
    int pos = 0;
    while(curr->data!=value && curr->next!= nullptr){
        curr=curr->next;
        pos++;
    }
    if(curr->data==value) return pos+1;
    else return -1;
}

void print_list(ListElem* start,int n){
    ListElem *curr=start;
    for(int i=0;i<n;i++){
        cout<<curr->data<<' ';
        curr=curr->next;
    }
    cout<<endl;
}

void delete_List(ListElem* list) {
    delete list;
}

int main(){
    //create list of n elements (user input)
    ListElem* list = createList(10);
    //print list first n elements (unfortunately no out of bounds checking - pain for user)
    print_list(list,10);
    //add 1 element on position pos
    add_elem(list,5);
    print_list(list,11);
    //add k(3) elements from position pos(2)
    add_elems(list,5,2);
    print_list(list,13);
    //delete k(3) elements from position pos(2)
    delete_elem(list,5,2);
    print_list(list,11);
    //print position of element if found, -1 otherwise
    cout<<find_elem(list,52)<<endl;
    //delete list
    delete_List(list);
    return 0;
}
