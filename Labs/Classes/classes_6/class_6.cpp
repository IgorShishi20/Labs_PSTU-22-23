#include "Vector.h"
#include "iostream"

int main(){
    Vector v1(5);
    std::cout<<v1<<std::endl;
    std::cin>>v1;
    std::cout<<v1<<std::endl;
    v1[2]=100;
    std::cout<<v1<<std::endl;
    Vector v2(10);
    std::cout<<v2<<std::endl;
    v2=v1;
    std::cout<<v2<<std::endl;
    Vector v3(10);
    v3=v2+100;
    std::cout<<v3<<std::endl;
    std::cout<<"The length of first vector "<<v1()<<std::endl;
    std::cout<<*(v1.first())<<std::endl;
    Iterator i = v1.first();
    ++i;
    std::cout<<*i<<std::endl;
    for(i=v1.first();i!=v1.last();++i) std::cout<<*i<<std::endl;
};
