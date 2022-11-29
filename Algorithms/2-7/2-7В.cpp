#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    if (N < 3) {
        cout << "невозможно построить квадрат со стороной меньше 3" << endl;
    }
    else {
        char str1[N];
        char str2[N];
        for (int i = 0; i < N; i++) {
            str1[i] = '*';
            str2[i] = ' ';
        }
        str2[0]='*';
        str2[N-1]='*';
        //this will be look like anything but square if the gap between strings in console is bigger than character width
        for (int i = 0; i < N ; i++) {
            if (i>0 && i!=(N-1)){
                for (int j = 0; j < N; j++) {
                    cout << str2[j];
                }
                cout << endl;
            }
            else{
                for (int j = 0; j < N; j++) {
                    cout << str1[j];
                }
                cout << endl;
            }
        }
    }
    return 0;
}
