#include<stdio.h>
#include<malloc.h>
#include<ctype.h>
#include<string.h>
#define max 15
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
int isEmpty(int st[]){
    if(top==-1) return 1;
    else return 0;
}
int prio(char a){
    if(a=='+'|| a=='-') return 1;
    else if(a=='*'||a=='/') return 2;
}
int solve(int a,int b,char c){
    if(c=='+') return a+b;
    else if(c=='-') return a-b;
    else if(c=='*') return a*b;
    else return a/b;
}
int PostfixEval(char* infix){
    int i=0;
    
    while(infix[i]!='\0'){
       if(isalnum(infix[i])){
        int a=infix[i]-'0';
        push(st,a);
        i++;
       }else{
            int val2=peek(st);
            pop(st);
            int val1=peek(st);
            pop(st);
            int res=solve(val1,val2,infix[i]);
            push(st,res);
            i++;
       }
        }
        int ans=peek(st);
        return ans;
    }
    
    

int main(){
    char *infix="23+";
    printf("%d",PostfixEval(infix));

    return 0;
}