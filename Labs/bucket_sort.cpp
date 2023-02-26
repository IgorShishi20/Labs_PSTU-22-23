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

int max_degree(int arr[],int N){
    int max = arr[0], deg=0;
    for(int i = 1;i<N; i++){
        if(arr[i]>max) max = arr[i];
    }
    while(max>0){
        deg++;
        max/=10;
    }
    return deg;
}

void bucket_sort(int arr[],int n){
    int buckets[10][n];
    int counter[10];
    int k,l,d=1;
    int max = max_degree(arr,n);
    for(int m=0;m<max;m++){
        for(int i=0;i<n;i++) counter[i]=0;
        for(int i=0;i<n;i++){
            k=(arr[i]/d)%n;
            buckets[k][counter[k]]=arr[i];
            counter[k]++;
        }
        l=0;
        for(int i=0;i<10;i++){
            for(k=0;k<counter[i];k++){
                arr[l]=buckets[i][k];
                l++;
            }
        }
        d*=10;
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
    bucket_sort(arr,10);
    PrintArr(arr,N);
    return 0;
}