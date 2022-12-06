#include <iostream>

int main() {
    std::cout<<"Введите числа a и b"<<std::endl;
    int a,b,result;
    std::cin>>a>>b;
    int *point_one, *point_two, *point_three;
    point_one = &a;
    point_two = &b;
    point_three = &result;
    result = 0;
    *point_three = *point_one + *point_two;
    std::cout<<"Сумма равна "<<result<<std::endl;
    return 0;
}
