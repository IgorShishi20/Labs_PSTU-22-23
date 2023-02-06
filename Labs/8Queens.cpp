#include <iostream>
using namespace std;
int board[8][8];

bool isPossible(int n, int row, int col){
    //check vertical
    for(int i=row;i>=1;i--){
        if(board[i-1][col]==1){
            return false;
        }
    }
    //check secondary diagonal
    for(int i=row,j=col;i >= 1 && j >= 1;i--,j--){
        if(board[i-1][j-1] == 1){
            return false;
        }
    }
    //check main diagonal
    for(int i=row,j=col+1;i >= 1 && j<n;i--,j++){
        if(board[i-1][j] == 1){
            return false;
        }
    }
    return true;
}
void nQueenHelper(int n, int row){
    if (row==n){
        for(int i=1;i<=n;i++){
            for(int j=1; j<=n; j++){
                if(board[i-1][j-1]==1){
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
    for(int j = 1; j <= n; j++){
        if(isPossible(n, row,j-1)){
            board[row][j-1] = 1;
            nQueenHelper(n,row + 1);
        }
        board[row][j-1] = 0;
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
