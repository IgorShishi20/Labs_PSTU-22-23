#include <iostream>
#include <string>

int main() {
    int cons_letter,vowel_letter;
    int *c_let, *v_let;
    v_let = &vowel_letter;
    c_let = &cons_letter;
    vowel_letter=0;
    cons_letter=0;
    std::string string;
    std::cout<<"Введите строку"<<std::endl;
    std::cin>>string;
    for(int i=0;i<string.size();i++){
        if((int)string[i]==-64 or (int)string[i]==-59 or (int)string[i]==-88 or (int)string[i]==-56 or (int)string[i]==-50 or (int)string[i]==-45 or (int)string[i]==-37 or (int)string[i]==-35 or (int)string[i]==-34 or (int)string[i]==-33){
            *v_let +=1;
        }
        else{
            if((int)string[i]==-32 or (int)string[i]==-27 or (int)string[i]==-72 or (int)string[i]==-24 or (int)string[i]==-18 or (int)string[i]==-13 or (int)string[i]==-5 or (int)string[i]==-3 or (int)string[i]==-2 or (int)string[i]==-1){
                *v_let +=1;
            }
            else{
                *c_let +=1;
            }
        }
    }
    std::cout<<"Количество согласных букв равно "<<*c_let<<std::endl;
    std::cout<<"Количество гласных букв равно "<<*v_let<<std::endl;
    return 0;
}

