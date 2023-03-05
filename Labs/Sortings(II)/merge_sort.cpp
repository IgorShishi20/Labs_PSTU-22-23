#include <iostream>
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

void merge(int arr[],int begin,int mid,int end){
    int left = mid-begin+1;
    int right = end-mid;
    int* lArr = new int[left];
    int* rArr = new int[right];
    for(int i=0;i<left;i++){
        lArr[i]=arr[begin+i];
    }
    for(int i=0;i<right;i++){
        rArr[i]=arr[mid+i+1];
    }
    int left_ind=0;
    int merge_ind=begin;
    int right_ind=0;
    while(left_ind<left && right_ind<right){
        if(lArr[left_ind]<=rArr[right_ind]){
            arr[merge_ind]=lArr[left_ind];
            left_ind++;
        }
        else{
            arr[merge_ind]=rArr[right_ind];
            right_ind++;
        }
        merge_ind++;
    }
    while(left_ind<left){
        arr[merge_ind]=lArr[left_ind];
        merge_ind++;
        left_ind++;
    }
    while(right_ind<right){
        arr[merge_ind]=rArr[right_ind];
        right_ind++;
        merge_ind++;
    }
    delete[] lArr;
    delete[] rArr;
}

void merge_sort (int arr[],int begin,int end)
{
    if(begin>=end){return;}
    int mid = begin + (end-begin)/2;
    merge_sort(arr,begin,mid);
    merge_sort(arr,mid+1,end);
    merge(arr,begin,mid,end);
}



int main( )
{
    int N=0;
    cout<<"Give me number of elements in an array"<<endl;
    cin>>N;
    int* arr = new int[N];
    FillArr(arr,N,0,1000);
    PrintArr(arr,N);
    merge_sort(arr,0,9);
    PrintArr(arr,N);
    delete[] arr;
    return 0;
}
