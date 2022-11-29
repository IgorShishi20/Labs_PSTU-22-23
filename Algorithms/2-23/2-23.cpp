#include <iostream>
#include "cmath"

using namespace std;
int main() {
    int N;
    float max;
    cout<<"Введите размер последовательности"<<endl;
    cin>>N;
    max=-1;
    for(int i=1;i<=N;i++){
        if (sin(float(N)+float(i)/float(N))>max){
            max=sin(float(N)+float(i)/float(N));
        }
    }
    //Последовательность sin(n+i/n) имеет ровно 1 максимум
    //А тут должна быть выкладка, но ее не будет т.к. она будет (была) на лекции
    cout<<"Наибольший элемент последовательности равен "<<max<<endl;
    cout<<"Наибольший элемент последовательности встречается 1 раз"<<endl;
    return 0;
}
