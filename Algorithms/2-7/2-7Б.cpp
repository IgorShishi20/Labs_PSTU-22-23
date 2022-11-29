#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    if (N <= 0) {
        cout << "невозможно построить квадрат с неположительной длиной стороны" << endl;
    }
    //If we have square of size 1 - we assume that it is just 1 dot 
    else {
        char str1[N];
        for (int i = 0; i < N; i++) {
            str1[i] = '*';
        }
        //this will be look like anything but square if the gap between strings in console is bigger than character width
        for (int i = 0; i < N ; i++) {
                for (int j = 0; j < N; j++) {
                    cout << str1[j];
                }
                cout << endl;
        }
    }
    return 0;
}
