#include<stdio.h>
#define max 5
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
int main(){
    int opt;
    int a;
    int val;
    printf("*****Main Menu*****\n");
    printf("1.Push in queue\n");
    printf("2.Pop in queue\n");
    printf("3.Peek in queue\n");
    printf("4.Display queue\n");
    printf("5.Exit\n");
    while(opt!=5){
         printf("Enter your option:");
        scanf("%d",&opt);
        switch(opt){
            case 1:
                printf("Enter your Data:");
                scanf("%d",&val);
                push(q,val);
                break;
            case 2:
                a=pop(q);
                printf("%d is popped\n",a);
                break;
            case 3:
                a=peek(q);
                printf("%d is the top most element in stack\n",a);
                break;
            case 4:
                display(q);
                break;
            case 5:
                break;
        }
    }
    return 0;
}