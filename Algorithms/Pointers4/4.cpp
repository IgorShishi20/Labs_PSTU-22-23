#include <iostream>
#include <iomanip>

int main() {
    double current,max,min;
    double *point_current, *point_max, *point_min;
    point_current = &current;
    point_max = &max;
    point_min = &min;
    std::cin>>*point_current;
    *point_min = *point_current;
    *point_max = *point_current;
    if(*point_current == 0){
        *point_min = 0;
        *point_max = 0;
    }
    while(*point_current!=0){
        if(*point_current>*point_max){
            *point_max= *point_current;
        }
        if(*point_current<*point_min){
            *point_min = *point_current;
        }
        std::cin>>*point_current;
    }
    std::cout<<"Минимум равен "<<std::setprecision(13)<<*point_min<<std::endl;
    std::cout<<"Максимум равен "<<std::setprecision(13)<<*point_max<<std::endl;
    return 0;
}
