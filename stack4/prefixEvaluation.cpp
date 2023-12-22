#include<iostream>
#include<stack>
using namespace std;
int solve(int val1,int val2,char ch){
    if(ch=='+') return val1+val2;
    else if(ch=='-') return val1-val2;
    else if(ch=='*') return val1*val2;
    else  return val1/val2;
}
int main(){
    string s="-/*+56481";
    cout<<s<<endl;
    stack<int> val;
    for(int i=s.length()-1;i>=0;i--){
        int ascii=int(s[i]);
        if(ascii>=48 && ascii<=57){
            val.push(ascii-48);
        }else{
            int val1=val.top();
            val.pop();
            int val2=val.top();
            val.pop();
            int ans=solve(val1,val2,s[i]);
            val.push(ans);
        }
    }
    cout<<val.top()<<endl;
    cout<<(5+6)*4/8-1;
    return 0;
}