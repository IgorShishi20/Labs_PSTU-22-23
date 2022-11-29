#include <iostream>
#include "cmath"

using namespace std;
int main() {
    int N,index;
    float max;
    index = 0;
    cout<< "Введите длину последовательности ";
    cin>>N;
    max = -1;
    for(int i=1;i<=N;i++){
        if(sin((float)N+float(i)/float(N))>max){
            max = sin(float(N)+float(i)/float(N));
            index = i;
        }
    }
    cout<< "Наибольший элемент последовательности равен "<< max << " и находится под номером "<< index;
    return 0;
}
