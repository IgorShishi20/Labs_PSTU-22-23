#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    if (N <= 0) {
        cout << "невозможно построить треугольник с неположительным основанием" << endl;
    }
    else {
        char str[N];
        for (int i = 0; i < N; i++) {
            str[i] = ' ';
        }
        int k = N - 1;
        for (int i = 0; i < N ; i++) {
            str[k] = '*';
            k--;
            for (int j = 0; j < N; j++) {
                cout << str[j];
            }
            cout << endl;
        }
    }
    return 0;
}
