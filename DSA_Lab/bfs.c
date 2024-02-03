#include<stdio.h>
#define max 20
int q[max-1];
int f=-1;
int b=-1;
void enque(int q[],int val){
    if(b==max-1) {
        printf("Stack is FULL!\n");
        return;
    }else if(f==-1){
        f=b=0;
        q[b]=q[f]=val;
        return;
    }
    else{
        b++;
        q[b]=val;
        return;
    }
}
int deque(int q[]){
    if(f==-1){
        printf("Stack is EMPTY!\n");
        return -1;
    }
    int val=q[f];
    f++;
    return val;
}
int peek(int q[]){
    if(b==-1){
        printf("Stack is EMPTY!\n");
        return -1;
    }
    return q[f];
}
void display(int q[]){
    if(b==-1){
        printf("Stack is EMPTY!\n");
        return ;
    }
    for(int i=f;i<=b;i++){
        printf("%d ",q[i]);
    }
    printf("\n");
    return;
}
int main(){
    int node;
    int visited[7]={0,0,0,0,0,0,0};
    int i=0;
    int a[7][7]={
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };
    printf("%d ",i);
    enque(q,i);
    visited[i]=1;
    while(b-f>=0){
        int node= deque(q);
        for(int j=0;j<7;j++){
            if(a[node][j]==1 && visited[j]==0){
                visited[j]=1;
                printf("%d ",j);
                enque(q,j);
            }
        }
    }
    return 0;
}