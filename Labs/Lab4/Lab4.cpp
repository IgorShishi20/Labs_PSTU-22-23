#include <iostream>
#include <cstdlib>
#include <ctime>
#include "random"
using namespace std;

void FillArr(int mas[10],int min,int max){
    srand(time(NULL));
    for(int i=0;i<10;i++){
        mas[i]=min+rand()%(max-min+1);
    }
}
void PrintArr(int mas[10]){
    for(int i=0;i<10;i++){
        cout<<mas[i]<<" ";
    }
    cout<<endl;
}
void DeleteEl(int n, int mas[10]){
    if(n>10){
        cout<<"Impossible"<<endl;
    }
    else{
        for(int i=n;i<10;i++){
            mas[i]=mas[i+1];
        }
        mas[9]=0;
    }
}
void AddEl(int mas[10]){
    for(int i=0;i<10;i++){
        if(!(mas[i]%2)){
            if(i==9 || !i){
                if(!i){
                    continue;
                }
                else{
                    cout<<"Not possible to put"<<endl;
                }
            }
            else{
                for(int j=9;j>i;j--){
                    mas[j+1]=mas[j];
                }
                mas[i+1]=mas[i-1]+2;
                return;
            }
        }
    }
}
int main(){
    int mas[10];
    for(int i=0;i<10;i++){
        mas[i]=0;
    }
    FillArr(mas,0,10000);
    PrintArr(mas);
    DeleteEl(5,mas);
    AddEl(mas);
    PrintArr(mas);
    return 0;
}
