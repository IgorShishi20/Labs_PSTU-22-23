#include <iostream>

using namespace std;

int main() {
    int N;
    cin>>N;
    if(N<=0){
        cout<<"невозможно посчитать сумму чисел при n меньше или равном 0"<<endl;
    }
    unsigned int result=0;
    for(int i=0;i<N;i++){
        result+=i;
    }
    cout<<result<<endl;
    return 0;
}
