#include <iostream>
using namespace std;

int minimum (int k,...)
{
    int *p = &k; // указатель на параметр k
    int min=INT32_MAX;
    for (;k!=0;k--){
        p+=2;
        if(min>*p) min=*p;
    }
    return min;
}

int main( )
{
    cout<<"Минимум(5,4,6,45,-234,3)="<<minimum(5,4,6,45,-234,3)<<endl;
    cout<<"Минимум(10,1,2,3,4,0,-5,23,64,83,-89)="<<minimum(10,1,2,3,4,0,-5,23,64,83,-89);
    cout<<"Минимум(15,1,2,3,4,0,-5,321,10008,-485,9,42,999,-245354,67,812)="<<minimum(15,1,2,3,4,0,-5,321,10008,-485,9,42,999,-245354,67,812);
    return 0;
}
