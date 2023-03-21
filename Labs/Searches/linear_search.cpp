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


int linear_search(int arr[],int N,int find){
    for(int i=0;i<N;i++){
        if(arr[i]==find){
            return i;
        }
    }
    return -1;
}

int main(){
    int N;
    cout<<"¬ведите размер массива"<<endl;
    cin>>N;
    int* arr = new int[N];
    FillArr(arr,N,0,1000);
    linear_search(arr,N,245);
    PrintArr(arr,N);
    return 0;
}
