#include <iostream>

int main() {
    int a;
    int *pointer;
    std::cout<<"������� �����"<<std::endl;
    std::cin>>a;
    pointer = &a;
    *pointer = a+10;
    std::cout<<"����� ����� �+10 ����� "<<*pointer<<std::endl;
    return 0;
}
