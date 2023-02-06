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
    for(int i=2;i<=N;i++){
        int tmp = arr[i-1];
        int j;
        for(j=i-1;j>=1 && arr[j-1]>tmp;j--){
            arr[j]=arr[j-1];
            arr[j-1]=-INT32_MAX;
        }
        arr[j]=tmp;
    }
    cout<<"Sorted array is "<<endl;
    for(int i=1;i<=N;i++){
        cout<<arr[i-1]<<" ";
    }
    cout<<endl;
    delete arr;
    return 0;
}
