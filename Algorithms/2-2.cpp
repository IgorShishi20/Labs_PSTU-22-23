#include <iostream>

using namespace std;

int main() {
    int N;
    cin>>N;
    if(N<=0){
        cout<<"невозможно посчитать произведение чисел при n меньше или равном 0"<<endl;
    }
    unsigned long long int result=1;
    for(int i=1;i<N+1;i++){
        result*=i;
    }
    cout<<result<<endl;
    return 0;
}


