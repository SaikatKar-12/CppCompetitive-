#include<iostream>
#include<string>
using namespace std;

int main(){
    string str;
    cout<<"Enter string: ";
    getline(cin,str);
    int n=str.length();
    bool flag=true;
    for(int i=0;i<=n/2;i++){
        if(str[i]!=str[n-i-1]){
            flag=false;
            break;
        }
    }
    if(flag==true) cout<<"It is a palindrome";
    else cout<<"Not a palindrome";
    return 0;
}