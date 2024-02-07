#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int prio(char ch){
    if(ch=='*'||ch=='/') return 2;
    else if(ch=='+'|| ch=='-') return 1;
    else return 0;
}

char* InfixToPost(char *infix){
    char* post=(char *)malloc((strlen(infix)+1)*sizeof(char));
    int i=0;
    int j=0;
    int top=-1;
    char st[100];
    while(infix[i]!='\0'){
        if(isalnum(infix[i])){
            post[j]=infix[i];
            i++;
            j++;
        }else {
            if(top==-1 || infix[i]=='('){
                top++;
                st[top]=infix[i];
                i++;
            }else if(st[top]=='('){
                top++;
                st[top]=infix[i];
                i++;
            }else if(infix[i]==')'){
                while(top!=-1 && st[top]!='('){
                    post[j]=st[top];
                    top--;
                    j++;
                }
                top--;
                i++;
            }
            else if( prio(infix[i]) > prio(st[top]) ){
                top++;
                st[top]=infix[i];
                i++;
            }else{
                while(top!=-1 && prio(infix[i])<=prio(st[top])){
                    post[j]=st[top];
                    top--;
                    j++;
                }
            }
        }
    }
    while(top!=-1){
        post[j]=st[top];
        top--;
        j++;
    }
    post[j]='\0';
    return post;
}

int main(){
    char *infix="a+b*c-d/e";
    printf("%s",InfixToPost(infix));
}