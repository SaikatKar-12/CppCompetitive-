#include<stdio.h>
#include<malloc.h>
#include<ctype.h>
#include<string.h>
#define max 15
char st[max];
int top=-1;
void push(char st[],char val){
    if(top==max-1) {
        printf("Stack is FULL!\n");
        return;
    }else{
        top++;
        st[top]=val;
        return;
    }
}
char pop(char st[]){
    if(top==-1){
        printf("Stack is EMPTY!\n");
        return -1;
    }
    int val=st[top];
    top--;
    return val;
}
char peek(char st[]){
    if(top==-1){
        printf("Stack is EMPTY!\n");
        return -1;
    }
    return st[top];
}
void display(char st[]){
    if(top==-1){
        printf("Stack is EMPTY!\n");
        return ;
    }
    for(int i=0;i<=top;i++){
        printf("%c ",st[i]);
    }
    printf("\n");
    return;
}
int isEmpty(char st[]){
    if(top==-1) return 1;
    else return 0;
}
int parenthesisChecker(char *exp){
    int flag=1;
    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]=='('||exp[i]=='{'||exp[i]=='[' ){
            push(st,exp[i]);
        }else if(exp[i]==')'||exp[i]=='}'||exp[i]==']'){
            if(isEmpty(st)){
                flag=0;
                break;
            }
            int temp=peek(st);
            pop(st);
            if(temp=='(' && (exp[i]=='}'||exp[i]==']')){
                flag=0;
                break;
            }else if(temp=='{' && (exp[i]==')'||exp[i]==']')){
                flag=0;
                break;
            }else if(temp=='[' && (exp[i]==')'||exp[i]=='}')){
                flag=0;
                break;
            }
        }
    }
    if(!isEmpty(st)) flag=0;
    return flag;
}
int main(){
    char exp[]="({)}()";
    int ans=parenthesisChecker(exp);
    printf("%d",ans);
    return 0;
}