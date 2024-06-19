#include<stdio.h>
#define n 8
char grid[n][n];
int count=0;
int canPlaceQueen(int row,int col){
    for(int i=row-1;i>=0;i--){
        if(grid[i][col]=='Q') return 0;
    }
    for(int i=row-1,j=col-1;i>=0,j>=0;i--,j--){
        if(grid[i][j]=='Q') return 0;
    }
    for(int i=row-1,j=col+1;i>=0,j<n;i--,j++){
        if(grid[i][j]=='Q') return 0;
    }
    return 1;
}
void f(int row){
    if(row==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                printf("%c",grid[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        count++;
    }
    for(int col=0;col<n;col++){
        if(canPlaceQueen(row,col)){
            grid[row][col]='Q';
            f(row+1);
            grid[row][col]='.';
        }
    }
}
void nqueen(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            grid[i][j]='.';
        }
    }
    f(0);
} 
int main(){
    nqueen();
    printf("%d",count);
}