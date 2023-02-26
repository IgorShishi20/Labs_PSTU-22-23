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
        int tmp=arr[i];
        int curr = i;
        for(int j=i-1;j>=1 && arr[j]>tmp;j--){
           arr[j+1]=arr[j];
        }
        arr[curr]=tmp;
    }
    cout<<"Sorted array is "<<endl;
    for(int i=1;i<=N;i++){
        cout<<arr[i-1]<<" ";
    }
    cout<<endl;
    delete arr;
    return 0;
}