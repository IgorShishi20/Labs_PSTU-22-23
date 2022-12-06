#include <iostream>
#include <string>

int main() {
    int big_letter,little_letter;
    int *big_let, *little_let;
    big_let = &big_letter;
    little_let = &little_letter;
    big_letter=0;
    little_letter=0;
    std::string string;
    std::cout<<"Ââåäèòå ñòðîêó"<<std::endl;
    std::cin>>string;
    for(int i=0;i<string.size();i++){
        if(-65<(int)string[i] and (int)string[i]<-32){
            *big_let +=1;
        }
        if(-33<(int)string[i] and (int)string[i]<-1){
            *little_let +=1;
        }
    }
    std::cout<<"Êîëè÷åñòâî çàãëàâíûõ áóêâ ðàâíî "<<*big_let<<std::endl;
    std::cout<<"Êîëè÷åñòâî ñòðî÷íûõ áóêâ ðàâíî "<<*little_let<<std::endl;
    return 0;
}
