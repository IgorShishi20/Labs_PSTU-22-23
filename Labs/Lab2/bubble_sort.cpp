#include <iostream>
using namespace std;
int main(){
    int N;
    cout<<"what size our array should have?"<<endl;
    cin>>N;
    int *arr;
    arr = new int[N];
    cout<<"Give us an array to sort"<<endl;
    for(int i=1;i<=N;i++){
        cin>>arr[i-1];
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N-i;j++){
            if(arr[j-1]>arr[j]){
                swap(arr[j-1],arr[j]);
            }
        }
    }
    cout<<"Sorted array is "<<endl;
    for(int i=1;i<=N;i++){
        cout<<arr[i-1]<<" ";
    }
    cout<<endl;
    delete arr;
    return 0;
}
