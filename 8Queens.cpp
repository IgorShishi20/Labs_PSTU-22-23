#include <iostream>
using namespace std;
int board[8][8];

bool isPossible(int n, int row, int col){
    //check vertical
    for(int i=row-1;i>=0;i--){
        if(board[i][col]==1){
            return false;
        }
    }
    //check secondary diagonal
    for(int i=row-1,j=col-1;i >= 0 && j >= 0;i--,j--){
        if(board[i][j] == 1){
            return false;
        }
    }
    //check main diagonal
    for(int i=row-1,j=col+1;i >= 0 && j<n;i--,j++){
        if(board[i][j] == 1){
            return false;
        }
    }
    return true;
}
void nQueenHelper(int n, int row){
    if (row==n){
        for(int i=0;i<n;i++){
            for(int j=0; j<n; j++){
                if(board[i][j]==1){
                    cout<<"Q"<<" ";
                }
                else{
                    cout<<"."<<" ";
                }
            }
            cout<<endl;
        }
        cout << endl;
        return;
    }
    for(int j = 0; j < n; j++){
        if(isPossible(n, row,j)){
            board[row][j] = 1;
            nQueenHelper(n,row + 1);
        }
        board[row][j] = 0;
    }
    return;
}

int main()
{
    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++){
            board[i-1][j-1]=0;
        }
    }
    nQueenHelper(8, 0);
    return 0;
}