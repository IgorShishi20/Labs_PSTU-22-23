#include <iostream>

using namespace std;

int main() {
    int N,a,max,index;
    cout << "Введите количество чисел" << endl;
    cin >> N;
    max=INT_MIN;
    index = 1;
    cout << "Введите последовательность чисел" << endl;
    for(int i = 1; i <= N; i++){
        cin >> a;
        if(a > max){
            max = a;
            index = i;
        }
    }
    cout << "Наибольшее число в последовательности равно " << max << endl;
    cout << "В последовательности это число стоит под номером "<< index << endl;
    return 0;
}
