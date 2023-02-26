#include "iostream"
#include <ctime>
#include "random"
using namespace std;

void FillArr(int mas[],int N,int min,int max){
    srand(time(NULL));
    for(int i=0;i<N;i++){
        mas[i]=min+rand()%(max-min+1);
    }
}

void PrintArr(int mas[],int N){
    for(int i=0;i<N;i++){
        cout<<mas[i]<<" ";
    }
    cout<<endl;
}

int max(int arr[],int N){
    int max = arr[0];
    for(int i = 1;i<N; i++){
        if(arr[i]>max) max = arr[i];
    }
    return max;
}

int min(int arr[],int N){
    int min = arr[0];
    for(int i=1;i<N;i++){
        if(arr[i]<min) min = arr[i];
    }
}

void counting_sort(int arr[],int n){
    int size = max(arr,n) - min(arr,n);
    int stored[size];
    for(int i=0;i<size;i++) stored[i]=0;
    for(int i=0;i<n;i++) stored[arr[i]]++;
    int count=0;
    int i=0;
    while(count<n){
        if(stored[i]==0) i++;
        else{
            arr[count]=i;
            stored[i]--;
            count++;
        }
    }
}

int main()
{
    int N=0;
    cout<<"Give me number of elements in an array"<<endl;
    cin>>N;
    int* arr = new int[N+1];
    FillArr(arr,N,0,1000);
    PrintArr(arr,N);
    counting_sort(arr,N);
    PrintArr(arr,N);
    return 0;
}