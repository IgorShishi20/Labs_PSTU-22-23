#include <iostream>
using namespace std;
int ops = 0;
void Hanoi_tower(int n, int from_rod, int to_rod, int aux_rod){
    if(n == 0){
        return;
    }
    Hanoi_tower(n - 1, from_rod, aux_rod, to_rod);
    cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;
    ops++;
    Hanoi_tower(n - 1, aux_rod, to_rod, from_rod);
}

int main(){
    int N;
    cout<<"Enter the number of rings on the first rod"<<endl;
    cin>>N;
    Hanoi_tower(N, 1, 2, 3);
    cout<<"There are "<<ops<<" operations of moving ring from one rod to another"<<endl;
    return 0;
}
