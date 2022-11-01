#include <iostream>

using namespace std;

int main() {
    int N;
    cin>>N;
    if(N<=0){
        cout<<"невозможно посчитать произведение чисел при n меньше или равном 0"<<endl;
    }
    unsigned long long int result=1;
    //if N>=21 the result will be wrong, so please - use another technique
    if(N>=21){
        cout<<"the result is bigger than maximum long long integer, computation will give wrong result"<<endl;
        //actually we could use arrays and implement something like long arithmetics, but hey, stay with us till the next patch
    }
    for(int i=1;i<N+1;i++){
        result*=i;
    }
    cout<<result<<endl;
    return 0;
}


