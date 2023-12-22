#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string str;
    cout<<"Enter string: ";
    getline(cin,str);
    int n=str.length();
    int num=0;
    int product=1;
    for(int i=n-1;i>=0;i--){
        num+=(str[i]-'0')*product;
        product*=10;
    }
    cout<<num;
    return 0;
}