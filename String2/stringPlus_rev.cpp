#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;

int main(){
    string str;
    cout<<"Enter string: ";
    getline(cin,str);
    string rev=str;
    reverse(rev.begin(),rev.end());
    str=str+rev;
    cout<<str;
    return 0;
}