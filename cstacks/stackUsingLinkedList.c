#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>
struct stack
{
    int data;
    struct stack *next;
};
struct stack *top = NULL;
struct stack *push(struct stack *top,int val)
{
    struct stack* ptr=(struct stack*)malloc(sizeof(struct stack));
    ptr->data=val;
    if(top==NULL){
        ptr->next=NULL;
        top=ptr;
    }else{
        ptr->next=top;
        top=ptr;
    }
    return top;
}

struct stack* display(struct stack *top){
    struct stack *ptr;
    ptr=top;
    if(top==NULL){
        printf("Stack is empty!");
        return NULL;
    }else{
        while(ptr){
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
        printf("\n");
    }
    return top;
}

struct stack *pop(struct stack* top){
    if(top==NULL){
        printf("Stack is empty!");
        return NULL;
    }else{
        struct stack *ptr;
        ptr=top;
        top=top->next;
        printf("the value %d is deleted",ptr->data);
        free(ptr);
    }
    return top;
}
int peek(struct stack* top){
    if(top==NULL){
        printf("Stack is empty!");
        return -1;
    }else{
        return top->data;
    }
    return -1;
}

int main()
{
    top=push(top,1);
    top=push(top,2);
    top=push(top,3);
    top=push(top,4);
    top=push(top,5);
    top=display(top);
    printf("%d\n",peek(top));
    top=pop(top);
    top=pop(top);
    top=display(top);
    printf("%d\n",peek(top));
    return 0;
}