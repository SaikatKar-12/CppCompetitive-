#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#define max 5
int visited[max]={0};
void dfs(int arr[][max],int start){
    int st[max];
    int top=-1;
    top++;
    st[top]=start;
    printf("%d ",start);
    visited[start]=1;
    while(top>-1){
        start=st[top];
        int i=0;
        for(i=0;i<max;i++){
            if(arr[start][i]==1 && visited[i]==0){
                visited[i]=1;
                printf("%d ",i);
                top++;
                st[top]=i;
                break;
            }
        }
        if(i==max) top--;
    }
}

int main(){
    int a[max][max]={
        {0,1,1,1,0},
        {1,0,1,0,0},
        {1,1,0,1,1},
        {1,0,1,0,1},
        {0,0,1,1,0},
    };
    dfs(a,0);
    return 0;
}