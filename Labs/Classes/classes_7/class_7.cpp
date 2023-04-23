#include "iostream"
#include "Vector.h"
#include "Time.h"
int main(){
    Vector<int> V1(5,0);
    cin>>V1;
    cout<<V1<<endl;
    Vector<int> V2(10,0);
    cout<<V2<<endl;
    V2=V1;
    cout<<V2<<endl;
    cout<<V1[2]<<endl;
    cout<<"size="<<V2()<<endl;
    V2=V1+10;
    cout<<V2<<endl;
    Time t1;
    cin>>t1;
    cout<<t1;
    int k;
    cout<<"k?";
    cin>>k;
    Time t2;
    t2=t1+k;
    cout<<t2;
    Time t3;
    cin>>t3;
    cout<<t3<<endl;
    Vector<Time> V4(5,t3);
    cin>>V4;
    cout<<V4;
    Vector<Time> V5(10,t3);
    V5=V4;
    cout<<V5<<endl;
    cout<<V4[2]<<endl;
    cout<<"size="<<V4()<<endl;
    V5=V4+t1;
    cout<<V5<<endl;
}
