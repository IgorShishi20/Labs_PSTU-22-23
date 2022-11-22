#include <iostream>

using namespace std;

int main() {
    int N;
    cout<< "Введите число ";
    cin>>N;
    if (N % 3 == 0){
        cout << "Сумма равна " << 3 * (N / 3) * (N / 3 - 1 ) / 2 << endl;
    }
    else{
        if (N % 3 == 1){
            cout << "Сумма равна " << 3 * (N / 3) * (N / 3 -1) / 2 + N;
        }
        else {
            cout << "Сумма равна " << 3 * (N / 3) * (N / 3 -1) / 2 + 2 * N - 1;
        }
    }
    return 0;
}
