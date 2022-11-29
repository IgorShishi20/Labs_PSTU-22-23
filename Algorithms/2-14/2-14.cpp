#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long int N;
    short sum = 0;
    cout << "Введите число" << endl;
    cin >> N;
    while(N>0){
        sum += N % 10;
        N = N / 10;
    }
    cout << "Сумма цифр числа равна " << sum << endl;
    return 0;
}
