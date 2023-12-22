#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string str;
    cout<<"Enter string: ";
    getline(cin,str);
    int n=str.length();
    reverse(str.begin()+n/2,str.end());
    cout<<str;
    return 0;
}