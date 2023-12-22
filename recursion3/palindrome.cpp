#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
bool palindrome(string s,int i,int j){
    if(i>j) return true;
    if(s[i]!=s[j]) return false;
    else palindrome(s,i+1,j-1);
}
int main(){
    string str="mom";
    cout<<palindrome(str,0,str.length()-1);
    return 0;
}