#include <iostream>
#include "cmath"

using namespace std;
int main() {
    int N,index;
    float s;
    bool found=false;
    index = 0;
    cout<< "Введите длину последовательности ";
    cin>>N;
    cout<<"Введите число, которое хотите найти";
    cin>>s;
    for(int i=1;i<=N;i++){
        if(sin(N+float(i)/float(N))==s){
            found = true;
            index = i;
        }
    }
    if(found){
        cout<<"Искомое число находится в последовательности под номером "<<index<<endl;
    }
    else{
        cout<<"Искомое число в последовательности не найдено"<<endl;
    }
    return 0;
}
