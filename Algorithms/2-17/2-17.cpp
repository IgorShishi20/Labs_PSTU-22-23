#include <iostream>

using namespace std;

int main() {
    int N;
    double x;
    long double sum,current;
    cout<< "Введите степень многочлена :";
    cin >> N;
    cout << "Введите точку, в которой хотите найти значение многочлена ";
    cin >> x;
    current = 1;
    sum = 0;
    for( int i=1;i<=N;i++){
        sum += current;
        current *= x/i;
    }
    sum += current;
    cout << sum;
    return 0;
}
