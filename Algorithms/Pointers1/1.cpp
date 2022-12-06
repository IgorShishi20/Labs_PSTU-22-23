#include <iostream>

int main() {
    std::cout<<"Введите числа a и b"<<std::endl;
    int a,b,temp;
    std::cin>>a>>b;
    int *point_one, *point_two, *point_three;
    point_one = &a;
    point_two = &temp;
    point_three = &b;
    std::cout<<"До замены a равно "<<a<<", b равно "<<b<<std::endl;
    *point_two = *point_one;
    *point_one = *point_three;
    *point_three = *point_two;
    std::cout<<"После замены a равно "<<a<<", b равно "<<b<<std::endl;
    return 0;
}
