#include<stdio.h>
#include<malloc.h>
#include<string.h>
struct stack{
    int top;
    int size;
    char *arr;
};
void push(struct stack *st,char val){
    if(st->top==st->size-1) printf("Stack is full!");
    else{
        st->top++;
        st->arr[st->top]=val;
    }
}
char pop(struct stack *st){
    if(st->top==-1){
        printf("Stack is empty!");
        return -1;
    } 
    else{
        char val=st->arr[st->top];
        st->top--;
        return val;
    }
}
char peek(struct stack *st){
    if(st->top==-1){
        printf("Stack is empty!peek");
        return -1;
    }else{
        return st->arr[st->top];
    }
}
int BracketChecker(char *exp){
    struct stack *st=(struct stack*)malloc(sizeof(struct stack));
    st->size=10;
    st->top=-1;
    st->arr=(char*)malloc(st->size*sizeof(char));
    int flag=1;
    for(int i=0;i<strlen(exp);i++){
        if(exp[i]=='('||exp[i]=='{'||exp[i]=='['){
            push(st,exp[i]);
        }else if(exp[i]==')'||exp[i]=='}'||exp[i]==']'){
            if(st->top==-1){
                flag=0;
                break;
            }else if(exp[i]==')' && (st->arr[st->top]=='{'||st->arr[st->top]=='[')){
                flag=0;
                break;
            }
            else if(exp[i]=='}' && (st->arr[st->top]=='('||st->arr[st->top]=='[')){
                flag=0;
                break;
            }
            else if(exp[i]==']' && (st->arr[st->top]=='('||st->arr[st->top]=='{')){
                flag=0;
                break;
            }else{
                pop(st);
            }
        }
    }
    if(st->top>=0) flag=0;
    if(flag) return 1;
    else return 0;
}
int main(){
    char exp[20];
    printf("Enter your expression:");
    gets(exp);
    int flag=BracketChecker(exp);
    if(flag) printf("Valid expression");
    else printf("invalid expression");
    return 0;
}