#include "iostream"
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

int interpolated_search(int arr[],int N,int find){
    int middle, begin=0,end=N-1;
    while(arr[begin]<find && arr[end]>find){
        if(arr[begin]==arr[end]) break;
        middle = begin + (find - arr[begin]) * (end - begin ) / (arr[end] - arr[begin]);
        if(arr[begin]<find) begin = middle +1;
        else{
            if(arr[end]>find) end = middle -1;
            else return middle;
        }
    }
    if(arr[begin]==find) return begin;
    if(arr[end]==find) return end;
    return -1;
}

int main(){
    int N;
    cout<<"Введите размер массива"<<endl;
    cin>>N;
    int* arr = new int[N];
    FillArr(arr,N,0,1000);
    quick_sort(arr,0,N);
    interpolated_search(arr,N, 384);
    PrintArr(arr,N);
    return 0;
}
