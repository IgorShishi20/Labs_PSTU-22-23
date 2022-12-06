#include <iostream>
#include <iomanip>

int main() {
    std::cout<<"Введите числа a и b"<<std::endl;
    double a,b,result;
    std::cin>>a>>b;
    double *point_one, *point_two, *point_three;
    point_one = &a;
    point_two = &b;
    point_three = &result;
    result = 0.0;
    *point_three = *point_one + *point_two;
    std::cout<<"Сумма равна "<<std::setprecision(13)<<result<<std::endl;
    return 0;
}
