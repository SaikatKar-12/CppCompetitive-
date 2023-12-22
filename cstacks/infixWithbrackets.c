#include<stdio.h>
#include<string.h>
#define max 15
int st[max];
char op[max];
int top1=-1;
int top2=-1;
void push1(int st[],int val){
    if(top1==max-1) {
        printf("Stack is FULL!\n");
        return;
    }else{
        top1++;
        st[top1]=val;
        return;
    }
}
void push2(char st[],char val){
    if(top2==max-1) {
        printf("Stack is FULL!\n");
        return;
    }else{
        top2++;
        st[top2]=val;
        return;
    }
}
void pop1(int st[]){
    if(top1==-1){
        printf("Stack is EMPTY!\n");
        return ;
    }
    top1--;
    return;
}
void pop2(char st[]){
    if(top2==-1){
        printf("Stack is EMPTY!\n");
        return ;
    }
    top2--;
     return;
}
int peek1(int st[]){
    if(top1==-1){
        printf("Stack is EMPTY!\n");
        return -1;
    }
    return st[top1];
}
char peek2(char st[]){
    if(top2==-1){
        printf("Stack is EMPTY!\n");
        return -1;
    }
    return st[top2];
}
void display(int st[]){
    if(top1==-1){
        printf("Stack is EMPTY!\n");
        return ;
    }
    for(int i=0;i<=top1;i++){
        printf("%d ",st[i]);
    }
    printf("\n");
    return;
}
// void reverse(int arr[],int n){
//     //int n=sizeof(arr)/sizeof(arr[0]);
//     for(int i=0;i<n;i++){
//         int val=arr[i];
//         push(st,val);
//     }
//     for(int i=0;i<n;i++){
//         int val=peek(st);
//         arr[i]=val;
//         pop(st);
//     }
// }
int size(char op[]){
    int n=strlen(op);
    return n;
}
int prio(char a){
    if( a=='+'|| a=='-') return 1;
    else return 2;
}
int solve(int val1,int val2,char ch){
    if(ch=='+') return val1+val2;
    else if(ch=='-') return val1-val2;
    else if(ch=='*') return val1*val2;
    else  return val1/val2;
}
int main(){
    // int arr[]={1,2,3,4,5,6,7};
    // int n=sizeof(arr)/sizeof(arr[0]);
    // for(int i=0;i<n;i++){
    //     printf("%d ",arr[i]);
    // }
    // printf("\n");
    // reverse(arr,n);
    // for(int i=0;i<n;i++){
    //     printf("%d ",arr[i]);
    // }
    // printf("\n");
    char s[100]="(5+6)*4/8-1";
    int n=strlen(s);
    for(int i=0;i<n;i++){
            // printf("%d ",top1);
            // printf("%d ",top2);
            // printf("%d ",peek1(st));
            // printf("%d",strlen(op));
            // printf("\n");
        int ascii= (int)(s[i]);
        if(ascii>=48 && ascii<=57){
            push1(st,ascii-48);
        }else{
            if(size(op)==0 ) push2(op,s[i]);
            else if(s[i]=='(') push2(op,s[i]);
            else if(peek2(op)=='(') push2(op,s[i]);
            else if(s[i]==')'){
                while(peek2(op)!='('){
                    int val2=peek1(st);
                    pop1(st);
                    int val1=peek1(st);
                    pop1(st);
                    char ch=peek2(op);
                    pop2(op);
                    int ans=solve(val1,val2,ch);
                    push1(st,ans);
                }
                pop2(op);
            }
            else if(prio(s[i])>prio(peek2(op))) push2(op,s[i]);
            else{
                while(top2>=0 && prio(s[i])<=prio(peek2(op))){
                    int val2=peek1(st);
                    pop1(st);
                    int val1=peek1(st);
                    pop1(st);
                    char ch=peek2(op);
                    pop2(op);
                    int ans=solve(val1,val2,ch);
                    push1(st,ans);
                }
                push2(op,s[i]);
            }
        }
    }
    while(top2>=0){
        int val2=peek1(st);
        pop1(st);
        int val1=peek1(st);
        pop1(st);
        char ch=peek2(op);
        pop2(op);
        int ans=solve(val1,val2,ch);
        push1(st,ans);
    }
    printf("Answer is: %d  \n",peek1(st));
    int num=(5+6)*4/8-1;
    printf("%d",num);
    return 0;
}