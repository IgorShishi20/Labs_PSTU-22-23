#include <iostream>

using namespace std;

int main() {
    int N, reverse_N;
    cout<< "Введите число ";
    cin>>N;
    reverse_N=0;
    while(N>0){
        int tmp = N % 10;
        reverse_N = reverse_N * 10 + tmp;
        N /= 10;
    }
    cout << " Обратное числу равно "<<reverse_N;
    return 0;
}
