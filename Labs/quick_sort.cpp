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

int Partition(int arr[],int begin,int end){
    int pivot = arr[begin];
    int num = 0;
    for(int i= begin+1;i<=end;i++){
        if(arr[i]<pivot) num++;
    }
    int pos = begin + num;
    swap(arr[pos],arr[begin]);
    int i = begin, j = end;
    while(i<pos && j>pos){
        while(arr[i]<pivot) i++;
        while(arr[j]>pivot) j--;
        if(i<pos && j>pos) swap(arr[i++],arr[j--]);
    }
    return pos;
}

void quick_sort (int arr[],int begin,int end)
{
    if(begin>=end) return;
    int p=Partition(arr,begin,end);
    quick_sort(arr,begin,p-1);
    quick_sort(arr,p+1,end);
}

int main( )
{
    int N=0;
    cout<<"Give me number of elements in an array"<<endl;
    cin>>N;
    int* arr = new int[N];
    FillArr(arr,N,0,1000);
    PrintArr(arr,N);
    quick_sort(arr,0,9);
    PrintArr(arr,N);
    return 0;
}