#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long int N;
    cout << "Введите число: ";
    cin >> N;
    if(N % 2 == 0){
        cout << "Сумма равна " << N / 2 << endl;
    }
    else{
        cout << "Сумма равна " << - ( N + 1 ) / 2 << endl;
    }
    return 0;
}
