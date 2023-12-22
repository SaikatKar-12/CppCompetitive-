#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
struct stack{
    int top;
    int size;
    char* arr;
};
void push(struct stack* st,char val){
    if(st->top==st->size-1){
        printf("Overflow!\n");
        return ;
    }
    st->top++;
    st->arr[st->top]=val;
}
char pop(struct stack* st){
    if(st->top==-1){
        printf("Underflow\n");
        return -1;
    }
    char ch=st->arr[st->top];
    st->top--;
    return ch;
}
char peek(struct stack *st){
    if(st->top==-1){
        printf("Underflow\n");
        return -1;
    }
    char ch=st->arr[st->top];
    return ch;
}
int bracketCheck(char* exp){
    struct stack *st=(struct stack*)malloc(sizeof(struct stack));
    st->top=-1;
    st->size=20;
    st->arr=(char*)malloc(st->size*sizeof(char));
    int flag=1;
    for(int i=0;i<strlen(exp);i++){
        if(exp[i]=='('||exp[i]=='{'||exp[i]=='['){
            push(st,exp[i]);
        }else if(exp[i]==')'||exp[i]=='}'||exp[i]==']'){
            if(st->top==-1){
                flag=0;
                break;
            }
            char ch=pop(st);
            if(exp[i]==')' &&(ch=='{'||ch=='[')){
                flag=0;
                break;
            }else if(exp[i]=='}' &&(ch=='('||ch=='[')){
                flag=0;
                break;
            }else if(exp[i]==']' &&(ch=='('||ch=='{')){
                flag=0;
                break;
            }
        }
    }
    if(st->top!=-1) flag=0;
    return flag;
}
int main(){
    char exp[20];
    printf("enter your exp:");
    gets(exp);
    int flag=bracketCheck(exp);
    if(flag) printf("valid exp");
    else printf("Inavlid");
    return 0;
}