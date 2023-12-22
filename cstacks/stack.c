#include<stdio.h>
#include<string.h>
#include<malloc.h>
struct stack{
    int size;
    int top;
    char *arr;
};
void push(struct stack *st,char val ){
    if(st->top==st->size-1) printf("Stack is full!");
    else{
        st->top++;
        st->arr[st->top]=val;
    }
}
char pop(struct stack *st){
    if(st->top==-1){
        printf("Stack is empty!pop");
        return -1;
    } 
    else{
        char val=st->arr[st->top];
        st->top--;
        return val;
    }
}
void display(struct stack *st){
    for(int i=0;i<=st->top;i++){
        printf("%c ",st->arr[i]);
    }
    printf("\n");
}
char peek(struct stack *st){
    if(st->top==-1){
        printf("Stack is empty!peek");
        return -1;
    }else{
        return st->arr[st->top];
    }
}
int isOperator(char ch){
    if(ch=='+' || ch=='-' ||ch=='*' || ch=='/'||ch=='('||ch==')') 
        return 1;
    else
        return 0;
}
int prio(char ch){
    if(ch=='*' || ch=='/') return 2;
    else return 1;
}
char* infixToPostfix(char* infix){
    struct stack *st = (struct stack *) malloc(sizeof(struct stack));
    st->size=10;
    st->top=-1;
    st->arr=(char*)malloc(st->size*sizeof(char));
    char * postfix = (char *) malloc((strlen(infix)+1) * sizeof(char));
    int i=0;
    int j=0;
    while(infix[i]!='\0'){
        if(!isOperator(infix[i])){
            postfix[j]=infix[i];
            i++;
            j++;
        }else if(infix[i]=='('){
            push(st,infix[i]);
            i++;
        }else if(infix[i]==')'){
            while(st->top!=-1 && peek(st)!='('){
                postfix[j]=pop(st);
                j++;
            }
            if(st->top==-1){
                printf("Incorrect Expression\n");
                exit(1);
            }
            pop(st);
            i++;
        }
        else{
            if(st->top==-1|| peek(st) == '('  || prio(infix[i])>prio(peek(st))){
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
    char infix[20];
    printf("Enter your infix expression: ");
    gets(infix);
    printf("Postfix is:%s",infixToPostfix(infix));

}