#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define max 7
int visited[max]={0};
void dfs(int arr[][max],int v){
    int st[max];
    int top=-1;
    top++;
    st[top]=v;
    printf("%d ",st[top]);
    visited[st[top]]=1;
    while(top!=-1){
        int node=st[top];
        int i;
        for(i=0;i<max;i++){
            if(visited[i]==0 && arr[node][i]==1){
                top++;
                st[top]=i;
                printf("%d ",i);
                visited[i]=1;
                break;
            }

        }
        if(i==max) top--;
    }
}
void bfs(int arr[][max],int val){
    int qu[max];
    int f=-1;
    int r=-1;
    f++;
    r++;
    qu[f]=val;
    printf("%d ",qu[f]);
    visited[qu[f]]=1;
    while(f<=r){
        int node=qu[f];
        for(int i=0;i<max;i++){
            if(arr[node][i]==1 && visited[i]==0){
                printf("%d ",i);
                r++;
                qu[r]=i;
                visited[i]=1;
            }
        }
        f++;
    }
}
int main(){
    int a[7][7]={
        {0,1,0,1,0,0,1},
        {1,0,1,0,0,0,0},
        {0,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,1,0,1,0,1},
        {0,1,0,0,1,0,0}
    };
    dfs(a,0);
    printf("\n");
    for(int i=0;i<max;i++){
        visited[i]=0;
    }
    bfs(a,0);
    return 0;
}