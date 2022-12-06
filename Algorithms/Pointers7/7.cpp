#include <iostream>

int main() {
    int a;
    int *pointer;
    std::cout<<"Ââåäèòå ÷èñëî"<<std::endl;
    std::cin>>a;
    pointer = &a;
    *pointer = a+10;
    std::cout<<"Íîâîå ÷èñëî à+10 ðàâíî "<<*pointer<<std::endl;
    return 0;
}
