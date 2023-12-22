#include<stdio.h>
#define max 3
int st[max];
int top=-1;
void push(int st[],int val){
    if(top==max-1) {
        printf("Stack is FULL!\n");
        return;
    }else{
        top++;
        st[top]=val;
        return;
    }
}
int pop(int st[]){
    if(top==-1){
        printf("Stack is EMPTY!\n");
        return -1;
    }
    int val=st[top];
    top--;
    return val;
}
int peek(int st[]){
    if(top==-1){
        printf("Stack is EMPTY!\n");
        return -1;
    }
    return st[top];
}
void display(int st[]){
    if(top==-1){
        printf("Stack is EMPTY!\n");
        return ;
    }
    for(int i=0;i<=top;i++){
        printf("%d ",st[i]);
    }
    printf("\n");
    return;
}
int main(){
    int opt;
    int a;
    int val;
    printf("*****Main Menu*****\n");
    printf("1.Push in stack\n");
    printf("2.Pop in stack\n");
    printf("3.Peek in stack\n");
    printf("4.Display stack\n");
    printf("5.Exit\n");
    while(opt!=5){
         printf("Enter your option:");
        scanf("%d",&opt);
        switch(opt){
            case 1:
                printf("Enter your Data:");
                scanf("%d",&val);
                push(st,val);
                break;
            case 2:
                a=pop(st);
                printf("%d is popped\n",a);
                break;
            case 3:
                a=peek(st);
                printf("%d is the top most element in stack\n",a);
                break;
            case 4:
                display(st);
                break;
            case 5:
                break;
        }
    }
    return 0;
}