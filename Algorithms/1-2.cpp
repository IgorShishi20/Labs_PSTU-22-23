#include <iostream>

using namespace std;

int main() {
    float numerator,denominator;
    cin>>numerator>>denominator;
    if(denominator==0){
        cout<<"обнаружено деление на 0"<<endl;
    }
    else{
        cout<<numerator/denominator<<endl;
    }
    return 0;
}

