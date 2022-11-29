#include <iostream>

using namespace std;

int main() {
    int N,a,max,min;
    cout << "Введите количество чисел" << endl;
    cin >> N;
    max = INT_MIN;
    min = INT_MAX;
    cout << "Введите последовательность чисел" << endl;
    for(int i = 1; i <= N; i++){
        cin >> a;
        if(a > max){
            max = a;
        }
        if(a < min){
            min = a;
        }
    }
    cout << "Сумма наибольшего и наименьшего чисел последовательности равна " << max + min << endl;
    return 0;
}
