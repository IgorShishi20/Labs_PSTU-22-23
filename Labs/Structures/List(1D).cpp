#include <iostream>
using namespace std;

struct ListElem
{
    int data;
    ListElem* next;
};

ListElem* createList(int n)
{
    ListElem* start;
    ListElem *prev,*curr;
    start = new ListElem;
    cin >> start->data;
    start->next = nullptr;
    prev = start;
    for (int i = 0; i < n-1; i++)
    {
        curr = new ListElem;
        cin >> curr->data;
        curr->next = nullptr;
        prev->next = curr;
        prev = curr;
    }
    return start;
}

void add_elem(ListElem* &start,int pos){
    ListElem *first=start;
    for(int i=1;i<pos-1;i++){
        first = first->next;
    }
    auto *new_elem = new ListElem;
    cin>>new_elem->data;
    if(pos==1){
        new_elem->next = first;
        start = new_elem;
    }
    else{
        new_elem->next = first->next;
        first->next = new_elem;
    }
}

void add_elems(ListElem* &list,int pos,int k){
    for(int i=0;i<k;i++){
        add_elem(list,pos+i);
    }
}

void delete_elems(ListElem* &start,int pos,int k){
    ListElem *first=start;
    ListElem *last;
    for(int i=0;i<pos-1;i++){
        first = first->next;
    }
    last = first;
    for(int i=0;i<k;i++){
        last = last->next;
    }
    if (pos==1){
        start = last;
    }
    else{
        first->next = last->next;
    }
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
    delete_elems(list,5,2);
    print_list(list,11);
    //print position of element if found, -1 otherwise
    cout<<find_elem(list,52)<<endl;
    //delete list
    delete_List(list);
    return 0;
}
