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
int prio(char a){
    if(a=='+'|| a=='-') return 1;
    else if(a=='*'||a=='/') return 2;
}
char* InfixToPost(char* infix){
    char * post = (char *) malloc((strlen(infix)+1) * sizeof(char));
    int i=0;
    int j=0;
    
    while(infix[i]!='\0'){
        if(isalnum(infix[i])){
            post[j]=infix[i];
            i++;
            j++;
        }else if(infix[i]=='(' ){
            push(st,infix[i]);
            i++;
        }else if(infix[i]==')'){
            while(peek(st)!='('){
                post[j]=peek(st);
                pop(st);
                j++;
            }
            pop(st);
            i++;
        }
        else if(isEmpty(st)){
            push(st,infix[i]);
            i++;
        }else if(peek(st)=='('){
            push(st,infix[i]);
            i++;
        }
        else if(prio(infix[i])>prio(peek(st))){
            push(st,infix[i]);
            i++;
        }else{
            while(prio(infix[i])<=prio(peek(st) )){
                post[j]=peek(st);
                pop(st);
                j++;
                if(isEmpty(st)) break;
            }
            //printf("hello");
        }
    }
    while(!isEmpty(st)){
                post[j]=peek(st);
                pop(st);
                j++;
            }
    post[j] = '\0';
    return post;
}
int main(){
    char *infix="(x+y)*c";
    printf("%s",InfixToPost(infix));

    return 0;
}