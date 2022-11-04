#include <iostream>
#include <cmath>

using namespace std;

unsigned long long int new_fact(int N){
    unsigned long long int temp=1;
    for(int i=N;i<=2*N;i++){
        temp*=i;
    }
    return temp;
}
int main() {
    int N;
    cin >> N;
    unsigned long long int result=0;
    for(int i=1;i<=N;i++){
        result+=new_fact(i);
    }
    cout<<result;
    return 0;
}
