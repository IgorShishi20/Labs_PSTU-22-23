#include <iostream>

using namespace std;

int main() {
    int N,a;
    bool zero_prev,pos_first;
    pos_first=true;
    zero_prev=true;
    cout << "Введите количество чисел" << endl;
    cin >> N;
    cout << "Введите последовательность чисел" << endl;
    for(int i = 1; i <= N; i++){
        cin >> a;
        if(a!=0 and zero_prev){
            if(a<0){
                pos_first=false;
            }
            zero_prev=false;
        }
    }
    if(zero_prev){
        cout<<"Вся последовательность нулевая"<<endl;
    }
    else{
        if(pos_first){
            cout<<"Первыми в последовательности встречаются положительные числа"<<endl;
        }
        else{
            cout<<"Первыми в последовательности встречаются отрицательные числа"<<endl;
        }
    }
    return 0;
}

