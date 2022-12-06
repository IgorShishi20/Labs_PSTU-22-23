#include <iostream>

int main() {
    int a;
    int *pointer;
    std::cout<<"Введите число"<<std::endl;
    std::cin>>a;
    pointer = &a;
    *pointer = a+10;
    std::cout<<"Новое число а+10 равно "<<*pointer<<std::endl;
    return 0;
}
