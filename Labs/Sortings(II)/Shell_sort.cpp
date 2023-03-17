#include "iostream"
using namespace std;

void ShellSort(int n, int mass[])
{
    int j,tmp;
    for(int step = n/2;step>0;step=step/2) {
        for (int i = step; i < n; i++) {
            tmp = mass[i];
            for (j = i; j >= step; j -= step) {
                if (tmp < mass[j - step]) mass[j] = mass[j - step];
                else break;
            }
            mass[j] = tmp;
        }
    }
}

int main(){
    int N;
    cout<<"Введите число элементов массива"<<endl;
    cin>>N;
    int* arr = new int[N];
    cout<<"Введите элементы массива"<<endl;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    ShellSort(N,arr);
    cout<<"Результат работы сортировки Шелла"<<endl;
    for(int i=0;i<N;i++){
        cout<<arr[i]<<' ';
    }
    delete[] arr;
}
