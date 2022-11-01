#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    if (N <= 0) {
        cout << "невозможно построить треугольник с неположительным основанием" << endl;
    }
    else {
        if (N % 2 == 0) {
            cout << "треугольник с четным основанием - такие не строят тут" << endl;
        }
        else{
            char str[N];
            for (int i = 0; i < N; i++) {
                str[i] = ' ';
            }
            int k1 = (N - 1) / 2;
            int k2 = k1;
            for (int i = 0; i < (N + 1) / 2; i++) {
                str[k1] = '*';
                str[k2] = '*';
                k1++;
                k2--;
                //just cout<<str<<endl; sometimes doesn't work well
                for (int j = 0; j < N; j++) {
                    cout << str[j];
                }
                cout << endl;
            }
        }
    }
    return 0;
}
