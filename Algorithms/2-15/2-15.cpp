#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long int N;
    short digit ;
    bool found=false;
    cout << "Введите число: ";
    cin >> N;
    cout << "Введите цифру, которую планируете встретить в числе: ";
    cin >> digit;
    while(digit<0 or digit>9){
        cout<< " Цифра не существует " << endl;
        cout << "Введите цифру, которую планируете встретить в числе: ";
        cin >> digit;
    }
    while(N>0){
        if(N % 10 == digit){
            found = true;
        }
        N = N / 10;
    }
    if(found){
        cout << "Цифра " << digit << " входит в запись введенного числа" << endl;
    }
    else{
        cout << "Цифра " << digit << " не входит в запись введенного числа" << endl;
    }
    return 0;
}
