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
int prio(char ch){
    if(ch=='*'||ch=='/') return 2;
    else return 1;
}
int isOperator(char ch){
    if(ch=='*'||ch=='/'||ch=='+'||ch=='-'||ch=='('||ch==')') return 1;
    else return 0;
}
char* infixTopostfix(char* infix){
    struct stack *st=(struct stack*)malloc(sizeof(struct stack));
    st->top=-1;
    st->size=10;
    st->arr=(char*)malloc(st->size*sizeof(char));
    char* postfix;
    postfix=(char*)malloc((strlen(infix)+1)*sizeof(char));
    int i=0;
    int j=0;
    while(infix[i]!='\0'){
        if(!isOperator(infix[i])){
            postfix[j]=infix[i];
            j++;
            i++;
        }else{
            if(st->top==-1){
                push(st,infix[i]);
                i++;
            }else if(infix[i]=='('||peek(st)=='('){
                push(st,infix[i]);
                i++;
            }else if(infix[i]==')'){
                while(st->top!=-1 && peek(st)!='('){
                    postfix[j]=pop(st);
                    j++;
                }
                if(st->top==-1){
                    printf("invalid");
                }
                pop(st);
                i++;
            }else if(prio(infix[i])>prio(peek(st))){
                push(st,infix[i]);
                i++;
            }else{
                postfix[j]=pop(st);
                j++;
            }
        }
    }
    while(st->top!=-1){
        postfix[j]=pop(st);
        j++;
    }
    postfix[j]='\0';
    return postfix;
}
int main(){
    char infix[20]="(a+b)*c/(d-e)";
    printf("%s",infixTopostfix(infix));
}