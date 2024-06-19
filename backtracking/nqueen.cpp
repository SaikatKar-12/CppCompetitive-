#include<iostream>
#include<vector>
using namespace std;

vector<vector<char>> grid;
bool canPlaceQueen(int row,int col,int n){
    for(int i=row-1;i>=0;i--){
        if(grid[i][col]=='Q') return false;
    }
    for(int i=row-1,j=col-1;i>=0,j>=0;i--,j--){
        if(grid[i][j]=='Q') return false;
    }
    for(int i=row-1,j=col+1;i>=0,j<n;i--,j++){
        if(grid[i][j]=='Q') return false;
    }
    return true;
}
void f(int row,int n){
    if(row==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<grid[i][j];
            }
            cout<<endl;
        }
        return;
    }
    for(int col=0;col<n;col++){
        if(canPlaceQueen(row,col,n)){
            grid[row][col]='Q';
            f(row+1,n);
            grid[row][col]='.';
        }
    }
}
void nqueen(int n){
    grid.clear();
    grid.resize(n+1,vector<char>(n,'.'));
    f(0,n);
}
int main(){
    nqueen(4);
    return 0;
}