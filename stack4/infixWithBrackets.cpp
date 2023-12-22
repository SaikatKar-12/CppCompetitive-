#include<iostream>
#include<stack>
using namespace std;
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
    string s="(5+6)*4/8-1";
    cout<<s<<endl;
    stack<int> val;
    stack<char> op;
    for(int i=0;i<s.length();i++){
        int ascii=int(s[i]);
        if(ascii>=48 && ascii<=57){
            val.push(ascii-48);
        }else{
            if(op.size()==0 ) op.push(s[i]);
            else if(s[i]=='(') op.push(s[i]);
            else if(op.top()=='(') op.push(s[i]);
            else if(s[i]==')'){
                while(op.top()!='('){
                    int val2=val.top();
                    val.pop();
                    int val1=val.top();
                    val.pop();
                    char ch=op.top();
                    op.pop();
                    int ans=solve(val1,val2,ch);
                    val.push(ans);
                }
                op.pop();
            }
            else if(prio(s[i])>prio(op.top())) op.push(s[i]);
            else{
                while(op.size()>0 && prio(s[i])<=prio(op.top())){
                    int val2=val.top();
                    val.pop();
                    int val1=val.top();
                    val.pop();
                    char ch=op.top();
                    op.pop();
                    int ans=solve(val1,val2,ch);
                    val.push(ans);
                }
                op.push(s[i]);
            }
        }
    }
    while(op.size()>0){
        int val2=val.top();
        val.pop();
        int val1=val.top();
        val.pop();
        char ch=op.top();
        op.pop();
        int ans=solve(val1,val2,ch);
        val.push(ans);
    }
    cout<<val.top()<<endl;
    cout<<(5+6)*4/8-1;
    return 0;
}