#include<stdio.h>
#define max 5
int visited[max]={0};
void printGraph(int a[][max],int n){
    for(int i=0;i<n;i++){
        printf("%d:",i);
        for(int j=0;j<n;j++){
            if(a[i][j]==1){
                printf("%d ",j);
            }
        }
        printf("\n");
    }
}
void dfs(int arr[][max],int start){
    int st[max];
    int top=-1;
    top++;
    st[top]=start;
    printf("%d ",start);
    visited[start]=1;
    while(top>=0){
        int node=st[top];
        int i;
        for(i=0;i<max;i++){
            if(arr[node][i]==1 && visited[i]==0){
                printf("%d ",i);
                visited[i]=1;
                top++;
                st[top]=i;
                break;
            }
        }
        if(i==max){
            top--;
        }
    }
}
void bfs(int arr[][max],int start){
    int q[max];
    int f=0;
    int r=0;
    q[r]=start;
    printf("%d ",start);
    visited[start]=1;
    while(f<=r){
        int node=q[f];
        f++;
        for(int i=0;i<max;i++){
            if(arr[node][i]==1 && visited[i]==0){
                r++;
                q[r]=i;
                printf("%d ",i);
                visited[i]=1;
            }
        }
    }
}
int main(){
    int a[][5]={
        {0,0,1,1,0},
        {0,0,1,0,1},
        {1,1,0,1,0},
        {0,0,1,0,1},
        {0,1,0,1,0}
    };
    //printGraph(a,5);
    // dfs(a,0);
    // printf("\n");
    bfs(a,1);
}