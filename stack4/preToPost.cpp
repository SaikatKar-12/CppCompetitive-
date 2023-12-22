#include<iostream>
#include<stack>
using namespace std;
string solve(string val1,string val2,char ch){
    string s="";
    s+=val1;
    s+=val2;
    s.push_back(ch);
    return s;
}
int main(){
    string s="-/*+56481";
    cout<<s<<endl;
    stack<string> val;
    for(int i=s.length()-1;i>=0;i--){
        int ascii=int(s[i]);
        if(ascii>=48 && ascii<=57){
            val.push(to_string(ascii-48));
        }else{
            string val1=val.top();
            val.pop();
            string val2=val.top();
            val.pop();
            string ans=solve(val1,val2,s[i]);
            val.push(ans);
        }
    }
    cout<<val.top()<<endl;
    cout<<(5+6)*4/8-1;
    return 0;
}