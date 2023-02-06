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
        int min = i;
        for(int j=i+1;j<=N;j++){
            if(arr[j-1]<arr[min-1]){
                min = j;
            }
        }
        swap(arr[min-1],arr[i-1]);
    }
    cout<<"Sorted array is "<<endl;
    for(int i=1;i<=N;i++){
        cout<<arr[i-1]<<" ";
    }
    cout<<endl;
    delete arr;
    return 0;
    
}
