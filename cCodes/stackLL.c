#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct Node{
    int data;
    struct Node* next;
};

struct stack{
    struct Node* top;
};

struct stack* create_st(){
    struct stack* st=(struct stack*)malloc(sizeof(struct stack));
    st->top=NULL;
    return st;
}
void push(struct stack* st,int val){
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=val;
    ptr->next=NULL;
    if(st->top==NULL){
        st->top=ptr;
    }else{
        ptr->next=st->top;
        st->top=ptr;
    }
}
int pop(struct stack* st){
    if(st->top==NULL) return -1;
    else{
        struct Node* temp=st->top;
        int data=temp->data;
        st->top=temp->next;
        free(temp);
        return data;
    }
}

int main(){
    struct stack* st=create_st();
    push(st,1);
    push(st,2);
    push(st,3);
    push(st,4);
    printf("%d",pop(st));
    printf("%d",pop(st));
    printf("%d",pop(st));
    printf("%d",pop(st));
    printf("%d",pop(st));
    return 0;
}