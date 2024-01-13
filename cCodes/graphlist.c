#include <stdio.h>
#include <stdlib.h>
#define max 7
int q[max-1];
int f=-1;
int b=-1;
void push(int q[],int val){
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
int pop(int q[]){
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
int isEmpty(int q[]){
    if(b==-1) return 1;
    else return 0;
}
int main(){
    int a[max][max];
    for(int i=0;i<max;i++){
        for(int j=0;j<max;j++){
            int n;
            scanf("%d",&n);
            a[i][j]=n;
        }
    }
    int i=0;
    int visited[max]={0};
    visited[i]=1;
    push(q,i);
    printf("%d ",i);
    while(!isEmpty(q)){
        int node=pop(q);
        for( int j=0;j<max;j++){
            if(a[node][j]!=0 && visited[j]==0){
                visited[j]=1;
                push(q,j);
                printf("%d ",j);
            }
        }
    }
    return 0;
}