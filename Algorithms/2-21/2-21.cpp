#include <iostream>

using namespace std;
int main() {
    float a,prev;
    bool increasing=true;
    cout<<"Введите последовательность "<<endl;
    cin>>a;
    prev = a;
    if(a!=0){
        do{
            if(a<prev){
                increasing = false;
            }
            prev = a;
            cin>>a;
        }while(a!=0);
    }
    if(increasing){
        cout << "Последовательность упорядочена по возрастанию" << endl;
    }
    else{
        cout<<"Последовательность не упорядочена по возрастанию"<<endl;
    }
    return 0;
}
