#include<iostream>
using namespace std;
void skipChar(string ans,string original,int idx){
    if(idx==original.length()) {
        cout<<ans;
        return;
    }
    char ch=original[idx];
    if(ch=='a') return skipChar(ans,original,idx+1);
    else return skipChar(ans+ch,original,idx+1);
}
int main(){
    skipChar("","saikat kar",0);
    return 0;
}