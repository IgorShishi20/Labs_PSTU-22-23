#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;
    int M = N+ (int)round(N*sqrt(2)*0.5);
    if (N < 1) {
        cout << "невозможно построить квадрат со стороной меньше 1" << endl;
    }
    else {
        char str1[M];
        char str2[M];
        for (int i = 0; i < M; i++) {
            if(i<M-N){
                str1[i]=' ';
                str2[i]=' ';
            }
            else{
                str1[i]='*';
                str2[i]=' ';
            }
        }
        str2[M-N-1]='*';
        str2[M-1]='*';
        str2[M-2]='*';
        cout<<M<<endl;
        //this will be look like anything but square if the gap between strings in console is bigger than character width
        //also the implementation is so disgusting that its a shame to use it, but the task was solved
        //total amount of crooked-nails (kostyly) is over9000)
        for (int j = 0; j < M; j++) {
            cout << str1[j];
        }
        cout << endl;
        int k=M-2;
        for (int i = 1; i < M-N ; i++) {
            for (int j = 0; j < M; j++) {
                cout << str2[j];
            }
            cout << endl;
            str2[k]=' ';
            str2[k-1]='*';
            str1[k]=' ';
            str1[k-N+1]='*';
            str2[k-N+1]=' ';
            str2[k-N]='*';
            k--;
        }
        str1[0]='*';
        for (int j = 0; j < M; j++) {
            cout << str1[j];
        }
        cout << endl;
        for(int i = M-N;i<N;i++){
            for (int j = 0; j < M; j++) {
                cout << str2[j];
            }
            cout << endl;
        }
        k=M-1;
        for (int i = N; i < M-1 ; i++) {
            for (int j = 0; j < M; j++) {
                cout << str2[j];
            }
            cout << endl;
            str2[k]=' ';
            str2[k-1]='*';
            k--;
        }
        str1[M-1]=' ';
        for (int j = 0; j < N; j++) {
            cout << str1[j];
        }
        cout << endl;
    }
    return 0;
}
