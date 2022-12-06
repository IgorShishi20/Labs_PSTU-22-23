#include <iostream>

int main() {
    long long int current,fact,N;
    long long int *point_current, *point_fact;
    point_current = &current;
    point_fact = &fact;
    *point_fact = 1;
    *point_current = 1;
    std::cout<<"Введите N "<<std::endl;
    std::cin>>N;
    for(int i=1;i<N;i++){
        *point_current += 1;
        (*point_fact) *= (*point_current);
    }
    std::cout<<"Факториал N равен "<<*point_fact<<std::endl;
    return 0;
}
